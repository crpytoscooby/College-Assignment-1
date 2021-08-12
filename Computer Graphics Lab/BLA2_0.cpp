#include<iostream>
#include<GL/glut.h>
using namespace std;

void Init()
{
	glClearColor(0.0, 0.0, 0.0, 0);
	glColor3f(1.0, 0.0, 0.0);
	gluOrtho2D(0, 640, 480, 0);
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glFlush();
}

void mymouse(int b, int s, int x, int y)
{
	static int xst, yst, pt = 0;
	if (b == GLUT_LEFT_BUTTON && s == GLUT_DOWN)
	{
		if (pt == 0)
		{
			xst = x; yst = y; pt++;
		}
		else
		{
			/* glBegin(GL_LINE_STRIP); //std function to draw line using GL
			glVertex2i(xst,yst);
			glVertex2i(x,y);*/

			drawddaline(xst, yst, x, y);
			glEnd();
			xst = x; yst = y;

		}
	}

	else if (b == GLUT_RIGHT_BUTTON && s == GLUT_DOWN)
	{
		pt = 0;
	}
	glFlush();
}
int main(int argc , char **argv)
{

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(640, 480);
	glutCreateWindow(“DDA - Line”);
	glutDisplayFunc(display);
	glutMouseFunc(mymouse);
	Init();
	glutMainLoop();
	return 0;

}