#include <GL/glut.h>

void myInitial() {
	glClearColor(1, 1, 1, 1);
	glPointSize(5.0);
	glLineWidth(5.0);
	glMatrixMode(GL_PROJECTION);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	gluOrtho2D(0.0, 1000.0, 0.0, 600.0);
}

void putWarna(int r = 1, int g = 1, int b = 1, float a=1) {
	glColor4f(r / 255.0f, g / 255.0f, b / 255.0f, a);
}

void ue(double ps=1, double ls=1, double gx=0, double gy=0) {
	glBegin(GL_QUADS);
	glVertex2d(0 + (gx * 5), (3 * ls) + (gy * 3));
	glVertex2d((5 * ls) + (gx * 5), 0 + (gy * 3));
	if (ps > ls) {
		glVertex2d((5 * (ls + ps)) + (gx * 5), (3 * ps) + (gy * 3));
		glVertex2d((5 * ps) + (gx * 5), (3 * (ps + ls)) + (gy * 3));
	} else if (ls > ps) {
		glVertex2d((5 * (ps + ls)) + (gx * 5), (3 * ps) + (gy * 3));
		glVertex2d((5 * ps) + (gx * 5), (3 * (ls + ps)) + (gy * 3));
	}
	else {
		glVertex2d((5 * 2 * ls) + (gx * 5), (3 * ps) + (gy * 3));
		glVertex2d((5 * ps) + (gx * 5), (3 * 2 * ls) + (gy * 3));
	}
	glEnd();
}

void migi(double p=1, double l=1, double gx=0, double gy=0) {
	glBegin(GL_POLYGON);
	glVertex2d(0 + (gx * 5), 0 + (gy * 3));
	glVertex2d((5 * p) + (gx * 5), (3 * p) + (gy * 3));
	glVertex2d((5 * p) + (gx * 5), (3 * (p + l)) + (gy * 3));
	glVertex2d((0 * l) + (gx * 5), (3 * l) + (gy * 3));
	glEnd();
}

void hidari(double p=1, double l=1, double gx=0, double gy=0) {
	glBegin(GL_POLYGON);
	glVertex2d(0 + (gx * 5), (3 * l) + (gy * 3));
	glVertex2d((5 * l) + (gx * 5), 0 + (gy * 3));
	glVertex2d((5 * l) + (gx * 5), (3 * p) + (gy * 3));
	glVertex2d(0 + (gx * 5), (3 * (p + l)) + (gy * 3));
	glEnd();
}

void cagak(double gx, double gy) {
	glBegin(GL_LINES);
	putWarna(22, 29, 75);
	glVertex2d(0+gx, 0+gy);
	glVertex2d(0+gx, 36+gy);
	glEnd();
}

