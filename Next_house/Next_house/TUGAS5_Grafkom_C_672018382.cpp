/*
    README
    Q,W,E,A,S,D / q,w,e,a,s,d : MOVE
    U,I,O,J,K,L / u,i,o,j,k,l : ROTATE
    Click & drag : ROTATE
    V / v : OPEN / CLOSE DOOR
*/

#include <GL/glut.h>
#include <windows.h>
#include <iostream>
using namespace std;
float xrot = 0;
float yrot = 0;
float xdiff = 0;
float ydiff = 0;
bool mousedown = false;
bool tobira = true;
int tob_hidari = 0;
int tob_migi = 0;

void myInit() {
    glClearColor((float)77 / 255.0f, (float)72 / 255.0f, (float)63 / 255.0f, 1);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
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
    gluPerspective(45.0f, aspect, 0.1f, -100.0f);
}

void mouseButton(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        mousedown = true;
        xdiff = x - yrot;
        ydiff = -y + xrot;
    }
    else {
        mousedown = false;
    }
    glutPostRedisplay();
}

void mouseMove(int x, int y) {
    if (mousedown) {
        yrot = x - xdiff;
        xrot = y + ydiff;

        glutPostRedisplay();
    }
}

void putWarna(int r = 1, int g = 1, int b = 1, float a = 1) {
    glColor4f(r / 255.0f, g / 255.0f, b / 255.0f, a);
}

void box_frontBack(int panjang = 1, int tinggi = 1, int p_x = 0, int p_y = 0, int p_z = 0) {

    glBegin(GL_QUADS);
        glVertex3d(0 + p_x, 0 + p_y, 0 + p_z);
        glVertex3d((1 * panjang) + p_x, 0 + p_y, 0 + p_z);
        glVertex3d((1 * panjang) + p_x, (1 * tinggi) + p_y, 0 + p_z);
        glVertex3d(0 + p_x, (1 * tinggi) + p_y, 0 + p_z);
    glEnd();
}

void box_sides(int lebar = 1, int tinggi = 1, int p_x = 0, int p_y = 0, int p_z = 0) {

    glBegin(GL_QUADS);
        glVertex3d(0 + p_x, 0 + p_y, 0 + p_z);
        glVertex3d(0 + p_x, 0 + p_y, (-1 * lebar) + p_z);
        glVertex3d(0 + p_x, (1 * tinggi) + p_y, (-1 * lebar) + p_z);
        glVertex3d(0 + p_x, (1 * tinggi) + p_y, 0 + p_z);
    glEnd();
}

void box_topBottom(int panjang = 1, int lebar = 1, int p_x = 0, int p_y = 0, int p_z = 0) {

    glBegin(GL_QUADS);
        glVertex3d(0 + p_x, 0 + p_y, 0 + p_z);
        glVertex3d((1 * panjang) + p_x, 0 + p_y, 0 + p_z);
        glVertex3d((1 * panjang) + p_x, 0 + p_y, (-1 * lebar) + p_z);
        glVertex3d(0 + p_x, 0 + p_y, (-1 * lebar) + p_z);
    glEnd();
}

void mainHouse() {
    
    //face up
    putWarna(255, 112, 96);
    box_frontBack(70, 5, -35, 0, 40); box_frontBack(70, 5, -35, 0, -40);
    //back
    box_frontBack(25, 25, -35, -25, -40); box_frontBack(25, 25, 10, -25, -40);
    box_frontBack(20, 20, -10, -25, -40);
    //window and door
    box_frontBack(5, 25, -35, -25, 40); box_frontBack(5, 25, 30, -25, 40);
    box_frontBack(10, 5, -30, -25, 40); box_frontBack(10, 5, 20, -25, 40);
    box_frontBack(5, 25, -20, -25, 40); box_frontBack(5, 25, 15, -25, 40);
    //top ceiling
    glBegin(GL_TRIANGLES);
        glVertex3d(-35, 5, 40); glVertex3d(35, 5, 40); glVertex3d(0, 25, 40);
        glVertex3d(-35, 5, -40); glVertex3d(35, 5, -40); glVertex3d(0, 25, -40);
        //middle wall
        putWarna(178, 94, 143);
        glVertex3d(-35, 5, 0); glVertex3d(35, 5, 0); glVertex3d(0, 25, 0);
    glEnd();
    box_frontBack(70, 5, -35, 0, 0); box_frontBack(55, 5, -35, -25, 0);
    box_frontBack(40, 20, -20, -20, 0); box_frontBack(5, 20, -35, -20, 0);
    //base
    putWarna(211, 225, 228);
    box_topBottom(110, 120, -55, -25, 60); box_topBottom(110, 120, -55, -30, 60);
    putWarna(255, 112, 96);
    box_frontBack(110, 5, -55, -30, 60); box_frontBack(110, 5, -55, -30, -60);
    putWarna(201, 84, 75);
    box_sides(120, 5, -55, -30, 60); box_sides(120, 5, 55, -30, 60);
    //sides
    putWarna(201, 84, 75);
    box_sides(80, 5, -35, 0, 40); box_sides(80, 5, 35, 0, 40);
    box_sides(40, 25, 35, -25, 0); box_sides(40, 25, -35, -25, 40);
    box_sides(40, 5, 35, -25, 40); box_sides(40, 5, -35, -25, 0);
    box_sides(5, 20, 35, -20, 40); box_sides(5, 20, 35, -20, 30); box_sides(5, 20, -35, -20, -35); box_sides(5, 20, -35, -20, -25);
    //roof
    
    glBegin(GL_QUADS);
        putWarna(132, 70, 119);
        glVertex3d(35, 5, 45); glVertex3d(35, 5, -45); glVertex3d(0, 25, -45); glVertex3d(0, 25, 45);

        putWarna(113, 62, 105);
        glVertex3d(-35, 5, 45); glVertex3d(-35, 5, -45); glVertex3d(0, 25, -45); glVertex3d(0, 25, 45);
    glEnd();
}

