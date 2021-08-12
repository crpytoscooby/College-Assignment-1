#include"GL/gl.h"
#include"GL/glu.h"
#include"GL/freeglut.h"
#include"GL/glut.h"
#include<iostream>
#include<stdio.h>
#include<math.h>
#define w 500
#define h 500
using namespace std;

void myInit(void)
{
	glClearColor(0.6, 0.6, 0.6, 0.0);
	glColor3f(0.13f, 0.13f, 0.155f);
	glPointSize(4.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-w / 2, w / 2, -h / 2, h / 2);
}

void setpixel(GLint x, GLint y)
{
	glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_POINTS);
	glVertex2f(x, y);
	glEnd();
	glFlush();
}

int sign(float x)
{
	if (x > 0)
		return 1;
	else if (x < 0)
		return 1;
	else
		return 0;
}


void simple ()
{
	int x1, y1, x2, y2;
	cout << endl;
	cout << "Enter x co-ordinate of start point (x1): ";
	cin >> x1;
	cout << endl;
	cout << "Enter y co-ordinate of start point (y1): ";
	cin >> y1;
	cout << endl;
	cout << "Enter x co-ordinate of end point (x2): ";
	cin >> x2;
	cout << endl;
	cout << "Enter y co-ordinate of end point (y2): ";
	cin >> y2;
	cout << endl;
	float x, y, dx, dy, length;           //Step 1
	dx = abs(x2 - x1);
	dy = abs(y2 - y1);
	if (dx >= dy)
		length = dx;
	else
		length = dy;


	dx = (x2 - x1) / length;              //Step 2
	dy = (y2 - y1) / length;


	x = x1 + 0.5 * sign(dx);              //Step 3
	y = y1 + 0.5 * sign(dy);
	int i = 1;

	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();

	while (i <= length)
	{
		glBegin(GL_POINTS);
		glVertex2i(x, y);
		glEnd();

		x = x + dx;
		y = y + dy;
		i = i + 1;
	}
}

void dotted ()
{
	int x1, y1, x2, y2;
	cout << endl;
	cout << "Enter x co-ordinate of start point (x1): ";
	cin >> x1;
	cout << endl;
	cout << "Enter y co-ordinate of start point (y1): ";
	cin >> y1;
	cout << endl;
	cout << "Enter x co-ordinate of end point (x2): ";
	cin >> x2;
	cout << endl;
	cout << "Enter y co-ordinate of end point (y2): ";
	cin >> y2;
	cout << endl;
	float x, y, dx, dy, length;           //Step 1
	dx = abs(x2 - x1);
	dy = abs(y2 - y1);
	if (dx >= dy)
		length = dx;
	else
		length = dy;


	dx = (x2 - x1) / length;              //Step 2
	dy = (y2 - y1) / length;


	x = x1 + 0.5 * sign(dx);              //Step 3
	y = y1 + 0.5 * sign(dy);
	int i = 1;

	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();

	while (i <= length)
	{
		if (i % 5 == 0)
		{
			glBegin(GL_POINTS);
			glVertex2i(x, y);
			glEnd();
		}

		x = x + dx;
		y = y + dy;
		i = i + 1;
	}
}

void dashed ()
{
	int x1, y1, x2, y2;
	cout << endl;
	cout << "Enter x co-ordinate of start point (x1): ";
	cin >> x1;
	cout << endl;
	cout << "Enter y co-ordinate of start point (y1): ";
	cin >> y1;
	cout << endl;
	cout << "Enter x co-ordinate of end point (x2): ";
	cin >> x2;
	cout << endl;
	cout << "Enter y co-ordinate of end point (y2): ";
	cin >> y2;
	cout << endl;
	float x, y, dx, dy, length;           //Step 1
	dx = abs(x2 - x1);
	dy = abs(y2 - y1);
	if (dx >= dy)
		length = dx;
	else
		length = dy;


	dx = (x2 - x1) / length;              //Step 2
	dy = (y2 - y1) / length;


	x = x1 + 0.5 * sign(dx);              //Step 3
	y = y1 + 0.5 * sign(dy);
	int i = 1;

	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();

	int  t = 0;
	while (i <= length)
	{
		if (i % 15 == 0)
		{
			if (t == 0)
				t = 1;
			else
				t = 0;
		}
		if (t == 0)
		{
			glBegin(GL_POINTS);
			glVertex2i(x, y);
			glEnd();
		}

		x = x + dx;
		y = y + dy;
		i = i + 1;
	}
}


void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0f, 0.0f, 0.0f);
	glPointSize(4.0);
	for (int i = -w; i <= w; i += 2)
	{
		setpixel(i, 0);
		setpixel(0, i);
	}
	glFlush();
}

void menu(int item)
{
	cout << endl;
	cout << "|-|-|-|-|-You clicked item : " << item << " -|-|-|-|-|";
	cout << endl;
	if (item == 1)
	{
		simple();
	}
	if (item == 2)
	{
		dotted();
	}
	if (item == 3)
	{
		dashed();
	}
	if (item == 4)
	{
		exit(0);
	}
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(700, 700);
	glutInitWindowPosition(700, 700);

	glutCreateWindow("DDA Algorithm Menu");
	glutDisplayFunc(myDisplay);
	myInit();
	glutCreateMenu(menu);
	glutAddMenuEntry("Simple Line", 1);
	glutAddMenuEntry("Dotted Line", 2);
	glutAddMenuEntry("Dashed Line", 3);
	glutAddMenuEntry("Exit", 4);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutMainLoop();
	return 0;
}