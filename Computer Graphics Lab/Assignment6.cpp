#include <iostream>
#include <math.h>
#include <GL/glut.h>
using namespace std;

class coOrdinate
{
public:
	int my_x, my_y;
};

coOrdinate *obj;
int count = 0, edge = 0;

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

void plot(int current_x, int current_y)
{
	glBegin(GL_POINTS);
	glVertex2i(current_x, current_y);
	glEnd();
	glFlush();
}

void drawPolygon()
{
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < edge; i++)
	{
		glVertex2i(obj[i].my_x, obj[i].my_y);
	}
	glEnd();
	glFlush();
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

void translation()
{
	int Dx, Dy;
	cout << "Enter Dx and Dy respectively: ";
	cin >> Dx >> Dy;
	for (int i = 0; i < edge; i++)
	{
		obj[i].my_x += Dx;
		obj[i].my_y += Dy;
	}
}

void scaling()
{
	double Sx, Sy;
	cout << "Enter Sx and Sy respectively: ";
	cin >> Sx >> Sy;
	for (int i = 0; i < edge; i++)
	{
		obj[i].my_x = obj[i].my_x * Sx;
		obj[i].my_y = obj[i].my_y * Sy;
	}
}

void rotation(int c)
{
	int theta;
	cout << "Enter Angle: ";
	cin >> theta;

	double cosx = cos(theta * 3.142 / 180.0);
	double sinx = sin(theta * 3.142 / 180.0);

	if (c == 1)
	{
		for (int i = 0; i < edge; i++)
		{
			int temp_x = obj[i].my_x;
			int temp_y = obj[i].my_y;

			obj[i].my_x = (cosx * temp_x) + (sinx * temp_y);
			obj[i].my_y = (-sinx * temp_x) + (cosx * temp_y);
		}
	}
	else if (c == 2)
	{
		for (int i = 0; i < edge; i++)
		{
			int temp_x = obj[i].my_x;
			int temp_y = obj[i].my_y;

			obj[i].my_x = (cosx * temp_x) - (sinx * temp_y);
			obj[i].my_y = (sinx * temp_x) + (cosx * temp_y);
		}
	}
}

void reflection()
{
	int choice;
	cout << "Reflection of Image with respect to: " << endl;
	cout << "1. X - axis" << endl;
	cout << "2. Y - axis" << endl;
	cout << "3. Along Origin" << endl;
	cin >> choice;

	if (choice == 1)
	{
		for (int i = 0; i < edge; i++)
		{
			obj[i].my_y = -obj[i].my_y;
		}
	}
	else if (choice == 2)
	{
		for (int i = 0; i < edge; i++)
		{
			obj[i].my_x = -obj[i].my_x;
		}
	}
	else if (choice == 3)
	{
		for (int i = 0; i < edge; i++)
		{
			obj[i].my_x = -obj[i].my_x;
			obj[i].my_y = -obj[i].my_y;
		}
	}
	else
	{
		cout << "Invalid Input" << endl;
		exit(0);
	}
}

void shear()
{
	int xSh = 0, ySh = 0;
	cout << "Enter x-Shear and y-Shear: " << endl;
	cin >> xSh >> ySh;
	for (int i = 0; i < edge; i++)
	{
		int temp_x = obj[i].my_x;
		int temp_y = obj[i].my_y;

		obj[i].my_x = temp_x + (xSh * temp_y);
		obj[i].my_y = temp_y + (ySh * temp_x);
	}
}

void myMouse(int button, int state, int temp_x, int temp_y)
{
	if (state == GLUT_DOWN && button == GLUT_LEFT_BUTTON)
	{
		if (count < edge)
		{

			temp_x = temp_x - 250;
			temp_y = 250 - temp_y;
			plot(temp_x, temp_y);
			obj[count].my_x = temp_x;
			obj[count].my_y = temp_y;
			count++;
		}
		else
		{
			drawPolygon();
			count = 0;
		}
	}
}

void myMenu(int choice)
{
	glClear(GL_COLOR_BUFFER_BIT);
	for (int i = -250; i <= 250; i++)
	{
		plot(i, 0);
		plot(0, i);
	}
	int c = 0;
	switch (choice)
	{
	case 1:
		drawPolygon();
		cout << "Translation Function Called" << endl;
		translation();
		drawPolygon();
		break;
	case 2:
		drawPolygon();
		cout << "Scaling Function Called" << endl;
		scaling();
		drawPolygon();
		break;
	case 3:
		drawPolygon();
		cout << "Rotation Function Called" << endl;
		cout << "1. Rotate in Clockwise" << endl;
		cout << "2. Rotate in CounterClockwise" << endl;
		cin >> c;
		rotation(c);
		drawPolygon();
		break;
	case 4:
		drawPolygon();
		cout << "Reflection Function Called" << endl;
		reflection();
		drawPolygon();
		break;
	case 5:
		drawPolygon();
		cout << "Shear Function Called" << endl;
		shear();
		drawPolygon();
		break;
	case 6:
		cout << "Exiting..." << endl;
		exit(0);
		break;
	default:
		cout << "Invalid Input!" << endl;
		break;
	}
}

int main(int argc, char **argv)
{
	cout << "Enter number of edges: ";
	cin >> edge;
	obj = new coOrdinate[edge];
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Assignment 6");
	glutMouseFunc(myMouse);
	glutCreateMenu(myMenu);
	glutAddMenuEntry("Translation", 1);
	glutAddMenuEntry("Scaling", 2);
	glutAddMenuEntry("Rotation", 3);
	glutAddMenuEntry("Reflection", 4);
	glutAddMenuEntry("Shear", 5);
	glutAddMenuEntry("Exit", 6);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();
	return 0;
}