void glass() {
    putWarna(232, 206, 254, .7);
    box_frontBack(10, 20, -30, -20, 40); box_frontBack(10, 20, 20, -20, 40); box_frontBack(10, 20, -30, -20, 0); box_frontBack(20, 5, -10, -5, -40);
    putWarna(209, 188, 227, .7);
    box_sides(5, 20, 35, -20, 35); box_sides(5, 20, -35, -20, -30);
    box_sides(25, 20, 35, -20, 25); box_sides(25, 20, -35, -20, 0);
}

void sofa() {
    putWarna(243, 221, 104);
    box_frontBack(25, 8); box_frontBack(25, 7, 0, 8, -7); box_frontBack(25, 15, 0, 0, -10);
    putWarna(217, 192, 13);
    box_sides(7, 8); box_sides(7, 8, 25);
    box_sides(3, 15, 0, 0, -7); box_sides(3, 15, 25, 0, -7);
    putWarna(229, 198, 10);
    box_topBottom(25, 7, 0, 8); box_topBottom(25, 3, 0, 15, -7);
}

void sofa2() {
    putWarna(168, 93, 149);
    box_frontBack(2, 12); box_frontBack(2, 12, 32); box_frontBack(30, 6, 2); box_frontBack(30, 6, 2, 6, -10);
    putWarna(199, 122, 178);
    box_topBottom(2, 12, 0, 12); box_topBottom(2, 12, 32, 12); box_topBottom(30, 10, 2, 6); box_topBottom(30, 2, 2, 12, -10);
    putWarna(132, 70, 119);
    box_sides(12, 12); box_sides(12, 12, 2); box_sides(12, 12, 32); box_sides(12, 12, 34);
}

void sukue() {
    putWarna(91, 160, 142);
    box_frontBack(1, 11, 10, 1, -6); box_frontBack(1, 11, 10, 1, -7);
    box_frontBack(3, 1, 9, 0, -5); box_frontBack(3, 1, 9, 0, -8);
    putWarna(12, 86, 82);
    box_sides(1, 11, 10, 1, -6); box_sides(1, 11, 11, 1, -6);
    box_sides(3, 1, 9, 0, -5); box_sides(3, 1, 12, 0, -5);
    putWarna(4, 56, 53);
    box_topBottom(3, 3, 9, 1, -5); box_topBottom(1, 1, 10, 12, -6);
    putWarna(4, 56, 53, .9);
    box_topBottom(21, 15, 0, 12, 1);
}

void sukue2() {
    putWarna(91, 160, 142);
    box_frontBack(1, 8, 0, 0, -8); box_frontBack(1, 8, 21, 0, -8);
    putWarna(12, 86, 82);
    box_sides(8, 8); box_sides(8, 8, 1); box_sides(8, 8, 21); box_sides(8, 8, 22);
    putWarna(4, 56, 53);
    box_topBottom(1, 8, 0, 8); box_topBottom(1, 8, 21, 8);
    putWarna(4, 56, 53, .9);
    box_topBottom(22, 8, 0, 8);
}

void terebi_gurasu() {
    putWarna(2, 3, 18);
    box_frontBack(35, 10, 0, 4);
}

