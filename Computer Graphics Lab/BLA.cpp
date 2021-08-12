#include <iostream>
#include<math.h>
#include <GL/glut.h>
using namespace std;

int x = 0, y = 0, dx = 0, dy = 0, s1 = 0, s2 = 0, interchange = 0, e = 0;

void step1(int x1, int y1, int x2, int y2)
{
    x = x1;
    y = y1;

    dx = abs(x2 - x1);
    dy = abs(y2 - y1);

    if (x2 > x1)
        s1 = 1;
    else
        s1 = -1;

    if (y2 > y1)
        s2 = 1;
    else
        s2 = -1;
}

void step2()
{
    if (dy > dx)
    {
        swap(dy, dx);
        interchange = 1;
    }
    else
    {
        interchange = 0;
    }
}

void myInit(void)
{
    glClearColor(0, 0, 0, 0);
    glColor3f(1.0f, 1.0f, 0.0f);
    glPointSize(1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}

void myDisplay(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POINTS);
    int x1 = 10, y1 = 10, x2 = 100, y2 = 100;
    step1(x1, y1, x2, y2);
    step2();
    e = 2 * dy - dx;
    glVertex2i(x, y);
    for (int i = 1; i <= dx; i++)
    {
        while (e >= 0)
        {
            if (interchange == 1)
            {
                x = x + s1;
            }
            else
            {
                y = y + s2;
            }
            e = e - 2 * dx;
        }

        if (interchange == 1)
        {
            y = y + s2;
        }
        else
        {
            x = x + s1;
        }
        e = e + 2 * dy;

        glVertex2i(x, y);
    }
    glEnd();
    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(100, 150);
    glutCreateWindow("Pixel Plotting Program");
    glutDisplayFunc(myDisplay);
    myInit();
    glutMainLoop();
    return 0;
}