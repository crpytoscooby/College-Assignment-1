#include <iostream>
#include <GL/glut.h>

using namespace std;

void myLine(int x1, int y1, int x2, int y2)
{
    glColor3f(1.0, 1.0, 0.0);
    glLineWidth(2.0);
    // glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_LINES);
    glVertex2i(x1, y1);
    glVertex2i(x2, y2);
    glEnd();
    glFlush();
}

void myPolygon()
{
    glColor3f(1.0, 0.0, 0.0);
    glLineWidth(2.0);
    // glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POLYGON);
    glVertex2i(300, 300);
    glVertex2i(300, 400);
    glVertex2i(400, 400);
    glVertex2i(400, 300);
    glEnd();
    glFlush();
}

void myMenu(int choice)
{
    switch (choice)
    {
    case 1:
        cout << "Line" << endl;
        myLine(100, 100, 200, 200);
        break;
    case 2:
        cout << "Polygon" << endl;
        myPolygon();
        break;
    case 3:
        exit(0);
    default:
        break;
    }
}

void myInit(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 640.0, 0.0, 500.0);
    glClear(GL_COLOR_BUFFER_BIT);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Menu Creation Program");
    myInit();
    glutCreateMenu(myMenu);
    glutAddMenuEntry("Line", 1);
    glutAddMenuEntry("Polygon", 2);
    glutAddMenuEntry("Exit", 3);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    glutMainLoop();
    return 0;
}
