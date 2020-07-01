#include <GL/glut.h>
#include <windows.h>

void myInitial() {
	glClearColor(0, 0, 0, 0);
	glLineWidth(2.5);
	glClearDepth(1.0f);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glShadeModel(GL_SMOOTH);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
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

void dsp() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	warna(247, 191, 94);
	kotak_dp(-60, -20, 60, 20, -30);
	kotak_dp(-60, -20, 60, 20, 30);

	warna(135, 81, 30);
	kotak_dp(-30, -20, -15, 10, 30);
	warna(141, 227, 208);
	kotak_dp(-50, -10, -30, 10, 30);
	kotak_dp(0, -10, 20, 10, 30);
	kotak_dp(30, -10, 50, 10, 30);

	warna(219, 163, 66);
	kotak_kk(-60, -20, -30, 20, 30);
	kotak_kk(60, -20, -30, 20, 30);

	warna(240, 255, 250);
	kotak_ab(-60, -20, -30, 60, 35);
	kotak_ab(-60, -20, 35, 0, 55);
	kotak_ab(-65, -23, -35, 65, 40);
	kotak_ab(-65, -23, 40, 5, 60);

	warna(216, 235, 228);
	kotak_dp(-60, -23, 0, -20, 55);
	kotak_dp(-60, -23, 60, -20, -30);
	kotak_dp(0, -23, 60, -20, 35);

	warna(202, 222, 214);
	kotak_kk(-60, -23, -30, -20, 55);
	kotak_kk(0, -23, 35, -20, 55);
	kotak_kk(60, -23, -30, -20, 35);
	
	warna(247, 191, 94);
	kotak_dp(-57, -20, -52, 20, 52);
	kotak_dp(-57, -20, -52, 20, 47);
	kotak_dp(-8, -20, -3, 20, 52);
	kotak_dp(-8, -20, -3, 20, 47);

	warna(219, 163, 66);
	kotak_kk(-57, -20, 47, 20, 52);
	kotak_kk(-52, -20, 47, 20, 52);
	kotak_kk(-8, -20, 47, 20, 52);
	kotak_kk(-3, -20, 47, 20, 52);

	warna(153, 99, 52);
	glBegin(GL_QUADS);
		glVertex3d(-70, 20, -40);
		glVertex3d(-30, 40, 0);
		glVertex3d(70, 40, 0);
		glVertex3d(70, 20, -40);
	glEnd();
	warna(143, 91, 46);
	glBegin(GL_QUADS);
		glVertex3d(5, 20, 40);
		glVertex3d(-30, 40, 0);
		glVertex3d(70, 40, 0);
		glVertex3d(70, 20, 40);
	glEnd();
	warna(153, 99, 52);
	glBegin(GL_QUADS);
		glVertex3d(-30, 40, 0);
		glVertex3d(5, 20, 40);
		glVertex3d(5, 20, 65);
		glVertex3d(-30, 40, 65);
	glEnd();
	warna(143, 91, 46);
	glBegin(GL_QUADS);
		glVertex3d(-70, 20, -40);
		glVertex3d(-30, 40, 0);
		glVertex3d(-30, 40, 65);
		glVertex3d(-70, 20, 65);
	glEnd();

	warna(94, 60, 30);
	kotak_ab(-70, 20, -40, 70, 40);
	kotak_ab(-70, 20, 40, 5, 65);

	warna(240, 255, 250);
	glBegin(GL_TRIANGLES);
		glVertex3d(-70, 20, 65);
		glVertex3d(5, 20, 65);
		glVertex3d(-30, 40, 65);

		glVertex3d(70, 20, -40);
		glVertex3d(70, 20, 40);
		glVertex3d(70, 40, 0);
	glEnd();

	glutSwapBuffers();
}

void aspRR(int w, int h) {
	if (h == 0) h = 1;
	GLfloat aspect = (GLfloat)w / (GLfloat)h;
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(100.0f, aspect, 0.1f, -100.0f);
}

void key(unsigned char k, int x, int y) {
	switch (k) {
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
	dsp();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(1000, 600);
	glutInitWindowPosition(133, 84);
	glutCreateWindow("my house");

	glutDisplayFunc(dsp);
	glutReshapeFunc(aspRR);
	glutKeyboardFunc(key);

	myInitial();
	glutMainLoop();
}