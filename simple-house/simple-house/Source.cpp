#include <GL/glut.h>
#include <windows.h>
#include <stdlib.h>
float xrot = 0;
float yrot = 0;
float xdiff = 0;
float ydiff = 0;
bool mousedown = false;
bool tembok = true;
int is_depth;

void myInitial() {
	glClearColor(0, 0, 0, 0);
	glLineWidth(2);
	glClearDepth(1.0f);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glDepthFunc(GL_LEQUAL);
	glShadeModel(GL_SMOOTH);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	glMatrixMode(GL_PROJECTION);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	is_depth = 1;
}

void warna(int r = 1, int g = 1, int b = 1, float a = 1) {
	glColor4f(r / 255.0f, g / 255.0f, b / 255.0f, a);
}

void idle() {
	if (!mousedown)
	{
		xrot += 0.3f;
		yrot += 0.4f;
	}
	glutPostRedisplay();
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

void kotak_dp(int x=1, int y=1, int X=1, int Y=1, int zZ=1) {
	glBegin(GL_QUADS);
		glVertex3d(x, y, zZ);
		glVertex3d(x, Y, zZ);
		glVertex3d(X, Y, zZ);
		glVertex3d(X, y, zZ);
	glEnd();
}

void kotak_dp_lines(int x = 1, int y = 1, int X = 1, int Y = 1, int zZ = 1) {
	glBegin(GL_LINE_LOOP);
		glVertex3d(x, y, zZ);
		glVertex3d(x, Y, zZ);
		glVertex3d(X, Y, zZ);
		glVertex3d(X, y, zZ);
	glEnd();
}

void kotak_kk(int xX=1, int y=1, int z=1, int Y=1, int Z=1) {
	glBegin(GL_QUADS);
		glVertex3d(xX, y, z);
		glVertex3d(xX, Y, z);
		glVertex3d(xX, Y, Z);
		glVertex3d(xX, y, Z);
	glEnd();
}

void kotak_ab(int x=1, int yY=1, int z=1, int X=1, int Z=1) {
	glBegin(GL_QUADS);
		glVertex3d(x, yY, z);
		glVertex3d(x, yY, Z);
		glVertex3d(X, yY, Z);
		glVertex3d(X, yY, z);
	glEnd();
}

void meja_4() {
	warna(204, 132, 59);
	kotak_dp(-59, -20, -58, -5, -15); kotak_dp(-50, -20, -49, -5, -15);
	kotak_dp(-59, -20, -58, -5, -16); kotak_dp(-50, -20, -49, -5, -16);
	kotak_dp(-59, -20, -58, -5, -24); kotak_dp(-50, -20, -49, -5, -24);
	kotak_dp(-59, -20, -58, -5, -25); kotak_dp(-50, -20, -49, -5, -25);
	warna(166, 105, 43);
	kotak_kk(-59, -20, -16, -5, -15); kotak_kk(-58, -20, -16, -5, -15); kotak_kk(-50, -20, -16, -5, -15); kotak_kk(-49, -20, -16, -5, -15);
	kotak_kk(-59, -20, -25, -5, -24); kotak_kk(-58, -20, -25, -5, -24); kotak_kk(-50, -20, -25, -5, -24); kotak_kk(-49, -20, -25, -5, -24);
	warna(66, 39, 11, .9);
	kotak_ab(-60, -5, -26, -48, -14);
}

void meja_2() {
	warna(55, 179, 64);
	kotak_dp(50, -20, 60, -10, 15); kotak_dp(50, -20, 60, -10, 14); kotak_dp(50, -20, 60, -10, -14); kotak_dp(50, -20, 60, -10, -15);
	warna(39, 143, 46);
	kotak_kk(50, -20, 14, -10, 15); kotak_kk(50, -20, -15, -10, -14);
	warna(8, 61, 12, .9);
	kotak_ab(50, -10, -15, 60, 15);
}

void kasur() {
	warna(224, 203, 61);
	kotak_dp(20, -20, 35, -12, 0);
	warna(186, 168, 45);
	kotak_kk(20, -20, -30, -12, 0); kotak_kk(35, -20, -30, -12, 0);
	warna(194, 187, 138);
	kotak_ab(20, -12, -30, 35, 0);
	//empuk
	warna(228, 235, 183);
	kotak_dp(21, -12, 34, -10, -1); kotak_dp(21, -12, 34, -10, -29);
	warna(207, 214, 161);
	kotak_kk(21, -12, -29, -10, -1); kotak_kk(34, -12, -29, -10, -1);
	warna(219, 222, 200);
	kotak_ab(21, -10, -29, 34, -1);
}

void lemari() {
	warna(148, 107, 18);
	kotak_dp(-8, -20, 8, 8, -20);
	warna(125, 93, 25);
	kotak_kk(-8, -20, -30, 8, -20); kotak_kk(8, -20, -30, 8, -20);
	warna(128, 87, 0);
	kotak_ab(-8, 8, -30, 8, -20);
	warna(71, 49, 0);
	glBegin(GL_LINES);
		glVertex3d(0, 8, -20); glVertex3d(0, -20, -20);
	glEnd();
	warna(222, 178, 80);
	kotak_dp_lines(2, -17, 6, 6, -20);
	kotak_dp_lines(-6, -17, -2, 6, -20);
}

void sofa() {
	warna(209, 186, 134);
	kotak_dp(-60, -12, -57, 0, 25); kotak_dp(-60, -12, -57, 0, -5);
	kotak_dp(-60, -20, -45, -12, 25); kotak_dp(-60, -20, -45, -12, -5);
	warna(168, 149, 106);
	kotak_kk(-57, -12, -5, 0, 25);
	kotak_kk(-45, -20, -5, -12, 25);
	warna(196, 190, 175);
	kotak_ab(-60, 0, -5, -57, 25);
	kotak_ab(-57, -12, -5, -45, 25);
}

void furniture() {
	meja_4();
	meja_2();
	kasur();
	lemari();
	sofa();
}

void dsp() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPushMatrix();
	gluLookAt(0, 0, 150, 0, 0, 0, 0, 1, 0);
	glRotatef(xrot, 1, 0, 0);
	glRotatef(yrot, 0, 1, 0);

	warna(247, 191, 94);
	if (tembok) {
		kotak_dp(-60, 10, 60, 20, 30);
		kotak_dp(-60, -20, -30, -10, 30);
		kotak_dp(-15, -20, 60, -10, 30);

		kotak_dp(-60, -10, -50, 10, 30);
		kotak_dp(50, -10, 60, 10, 30);
		kotak_dp(-15, -10, 0, 10, 30);
		kotak_dp(20, -10, 30, 10, 30);

		warna(135, 81, 30);
		kotak_dp(-30, -20, -15, 10, 30);
	}
	kotak_dp(-60, -20, 60, 20, -30);

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

	furniture();

	if (tembok) {
		warna(141, 227, 208, .7);
		kotak_dp(-50, -10, -30, 10, 30);
		kotak_dp(0, -10, 20, 10, 30);
		kotak_dp(30, -10, 50, 10, 30);
	}

	glPopMatrix();
	glutSwapBuffers();
}

void aspRR(int w, int h) {
	if (h == 0) h = 1;
	GLfloat aspect = (GLfloat)w / (GLfloat)h;
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0f, aspect, 0.1f, -100.0f);
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
		case '5':
			if (tembok) {
				tembok = false;
			} else {
				tembok = true;
			}
			
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
	myInitial();
	glutDisplayFunc(dsp);
	glutReshapeFunc(aspRR);
	glutKeyboardFunc(key);
	glutMouseFunc(mouseButton);
	glutMotionFunc(mouseMove);
	glutIdleFunc(dsp);

	glutMainLoop();
	return 0;
}