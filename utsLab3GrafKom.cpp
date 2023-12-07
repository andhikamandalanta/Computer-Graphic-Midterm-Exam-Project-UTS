#include <GL/glut.h>
#include <cmath>

double carX = -0.25;
double carY = 0.42; 
double carX2 = -0.25;
double carY2 = 0.20;

float wheelY = 0.05;
float mouseX = 0.0;
float mouseY = 0.0;

double planeX = 0.8;
double planeY = 0.8;
double planeSpeed = 0.01;


// Fungsi callback mouse
void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        carX -= 0.05;
    }
    else if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
        carX += 0.05;
    }

    glutPostRedisplay(); // Meminta agar tampilan diperbarui setelah perubahan
}

void keyboard(unsigned char key, int x, int y) {
    float step = 0.01;

    switch (key) {
    case 'a':
    case 'A':
        carX2 -= step;
        break;
    case 'd':
    case 'D':
        carX2 += step;
        break;
    case 'w':
    case 'W':
        carY2 += step;
        break;
    case 's':
    case 'S':
        carY2 -= step;
        break;
    }

    glutPostRedisplay();
}


void specialKey(int key, int x, int y) {
    switch (key) {
    case GLUT_KEY_RIGHT:
        planeX += planeSpeed;
        break;
    case GLUT_KEY_LEFT:
        planeX -= planeSpeed;
        break;
    case GLUT_KEY_UP:
        planeY += planeSpeed;
        break;
    case GLUT_KEY_DOWN:
        planeY -= planeSpeed;
        break;
    }

    glutPostRedisplay(); 
}

void drawCar() {
    // Badan mobil
    glColor3f(0.8, 0.2, 0.2);  // Warna merah untuk badan mobil
    glBegin(GL_POLYGON);
    glVertex2f(carX + 0.45, carY + 0.05);
    glVertex2f(carX + 0.55, carY + 0.05);
    glVertex2f(carX + 0.55, carY + 0.1);
    glVertex2f(carX + 0.45, carY + 0.1);
    glEnd();

    // Atap mobil
    glColor3f(0.0, 0.0, 1.0);  // Warna biru untuk atap mobil
    glBegin(GL_POLYGON);
    glVertex2f(carX + 0.47, carY + 0.1);
    glVertex2f(carX + 0.53, carY + 0.1);
    glVertex2f(carX + 0.52, carY + 0.13);
    glVertex2f(carX + 0.48, carY + 0.13);
    glEnd();

    // Roda kiri depan
    glColor3f(0.0, 0.0, 0.0);  // Warna hitam untuk roda
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++) {
        float angle = i * 3.14159 / 180.0;
        float x = carX + 0.475 + 0.01 * cos(angle);
        float y = carY + wheelY + 0.01 * sin(angle);
        glVertex2f(x, y);
    }
    glEnd();

    // Roda kanan depan
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++) {
        float angle = i * 3.14159 / 180.0;
        float x = carX + 0.525 + 0.01 * cos(angle);
        float y = carY + wheelY + 0.01 * sin(angle);
        glVertex2f(x, y);
    }
    glEnd();

}

void drawCar2() {
    // Badan mobil
    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2f(carX2 + 0.45, carY2 + 0.05);
    glVertex2f(carX2 + 0.55, carY2 + 0.05);
    glVertex2f(carX2 + 0.55, carY2 + 0.1);
    glVertex2f(carX2 + 0.45, carY2 + 0.1);
    glEnd();

    // Atap mobil 
    glColor3f(1.0, 1.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(carX2 + 0.47, carY2 + 0.1);
    glVertex2f(carX2 + 0.53, carY2 + 0.1);
    glVertex2f(carX2 + 0.52, carY2 + 0.13);
    glVertex2f(carX2 + 0.48, carY2 + 0.13);
    glEnd();

    // Roda kiri depan
    glColor3f(0.0, 0.0, 0.0);  // Warna hitam untuk roda
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++) {
        float angle = i * 3.14159 / 180.0;
        float x = carX2 + 0.475 + 0.01 * cos(angle);
        float y = carY2 + wheelY + 0.01 * sin(angle);
        glVertex2f(x, y);
    }
    glEnd();

    // Roda kanan depan
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++) {
        float angle = i * 3.14159 / 180.0;
        float x = carX2 + 0.525 + 0.01 * cos(angle);
        float y = carY2 + wheelY + 0.01 * sin(angle);
        glVertex2f(x, y);
    }
    glEnd();
}

