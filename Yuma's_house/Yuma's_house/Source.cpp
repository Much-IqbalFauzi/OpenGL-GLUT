#include <GL/glut.h>
#include <windows.h>

void myInit() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glShadeModel(GL_SMOOTH);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void aspRR(GLsizei width, GLsizei height) {
    if (height == 0) height = 1;
    GLfloat aspect = (GLfloat)width / (GLfloat)height;
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(50.0f, aspect, 0.1f, -100.0f);
}

void warna(int r = 1, int g = 1, int b = 1, float a = 1) {
    glColor4f(r / 255.0f, g / 255.0f, b / 255.0f, a);
}

void kotak_dp(int x, int y, int X, int Y, int zZ) {
    glBegin(GL_QUADS);
    glVertex3d(x, y, zZ);
    glVertex3d(x, Y, zZ);
    glVertex3d(X, Y, zZ);
    glVertex3d(X, y, zZ);
    glEnd();
}

void kotak_kk(int xX, int y, int z, int Y, int Z) {
    glBegin(GL_QUADS);
    glVertex3d(xX, y, z);
    glVertex3d(xX, Y, z);
    glVertex3d(xX, Y, Z);
    glVertex3d(xX, y, Z);
    glEnd();
}

void kotak_ab(int x, int yY, int z, int X, int Z) {
    glBegin(GL_QUADS);
    glVertex3d(x, yY, z);
    glVertex3d(x, yY, Z);
    glVertex3d(X, yY, Z);
    glVertex3d(X, yY, z);
    glEnd();
}

void tampil() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //all box
    warna(227, 89, 130);
    kotak_dp(-30, -30, 60, 20, -30);
    kotak_dp(0, -30, 60, 20, 30);
    kotak_dp(-30, 10, 0, 20, 30);
    warna(184, 73, 106);
    kotak_dp(-30, -30, 0, 10, 0);
    warna(184, 130, 73);
    kotak_dp(5, -25, 60, -20, 50);
    kotak_dp(0, -30, 60, -25, 50);
    //atas
    warna(227, 89, 130);
    kotak_dp(10, 20, 60, 55, 10);
    kotak_dp(10, 20, 60, 45, -30);
    warna(201, 118, 62);
    kotak_dp(10, 20, 60, 30, 50);

    warna(201, 73, 111);
    kotak_kk(-30, -30, -30, 20, 30);
    kotak_kk(60, -30, -30, 20, 30);
    kotak_kk(0, -30, 0, 10, 30);
    warna(150, 101, 48);
    kotak_kk(0, -30, 30, -25, 50);
    kotak_kk(5, -30, 30, -20, 50);
    kotak_kk(60, -30, 30, -20, 50);
    //atas
    warna(201, 73, 111);
    kotak_kk(10, 20, -30, 45, 10);
    kotak_kk(60, 20, -30, 45, 10);
    warna(163, 94, 47);
    kotak_kk(10, 20, 10, 30, 50);
    kotak_kk(60, 20, 10, 30, 50);

    warna(230, 148, 90);
    kotak_ab(-30, 10, 0, 0, 30);
    kotak_ab(-30, -30, -30, 60, 30);
    warna(191, 146, 98);
    kotak_ab(0, -30, 30, 60, 50);
    kotak_ab(0, -25, 30, 5, 50);
    kotak_ab(5, -20, 30, 60, 50);
    //atas
    warna(230, 148, 90);
    kotak_ab(10, 20, -30, 60, 50);
    kotak_ab(10, 50, 10, 60, 50);

    //cagak
    warna(158, 87, 87);
    kotak_dp(50, -20, 58, 20, 48);
    kotak_dp(50, -20, 58, 20, 45);
    kotak_dp(12, -20, 20, 20, 48);
    kotak_dp(12, -20, 20, 20, 45);
    //atas
    kotak_dp(55, 20, 56, 50, 46);
    kotak_dp(55, 20, 56, 50, 45);
    kotak_dp(14, 20, 15, 50, 46);
    kotak_dp(14, 20, 15, 50, 45);

    warna(135, 58, 58);
    kotak_kk(50, -20, 45, 20, 48);
    kotak_kk(58, -20, 45, 20, 48);
    kotak_kk(12, -20, 45, 20, 48);
    kotak_kk(20, -20, 45, 20, 48);
    //atas
    kotak_kk(55, 20, 45, 50, 46);
    kotak_kk(56, 20, 45, 50, 46);
    kotak_kk(14, 20, 45, 50, 46);
    kotak_kk(15, 20, 45, 50, 46);
    
    //acc
    warna(99, 53, 25);
    kotak_dp(35, -20, 45, 0, 30);
    warna(94, 160, 173);
    kotak_dp(15, -15, 35, 0, 30);
    //atas
    warna(99, 53, 25);
    kotak_dp(15, 20, 25, 40, 10);
    warna(94, 160, 173);
    kotak_dp(25, 25, 45, 40, 10);

    //atap
    warna(201, 73, 111);
    glBegin(GL_TRIANGLES);
        glVertex3d(-30, 20, -30);
        glVertex3d(-30, 20, 30);
        glVertex3d(-30, 30, 0);

        glVertex3d(10, 55, 10);
        glVertex3d(10, 45, 10);
        glVertex3d(10, 45, -30);

        glVertex3d(60, 55, 10);
        glVertex3d(60, 45, 10);
        glVertex3d(60, 45, -30);
    glEnd();

    glBegin(GL_QUADS);
        warna(110, 80, 58);
        glVertex3d(-30, 30, 0);  
        glVertex3d(-30, 20, 30);  
        glVertex3d(10, 20, 30);  
        glVertex3d(10, 30, 0);

        warna(94, 67, 47);
        glVertex3d(-30, 30, 0);
        glVertex3d(-30, 20, -30);
        glVertex3d(10, 20, -30);
        glVertex3d(10, 30, 0);

        glVertex3d(10, 55, 10);
        glVertex3d(60, 55, 10);
        glVertex3d(60, 45, -30);
        glVertex3d(10, 45, -30);
    glEnd();


    glutSwapBuffers();
}

