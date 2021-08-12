#include <iostream>
#include <math.h>
#include <GL/glut.h>
using namespace std;

int main_radius = 0, center_x = 0, center_y = 0;
int D = 0, x = 0, y = 0, radius_x = 0, radius_y = 0;
int flag = 0;

void myInit(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(0.0f, 0.0f, 0.0f);
	glPointSize(3.0);
	glLineWidth(3.0);
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

void plotCircle(int xc, int yc, int x, int y)
{
	plot(xc + x, yc + y);
	plot(xc + y, yc + x);
	plot(xc - y, yc + x);
	plot(xc - x, yc + y);
	plot(xc - x, yc - y);
	plot(xc - y, yc - x);
	plot(xc + y, yc - x);
	plot(xc + x, yc - y);
}

void circleAlgorithm(int xc, int yc, int radius)
{
	int x = 0;
	int y = radius;
	plotCircle(xc, yc, x, y);
	int D = 3 - (2 * radius);
	while (x <= y)
	{
		x = x + 1;
		if (D < 0)
		{
			D = D + (4 * x) + 6;
		}
		else
		{
			D = D + (4 * (x - y)) + 10;
			y = y - 1;
		}
		plotCircle(xc, yc, x, y);
	}
	glFlush();
}

void concentricCircles()
{
	int xc = center_x, yc = center_y;
	int radius = main_radius;
	int interval = 10;
	while (radius >= 0)
	{
		circleAlgorithm(xc, yc, radius);
		radius -= interval;
	}
}

void olympicRings()
{
	int xc = center_x, yc = center_y;
	int radius = main_radius;
	int i = 0;
	while (i < 3)
	{
		circleAlgorithm(xc, yc, radius);
		xc = xc + (2 * radius) + (0.2 * radius);
		i++;
	}
	i = 0;
	xc = center_x + (1.1 * main_radius);
	yc = center_y - (main_radius);
	while (i < 2)
	{
		circleAlgorithm(xc, yc, radius);
		xc = xc + (2 * radius) + (0.2 * radius);
		i++;
	}
}

void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	for (int i = -250; i <= 250; i++)
	{
		plot(i, 0);
		plot(0, i);
	}
}

void myMenu(int choice)
{
	int xc = center_x;
	int yc = center_y;
	switch (choice)
	{
	case 1:

		cout << "Drawing Circle" << endl;
		circleAlgorithm(center_x, center_y, main_radius);
		break;
	case 2:
		cout << "Drawing Concentric Circle" << endl;
		concentricCircles();
		break;
	case 3:
		cout << "Drawing Olympic Rings" << endl;
		olympicRings();
		break;
	case 4:
		cout << "Exiting..." << endl;
		exit(0);
		break;
	default:
		cout << "Invalid Input" << endl;
		break;
	}
}

void myMouse(int button, int state, int temp_x, int temp_y)
{
	if (state == GLUT_DOWN && button == GLUT_LEFT_BUTTON)
	{
		switch (flag)
		{
		case 0:
			center_x = temp_x - 250;
			center_y = 250 - temp_y;
			plot(center_x, center_y);
			flag = 1;
			break;
		case 1:
			radius_x = temp_x - 250;
			radius_y = 250 - temp_y;
			plot(radius_x, radius_y);
			main_radius = sqrt((radius_x - center_x) * (radius_x - center_x) + (radius_y - center_y) * (radius_y - center_y));
			flag = 0;
			break;
		}
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
	glutAddMenuEntry("Circle", 1);
	glutAddMenuEntry("Concentric Circles", 2);
	glutAddMenuEntry("Olympic Rings", 3);
	glutAddMenuEntry("Exit", 4);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();
	return 0;
}
// b circle drawing algo
// modifications
// 1. concentric circles
// 2. olympic logo
// 3. spiral clockwise and anticlockwise

/* Writeup
1. what is b c algorithm
2. explain 8 way symetry
3. how particular pt will point in one octant and how the particular point will be dericved because of error term
4. decision variable theoDrawing ry error term
validation radius should not be 0*/

/*tranformation
1. translation
2. scaling
3. rotaion
what are tranfor
need for transformation
what are basic transformation
explain with example and show transformation matrix
what are composite transformation
scanning abt fixed point
what are the other transformation
 exaplain reflection and sheer transformation wrto
validation
	check order of matrices
	*/


/*
new
what is B circle algo
8 way symmetry
eg using value - also mention the condition
validation r != 0
input

try concentric
using mouse interface for selecting centre and radius



when to use the decision varia
algo



Transformation
create menu
1. translational
2. scalling
uniform scalling
differential scalling
3. clockwise or anticlockwise rotation
rotation abt arbitrary point
scalling abt fixed point

reflection abt x axis and y axis and sheer abt x and y axis


wha*/

/*void myMenu(int choice)
{
	switch (choice)
	{
	case 1:
		cout << "Circle" << endl;

		break;
	case 2:
		cout << "Concentric Circle" << endl;
		break;
	default:
		cout << "Exiting..." << endl;
		exit(0);
		break;
	}
}*/

// glutCreateMenu(myMenu);
// glutAddMenuEntry("Circle", 1);
// glutAddMenuEntry("Concentric Circle", 2);
// glutAttachMenu(GLUT_RIGHT_BUTTON);