#include <GL/glut.h>
#include <windows.h>
#include <iostream>
#include "imageloader.h"
using namespace std;
float xrot = 0;
float yrot = 0;
float xdiff = 0;
float ydiff = 0;
bool mousedown = false;
unsigned int ID;
const float kotak = 20.0f;
int _sudut = 0;
GLuint _textureId;

GLuint loadTexture(Image* image) {
    GLuint textureId;
    glGenTextures(1, &textureId);
    glBindTexture(GL_TEXTURE_2D, textureId);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image->width, image->height, 0, GL_RGB, GL_UNSIGNED_BYTE, image->pixels);
    return textureId;
}

void myInit() {
    glClearColor((float)77 / 255.0f, (float)72 / 255.0f, (float)63 / 255.0f, 1);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glDepthFunc(GL_LEQUAL);
    glShadeModel(GL_SMOOTH);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    Image* image = loadBMP("fti_text.bmp");
    _textureId = loadTexture(image);
    delete image;
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
        cout << xdiff << ydiff << " gerakan" << endl;
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
        cout << "yoi gan " << xrot << yrot << endl;
        glutPostRedisplay();
    }
}

void update(int value) {
    _sudut += 1.0f;
    if (_sudut > 360) {
        _sudut -= 360;
    }
    glutPostRedisplay();
    glutTimerFunc(25, update, 0);
}

void tampil() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(30, 20, 50, 0, 0, 0, 0, 1, 0);
    glRotatef(xrot, 1, 0, 0);
    glRotatef(yrot, 0, 1, 0);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, _textureId);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);
    {
        //Sisi atas
        glTexCoord2f(0.0f, 0.0f);
        glNormal3f(0.0, 1.0f, 0.0f);
        glVertex3f(-kotak / 2, kotak / 2, -kotak / 2);
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(-kotak / 2, kotak / 2, kotak / 2);
        glTexCoord2f(1.0f, 1.0f);
        glVertex3f(kotak / 2, kotak / 2, kotak / 2);
        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(kotak / 2, kotak / 2, -kotak / 2);
    }
    {
        //Sisi bawah
        glTexCoord2f(0.0f, 0.0f);
        glNormal3f(0.0, -1.0f, 0.0f);
        glVertex3f(-kotak / 2, -kotak / 2, -kotak / 2);
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(kotak / 2, -kotak / 2, -kotak / 2);
        glTexCoord2f(1.0f, 1.0f);
        glVertex3f(kotak / 2, -kotak / 2, kotak / 2);
        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(-kotak / 2, -kotak / 2, kotak / 2);
    }
    {
        //Sisi kiri
        glNormal3f(-1.0, 0.0f, 0.0f);
        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(-kotak / 2, -kotak / 2, -kotak / 2);
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(-kotak / 2, -kotak / 2, kotak / 2);
        glTexCoord2f(1.0f, 1.0f);
        glVertex3f(-kotak / 2, kotak / 2, kotak / 2);
        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(-kotak / 2, kotak / 2, -kotak / 2);
    }
    {
        //Sisi kanan
        glNormal3f(1.0, 0.0f, 0.0f);
        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(kotak / 2, -kotak / 2, -kotak / 2);
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(kotak / 2, kotak / 2, -kotak / 2);
        glTexCoord2f(1.0f, 1.0f);
        glVertex3f(kotak / 2, kotak / 2, kotak / 2);
        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(kotak / 2, -kotak / 2, kotak / 2);
    }
    {
        //Sisi depan
        glNormal3f(0.0, 0.0f, 1.0f);
        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(-kotak / 2, -kotak / 2, kotak / 2);
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(kotak / 2, -kotak / 2, kotak / 2);
        glTexCoord2f(1.0f, 1.0f);
        glVertex3f(kotak / 2, kotak / 2, kotak / 2);
        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(-kotak / 2, kotak / 2, kotak / 2);
    }
    {
        //Sisi belakang
        glNormal3f(0.0, 0.0f, -1.0f);
        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(-kotak / 2, -kotak / 2, -kotak / 2);
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(-kotak / 2, kotak / 2, -kotak / 2);
        glTexCoord2f(1.0f, 1.0f);
        glVertex3f(kotak / 2, kotak / 2, -kotak / 2);
        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(kotak / 2, -kotak / 2, -kotak / 2);
    }
    glEnd();
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();
    glutSwapBuffers();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(1000, 600);
    glutInitWindowPosition(133, 54);
    cout << "Muchamad Iqbal Fauzi - 672018382" << endl;
    glutCreateWindow("Muchamad Iqbal Fauzi - 672018382");
    myInit();
    glutReshapeFunc(aspRR);
    glutDisplayFunc(tampil);
    glutMouseFunc(mouseButton);
    glutMotionFunc(mouseMove);

    glutMainLoop();
    return 0;
}