void terebi() {
    putWarna(55, 58, 130);
    box_frontBack(35, 1, 0, 4, -1); box_frontBack(35, 1, 0, 13, -1);
    box_frontBack(1, 8, 0, 5, -1); box_frontBack(1, 8, 34, 5, -1);
    box_frontBack(1, 3, 16, 1, -1);
    box_frontBack(5, 1, 14, 0, -2);
    putWarna(32, 35, 92);
    box_topBottom(35, 1, 0, 4); box_topBottom(35, 1, 0, 14);
    box_topBottom(33, 1, 1, 5); box_topBottom(33, 1, 1, 13);
    box_topBottom(5, 3, 14, 1, 1);
    putWarna(11, 13, 54);
    box_sides(1, 10, 0, 4); box_sides(1, 10, 35, 4);
    box_sides(1, 8, 1, 5); box_sides(1, 8, 34, 5);
    box_sides(1, 3, 16, 1, 0); box_sides(1, 3, 17, 1, 0);
    box_sides(3, 1, 14, 0, 1); box_sides(3, 1, 19, 0, 1);
    terebi_gurasu();
}

void tobira_hidari() {
    putWarna(82, 44, 14);
    box_frontBack(15, 25, tob_hidari - 15, -25, 39);
    putWarna(207, 138, 54);
    box_frontBack(1, 3, tob_hidari - 3, -14, 39);
    putWarna(59, 31, 9);
    box_sides(1, 25, tob_hidari - 15, -25, 40);
    box_topBottom(15, 1, tob_hidari - 15, 0, 40);
}

void tobira_migi() {
    putWarna(82, 44, 14);
    box_frontBack(15, 25, tob_migi, -25, 39);
    putWarna(207, 138, 54);
    box_frontBack(1, 3, tob_migi + 2, -14, 39);
    putWarna(59, 31, 9);
    box_sides(1, 25, tob_migi + 15, -25, 40);
    box_topBottom(15, 1, tob_migi, 0, 40);
}

void tampil() {
    
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        gluLookAt(60, 20, 150, 0, 0, 0, 0, 1, 0);
        glRotatef(xrot, 1, 0, 0);
        glRotatef(yrot, 0, 1, 0);
        mainHouse();
        {
            glTranslated(-20, -25, 11);
            sofa();
            glTranslated(20, 25, -11);
        }
        {
            glRotated(90, 0, 1, 0);
            glTranslated(-36, -25, -24);
            sofa();
            glTranslated(36, 25, 24);
            glRotated(90, 0, -1, 0);
        }
        {
            glTranslated(-18, -25, 30);
            sukue();
            glTranslated(18, 25, -30);
        }
        {
            glTranslated(-17, -25, -27);
            sofa2();
            glTranslated(17, 25, 27);
        }
        {
            glTranslated(-11, -25, 0);
            sukue2();
            glTranslated(11, 25, 0);
        }
        {
            glTranslated(-16, -17, -1);
            terebi();
            glTranslated(16, 17, 1);
        }
        {
            tobira_hidari();
            tobira_migi();
        }
        glass();

    glPopMatrix();

    glutSwapBuffers();
}

void toki_open(int) {
    glutPostRedisplay();

    if ((tob_hidari > -15) || (tob_migi < 15)) {
        glutTimerFunc(1000 / 60, toki_open, 0);
        tob_hidari -= 1;
        tob_migi += 1;
        cout << "move-open" << tob_hidari << endl;
    }
    if (tob_hidari == -15) {
        cout << "stop" << endl;
        tobira = false;
    }
}

void toki_close(int) {
    glutPostRedisplay();

    if ((tob_hidari < 0) || (tob_migi > 0)) {
        glutTimerFunc(1000 / 60, toki_close, 0);
        tob_hidari += 1;
        tob_migi -= 1;
        cout << "move-close" << tob_hidari << endl;
    }
    if (tob_hidari == 0) {
        cout << "stop" << endl;
        tobira = true;
    }
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
        case 'v':
        case 'V':
            if (tobira) {
                glutTimerFunc(0, toki_open, 0);
            } else {
                glutTimerFunc(0, toki_close, 0);
            }
            break;
    }
    cout << key << endl;
    tampil();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE);
    glutInitWindowSize(1000, 600);
    glutInitWindowPosition(133, 54);

    glutCreateWindow("Muchamad Iqbal Fauzi - 672018382");
    myInit();
    glutReshapeFunc(aspRR);
    glutDisplayFunc(tampil);
    glutKeyboardFunc(key);
    glutMouseFunc(mouseButton);
    glutMotionFunc(mouseMove);

    glutMainLoop();
    return 0;
}