void tampil() {
	glClear(GL_COLOR_BUFFER_BIT);

	//base
	putWarna(226, 192, 167);
	ue(130, 130, -30, -55);

	//kolam
	putWarna(204, 213, 220);
	ue(35, 60, 10, -10);

	putWarna(100, 215, 234);
	ue(30, 55, 15, -5);

	putWarna(224, 224, 224);
	hidari(2, 60, 10, -12);

	putWarna(177, 182, 186);
	migi(30, 2, 75, -7);

	//suket
	putWarna(59, 195, 127);
	ue(20, 15, 110, 20);

	putWarna(63, 133, 82);
	hidari(2, 15, 110, 18);

	putWarna(28, 100, 64);
	migi(20, 2, 125, 18);

	
	//bottom_ left to right
	putWarna(145, 170, 181);
	hidari(30, 15, 90, 40);
	putWarna(193, 206, 212);
	hidari(26, 11, 92, 44);

	putWarna(89, 114, 125);
	migi(25, 30, 105, 40);
	putWarna(143, 158, 166);
	migi(21, 26, 107, 44);

	putWarna(145, 170, 181);
	hidari(30, 25, 130, 40);
	putWarna(193, 206, 212);
	hidari(26, 21, 132, 44);

	putWarna(89, 114, 125);
	migi(15, 30, 155, 40);
	putWarna(143, 158, 166);
	migi(11, 26, 157, 44);

	//middle left to right
	putWarna(224, 224, 224);
	hidari(30, 25, 70, 60);
	//window 1
	putWarna(145, 170, 181);
	hidari(20, 5, 75, 80);
	putWarna(193, 206, 212);
	hidari(15, 3, 76, 83);

	putWarna(145, 170, 181);
	hidari(20, 5, 85, 70);
	putWarna(193, 206, 212);
	hidari(15, 3, 86, 73);
	//end

	putWarna(177, 182, 186);
	migi(30, 30, 95, 60);
	//window 2
	putWarna(89, 114, 125);
	migi(20, 15, 100, 72);
	putWarna(143, 158, 166);
	migi(18, 10, 101, 75);
	//end

	putWarna(224, 224, 224);
	hidari(30, 30, 125, 60);
	//window 3
	putWarna(145, 170, 181);
	hidari(20, 5, 130, 85);
	putWarna(193, 206, 212);
	hidari(15, 3, 131, 88);

	putWarna(145, 170, 181);
	hidari(20, 5, 137, 78);
	putWarna(193, 206, 212);
	hidari(15, 3, 138, 81);

	putWarna(145, 170, 181);
	hidari(20, 5, 144, 71);
	putWarna(193, 206, 212);
	hidari(15, 3, 145, 74);
	//end

	putWarna(177, 182, 186);
	migi(20, 30, 155, 60);
	//window 4

	//end

	//roof left to right
	putWarna(244, 244, 244);
	ue(50, 25, 70, 90);
	putWarna(244, 244, 244);
	ue(20, 30, 125, 90);

	//roof puuru
	putWarna(224, 224, 224);
	hidari(5, 15, 80, 100);

	putWarna(177, 182, 186);
	migi(35, 5, 95, 100);

	putWarna(204, 213, 220);
	ue(35, 15, 80, 105);

	putWarna(100, 215, 234);
	ue(30, 10, 85, 110);

	putWarna(46, 211, 197, 0.4);
	hidari(12, 55, 120, 110);

	cagak(600, 495);

	putWarna(46, 211, 197, 0.4);
	migi(50, 12, 70, 115);

	cagak(351, 345);

	putWarna(46, 211, 197, 0.4);
	hidari(12, 25, 70, 90);

	cagak(476, 270);

	putWarna(46, 211, 197, 0.4);
	migi(30, 12, 95, 90);

	//top room
	putWarna(224, 224, 224);
	hidari(30, 2.5, 125, 115);

	putWarna(177, 182, 186);
	migi(2.5, 30, 127.5, 117.5);

	// inner glass start
	putWarna(145, 170, 181);
	hidari(30, 15, 130, 105);
	putWarna(193, 206, 212);
	hidari(25, 13, 131, 108);

	putWarna(89, 114, 125);
	migi(15, 30, 145, 105);
	putWarna(143, 158, 166);
	migi(13, 25, 146, 108);
	// inner glass finish

	putWarna(244, 244, 244);
	ue(20, 20, 125, 130);

	putWarna(224, 224, 224);
	hidari(5, 20, 125, 125);

	putWarna(224, 224, 224);
	hidari(30, 2.5, 160, 117.5);

	putWarna(177, 182, 186);
	migi(20, 5, 145, 125);

	putWarna(177, 182, 186);
	migi(2.5, 30, 162.5, 117.5);

	//outer glass start
	

	putWarna(46, 211, 197, 0.4);
	hidari(12, 27.5, 127.5, 90);

	cagak(775, 271);
	cagak(875, 331);

	putWarna(46, 211, 197, 0.4);
	migi(20, 12, 155, 90);
	//outer glass finish

	

	glFlush();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1000, 600);
	glutInitWindowPosition(133, 84);
	glutCreateWindow("672018382 - Muchamad Iqbal Fauzi");

	glutDisplayFunc(tampil);
	myInitial();
	glutMainLoop();
}