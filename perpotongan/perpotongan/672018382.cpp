#include <GL/glut.h>
#include <math.h>
#define PI 3.14

void myInitial() {
	glClearColor(1, 1, 1, 1);
	glPointSize(5.0);
	glLineWidth(2.0);
	glMatrixMode(GL_PROJECTION);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	gluOrtho2D(0.0, 600.0, 0.0, 500.0);
}

void putWarna(int r = 1, int g = 1, int b = 1, float a = 1) {
	glColor4f(r / 255.0f, g / 255.0f, b / 255.0f, a);
}

void kotak(int x, int y) {
	putWarna(50, 117, 168);
	glBegin(GL_QUADS);
	glVertex2i(0 + x, 0 + y);
	glVertex2i(100 + x, 0 + y);
	glVertex2i(100 + x, 100 + y);
	glVertex2i(0 + x, 100 + y);
	glEnd();
}

void sTiga(int x, int y) {
	putWarna(168, 50, 74);
	glBegin(GL_POLYGON);
	glVertex2f(0 + x, 0 + y);
	glVertex2f(100 + x, 0 + y);
	glVertex2f(50 + x, 100 + y);
	glEnd();
}

void bunder(GLfloat x, GLfloat y, GLfloat radd) {
	int i;
	int tJum = 6;
	GLfloat pi_2 = 2.0f * PI;

	putWarna(150, 204, 43, 0.8);
	glBegin(GL_LINE_LOOP);
	//glVertex2f(x, y);
	for (i = 0; i <= tJum; i++) {
		glVertex2f(
			x + (radd * cos(i * pi_2 / tJum)),
			y + (radd * sin(i * pi_2 / tJum))
		);
	}
	glEnd();
}

void tampil() {
	glClear(GL_COLOR_BUFFER_BIT);
	kotak(320, 200);
	sTiga(180, 200);
	bunder(290, 250, 50);
	glFlush();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(600, 500);
	glutInitWindowPosition(333, 114);
	glutCreateWindow("672018382 - Muchamad Iqbal Fauzi");

	glutDisplayFunc(tampil);
	myInitial();
	glutMainLoop();
}