void key(unsigned char key, int x, int y) {
    switch (key) {
    case 'a':
    case 'A':
        glTranslatef(-1.0, 0.0, 0.0);
        break;
    case 'd':
    case 'D':
        glTranslatef(1.0, 0.0, 0.0);
        break;
    case 'w':
    case 'W':
        glTranslatef(0.0, 0.0, 1.0);
        break;
    case 's':
    case 'S':
        glTranslatef(0.0, 0.0, -1.0);
        break;
    case 'q':
    case 'Q':
        glTranslatef(0.0, 1.0, 0.0);
        break;
    case 'e':
    case 'E':
        glTranslatef(0.0, -1.0, 0.0);
        break;
    case 'j':
    case 'J':
        glRotatef(1.0, 0.0, -5.0, 0.0);
        break;
    case 'l':
    case 'L':
        glRotatef(1.0, 0.0, 5.0, 0.0);
        break;
    case 'i':
    case 'I':
        glRotatef(1.0, 0.0, 0.0, -5.0);
        break;
    case 'k':
    case 'K':
        glRotatef(1.0, 0.0, 0.0, 5.0);
        break;
    case 'o':
    case 'O':
        glRotatef(1.0, -5.0, 0.0, 0.0);
        break;
    case 'u':
    case 'U':
        glRotatef(1.0, 5.0, 0.0, 0.0);
        break;
    }
    tampil();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE);
    glutInitWindowSize(1000, 600);
    glutInitWindowPosition(133, 54);
    glutCreateWindow("Yummy");
    glutDisplayFunc(tampil);
    glutReshapeFunc(aspRR);
    glutKeyboardFunc(key);
    myInit();
    glutMainLoop();
    return 0;
}