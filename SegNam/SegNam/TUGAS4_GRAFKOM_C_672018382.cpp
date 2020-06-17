#include <GL/glut.h>
#include <math.h>
#define PI 3.14

void myInitial() {
	glClearColor(0, 0, 0, 1);
	glPointSize(5.0);
	glLineWidth(0.5);
	glMatrixMode(GL_PROJECTION);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	gluOrtho2D(0.0, 600.0, 0.0, 600.0);
}

void putWarna(int r = 1, int g = 1, int b = 1, float a = 1) {
	glColor4f(r / 255.0f, g / 255.0f, b / 255.0f, a);
}

void wakaranai(int n, float cx, float cy, float radius, float rotAngle)
{
	double angle, angleInc;
	int k;
	if (n < 3) return;
	angle = rotAngle * PI / 180;
	angleInc = 2 * PI / n;
	glVertex2f(radius * cos(angle) + cx, radius * sin(angle) + cy);
	for (k = 0; k < n; k++) {
		angle += angleInc;
		glVertex2f(
			radius * cos(angle) + cx,
			radius * sin(angle) + cy
		);
	}
}

void recal() {
	
	int x = 300;
	int y = 300;
	int r_x = 200;
	int sides = 6;
	int deep = 63;
	int red = 20, green = 0, blue = 200;


	glBegin(GL_LINE_STRIP);
	for (int jah= 1; jah <= deep; jah++)
	{
		putWarna(22, green, blue);
		wakaranai(sides, x, y, r_x - (jah * 0.2), jah * 2);
		r_x -= 3;
		red += 10;
		green += 10;
		blue -= 8;
	}
	glEnd();

}

void tampil() {
	glClear(GL_COLOR_BUFFER_BIT);

	recal();
	glFlush();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(333, 84);
	glutCreateWindow("Muchamad Iqbal Fauzi - 672018382");

	glutDisplayFunc(tampil);
	myInitial();
	glutMainLoop();
}