void drawRoad() {
    // Lebar jalan
    GLfloat roadWidth = 0.6;

    // Gambar jalan dengan 3 jalur
    glBegin(GL_QUADS);
    glColor3f(0.2, 0.2, 0.2); // Warna abu-abu untuk jalur jalan
    glVertex2f(0.0, 0.2);
    glVertex2f(1.0, 0.2);
    glVertex2f(1.0, 0.5);
    glVertex2f(0.0, 0.5);
    glEnd();

    // Gambar garis pembatas jalur
    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 1.0); // Warna putih untuk garis pembatas

    // Garis batas kiri jalur 1
    glVertex2f(0.0, 0.35);
    glVertex2f(1.0, 0.35);

    // Garis batas kanan jalur 1
    glVertex2f(0.0, 0.45);
    glVertex2f(1.0, 0.45);

    // Garis batas kiri jalur 2
    glVertex2f(0.0, 0.2);
    glVertex2f(1.0, 0.2);

    // Garis batas kanan jalur 2
    glVertex2f(0.0, 0.5);
    glVertex2f(1.0, 0.5);
    glEnd();
}

void drawTree() {
    // Gambar pohon
    glColor3f(0.133, 0.545, 0.133); // Warna hijau gelap untuk daun

    glBegin(GL_TRIANGLES);
    glVertex2f(0.75, 0.5); // Puncak segitiga
    glVertex2f(0.7, 0.4);  // Kiri bawah segitiga
    glVertex2f(0.8, 0.4);  // Kanan bawah segitiga
    glEnd();

    glColor3f(0.545, 0.270, 0.074); // Warna cokelat untuk batang
    glBegin(GL_QUADS);
    glVertex2f(0.75, 0.35);
    glVertex2f(0.76, 0.35);
    glVertex2f(0.76, 0.4);
    glVertex2f(0.75, 0.4);
    glEnd();
}

void drawGrass() {
    // Gambar rumput
    glColor3f(0.0, 0.7, 0.0);  // Warna hijau tua
    glBegin(GL_POLYGON);
    glVertex2f(0.0, 0.0);
    glVertex2f(1.0, 0.0);
    glVertex2f(1.0, 0.2);
    glVertex2f(0.0, 0.2);
    glEnd();
}

void drawCloud(float x, float y) {
    // Gambar satu lingkaran awan pada posisi (x, y)
    glPushMatrix();
    glColor3f(1.0, 1.0, 1.0);  // Warna awan (putih)
    glTranslatef(x, y, 0.0); // Posisi awan

    glutSolidSphere(0.05, 20, 20);

    glPopMatrix();
}

void drawClouds() {
    
    drawCloud(0.2, 0.8);
    drawCloud(0.25, 0.82);
    drawCloud(0.3, 0.78);
}

void drawRightClouds() {
    drawCloud(0.7, 0.9);
    drawCloud(0.75, 0.92);
    drawCloud(0.8, 0.88);
}

void drawPlaneBody1(float x, float y) {
    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2f(x, y);
    glVertex2f(x + 0.13, y);
    glVertex2f(x + 0.145, y + 0.02);
    glVertex2f(x + 0.025, y + 0.02);
    glEnd();
}

void drawPlaneBody2(float x, float y) {
    glColor3ub(70, 130, 150);
    glBegin(GL_QUADS);
    glVertex2f(x + 0.005, y - 0.015);
    glVertex2f(x + 0.115, y - 0.015);
    glVertex2f(x + 0.13, y);
    glVertex2f(x, y);
    glEnd();
}

void drawPlaneTail(float x, float y) {
    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2f(x + 0.12, y + 0.02);
    glVertex2f(x + 0.145, y + 0.02);
    glVertex2f(x + 0.155, y + 0.04);
    glVertex2f(x + 0.14, y + 0.04);
    glEnd();
}

void drawPlaneWing(float x, float y) {
    glColor3ub(0, 80, 128);
    glBegin(GL_QUADS);
    glVertex2f(x + 0.09, y - 0.025);
    glVertex2f(x + 0.11, y - 0.025);
    glVertex2f(x + 0.08, y);
    glVertex2f(x + 0.04, y);
    glEnd();
}


void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Gambar jalan raya dengan 3 jalur
    drawRoad();


    // Gambar beberapa pohon di pinggir jalan
    for (int i = 0; i < 9; ++i) {
        glPushMatrix();
        glTranslatef(-0.7 + i * 0.3, 0.15, 0);
        drawTree();
        glPopMatrix();
    }

    drawCar();
    drawCar2();

    drawClouds();
    drawRightClouds();

    // Gambar rumput 
    glPushMatrix();
    glTranslatef(0.0, 0.0, 0.0); 
    drawGrass();
    glPopMatrix();

    drawPlaneBody1(planeX, planeY);
    drawPlaneBody2(planeX, planeY);
    drawPlaneTail(planeX, planeY);
    drawPlaneWing(planeX, planeY);

    glutSwapBuffers();
}


void init() {
    glClearColor(135.0 / 255.0, 206.0 / 255.0, 250.0 / 255.0, 1.0); // Warna latar belakang (light sky blue)
    gluOrtho2D(0.0, 1.0, 0.0, 1.0);   // Mengatur sistem koordinat
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("UTS LAB GRAFIKA KOMPUTER");

    init();

    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(specialKey); 

    glutMainLoop();

    return 0;
}
