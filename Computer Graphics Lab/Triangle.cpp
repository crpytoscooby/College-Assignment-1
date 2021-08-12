#include<iostream>
#include<GL/glut.h>
using namespace std;

void myInit(void)
{
	glClearColor(1, 1, 0, 0);
	glColor3f(0.0f, 0.0f, 0.0f);
	glLineWidth(8.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}

void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_TRIANGLES);
		glVertex2i(100,  100);
		glVertex2i(225, 200);
		glVertex2i(350, 100);
	glEnd();
	glFlush();
}

int main(int argc, char **argv)
{	
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(100, 150);
	glutCreateWindow("Triangle");
	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();
	return 0;
}