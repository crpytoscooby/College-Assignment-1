#include <iostream>
#include <GL/glut.h>
using namespace std;

void myInit(void)
{
	glClearColor(1, 1, 0, 0);
	glColor3f(0.0f, 0.0f, 0.0f);
	glLineWidth(8.0);
	glPointSize(8.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}

void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_LINE_LOOP);
	glVertex2i(50, 50);
	glVertex2i(50, 150);
	glVertex2i(120, 150);
	glVertex2i(120, 50);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex2i(50, 150);
	glVertex2i(85, 185);
	glVertex2i(120, 150);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex2i(85, 185);
	glVertex2i(385, 185);
	glVertex2i(420, 150);
	glVertex2i(120, 150);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex2i(120, 150);
	glVertex2i(400, 150);
	glVertex2i(400, 50);
	glVertex2i(120, 50);
	glEnd();

	glBegin(GL_POINTS);
	glVertex2i(50, 50);
	glVertex2i(50, 150);
	glVertex2i(400, 50);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex2i(220, 120);
	glVertex2i(300, 120);
	glVertex2i(300, 70);
	glVertex2i(220, 70);
	glEnd();
	glFlush();
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(100, 150);
	glutCreateWindow("House");
	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();
	return 0;
}