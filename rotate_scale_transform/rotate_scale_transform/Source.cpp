#include <Windows.h>
#include <math.h>
#include <gl/glut.h>
#include <iostream>
#define PI 3.14
using namespace std;

int a = 0, b = 0;

void waktu(int i) {
	glutTimerFunc(1000, waktu, 10);
	glutPostRedisplay();
}

void myInit(void) {
	gluOrtho2D(-500.0, 500.0, -300.0, 300.0);
}

void warna(int r = 1, int g = 1, int b = 1, float a = 1) {
	glColor4f(r / 255.0f, g / 255.0f, b / 255.0f, a);
}

void bunder(GLfloat x, GLfloat y, GLfloat radd) {
	int i;
	int tJum = 100;
	GLfloat pi_2 = 2.0f * PI;
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(x, y);
	for (i = 0; i <= tJum; i++) {
		glVertex2f(
			x + (radd * cos(i * pi_2 / tJum)),
			y + (radd * sin(i * pi_2 / tJum))
		);
	}
	glEnd();
}

void segitiga() {
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(-50, 50);
		glVertex2f(-50, -50);
		glVertex2f(50, 0);
	glEnd();
}

void myDisplay(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	bunder(0, 0, 30);
	glPushMatrix();
		glRotatef(a += 30, 0, 0, 1);
		if ((a/30) % 2 == 1) {
			glColor3f(1.0, 0.0, 0.0);
			glScalef(.5, .5, 1);
			glRectf(250.0, 200.0, 350.0, 300.0);
		}
		else {
			glColor3f(0.0, 1.0, 0.0);
			glScalef(.25, .25, 1);
			glRectf(450.0, 400.0, 550.0, 500.0);
		}
	glPopMatrix();
	glPushMatrix();
		glRotatef(b += 30, 0, 0, -1);
		if ((b / 30) % 2 == 1) {
			glScalef(.25, .25, 1);
			glTranslatef(500, 200, 0);
			glColor3f(0.0, 1.0, 0.0);
			segitiga();
			glColor3f(1.0, 1.0, 0.0);
			glClearColor(.0, 1.0, 1.0, 1.0);
		}
		else {
			glScalef(.5, .5, 1);
			glTranslatef(250, 100, 0);
			glColor3f(0.0, 0.0, 1.0);
			segitiga();
			glColor3f(0.0, 1.0, 1.0);
			glClearColor(1.0, 1.0, .0, 1.0);
		}
	glPopMatrix();
	
	glFlush();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1000, 600);
	glutInitWindowPosition(100, 150);
	//glutCreateWindow("rst");
	//glutDisplayFunc(myDisplay);
	//waktu(0);
	//myInit();
	//glutMainLoop();

	cout << 8382 % 10 << endl;


}