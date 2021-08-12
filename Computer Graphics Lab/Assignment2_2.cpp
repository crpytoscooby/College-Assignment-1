#include <iostream>
#include <math.h>
#include <GL/glut.h>
using namespace std;

int s1, s2, interchange, e, flag = 0;
int varx1, vary1, varx2, vary2, varx, vary, dx, dy;

void myInit(void)
{
	glClearColor(0.6, 0.6, 0.6, 0.0);
	glColor3f(0.0f, 0.0f, 0.0f);
	glPointSize(3.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-250.0, 250.0, -250.0, 250.0);
}

void plot(int temp_x, int temp_y)
{
	glBegin(GL_POINTS);
	glVertex2i(temp_x, temp_y);
	glEnd();
	glFlush();
}

int sign(int current)
{
	if (current >= 0)
		return 1;
	else
		return -1;
}

void straightLine()
{
	// Step 1
	varx = varx1;
	vary = vary1;
	dx = abs(varx2 - varx1);
	dy = abs(vary2 - vary1);
	s1 = sign(varx2 - varx1);
	s2 = sign(vary2 - vary1);

	// Step 2
	if (dy > dx)
	{
		int temp = dy;
		dy = dx;
		dx = temp;
		interchange = 1;
	}
	else
		interchange = 0;

	// Step 3
	e = (2 * dy) - dx;
	for (int i = 0; i <= dx; i++)
	{
		while (e >= 0)
		{
			if (interchange)
				varx = varx + s1;
			else
				vary = vary + s2;

			e = e - (2 * dx);
		}

		if (interchange)
			vary = vary + s2;
		else
			varx = varx + s1;

		e = e + (2 * dy);
		plot(varx, vary);
	}
}

void dottedLine()
{
	// Step 1
	varx = varx1;
	vary = vary1;
	dx = abs(varx2 - varx1);
	dy = abs(vary2 - vary1);
	s1 = sign(varx2 - varx1);
	s2 = sign(vary2 - vary1);

	// Step 2
	if (dy > dx)
	{
		int temp = dy;
		dy = dx;
		dx = temp;
		interchange = 1;
	}
	else
		interchange = 0;

	// Step 3
	e = (2 * dy) - dx;
	for (int i = 0; i <= dx; i++)
	{
		while (e >= 0)
		{
			if (interchange)
				varx = varx + s1;
			else
				vary = vary + s2;

			e = e - (2 * dx);
		}

		if (interchange)
			vary = vary + s2;
		else
			varx = varx + s1;

		e = e + (2 * dy);

		if (i % 5 == 0)
			plot(varx, vary);
	}
}

void dashedLine()
{
	int count = 0;
	// Step 1
	varx = varx1;
	vary = vary1;
	dx = abs(varx2 - varx1);
	dy = abs(vary2 - vary1);
	s1 = sign(varx2 - varx1);
	s2 = sign(vary2 - vary1);

	// Step 2
	if (dy > dx)
	{
		int temp = dy;
		dy = dx;
		dx = temp;
		interchange = 1;
	}
	else
		interchange = 0;

	// Step 3
	e = (2 * dy) - dx;
	for (int i = 0; i <= dx; i++)
	{
		while (e >= 0)
		{
			if (interchange)
				varx = varx + s1;
			else
				vary = vary + s2;

			e = e - (2 * dx);
		}

		if (interchange)
			vary = vary + s2;
		else
			varx = varx + s1;

		e = e + (2 * dy);
		if (count < 5)
		{
			plot(varx, vary);
			count++;
		}
		else if (count >= 5 && count < 10)
			count++;
		else
			count = 0;
	}
}

void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	for (int i = -250; i <= 250; i++)
	{
		if (i % 5 == 0)
		{
			plot(i, 0);
			plot(0, i);
		}
	}
}

void myMouse(int button, int state, int x, int y)
{
	if (state == GLUT_DOWN && button == GLUT_LEFT_BUTTON)
	{
		switch (flag)
		{
		case 0:
			varx1 = x - 250;
			vary1 = 250 - y;
			plot(varx1, vary1);
			flag = 1;
			break;
		case 1:
			varx2 = x - 250;
			vary2 = 250 - y;
			plot(varx2, vary2);
			flag = 0;
			break;
		}
	}
}

void myMenu(int choice)
{
	switch (choice)
	{
	case 1:
		cout << "Straight Line" << endl;
		straightLine();
		break;
	case 2:
		cout << "Dotted Line" << endl;
		dottedLine();
		break;
	case 3:
		cout << "Dashed Line" << endl;
		dashedLine();
		break;
	case 4:
		cout << "Exiting..." << endl;
		exit(0);
		break;
	default:
		cout << "Wrong Input" << endl;
		break;
	}
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Assignment 3");
	glutMouseFunc(myMouse);
	glutCreateMenu(myMenu);
	glutAddMenuEntry("Straight Line", 1);
	glutAddMenuEntry("Dotted Line", 2);
	glutAddMenuEntry("Dashed Line", 3);
	glutAddMenuEntry("Exit", 4);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();
	return 0;
}
