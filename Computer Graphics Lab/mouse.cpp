#include<iostream>
#include<GL/glut.h>
using namespace std;

GLint y1;
GLint x1;

void myInit(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.6, 0.6, 0.6, 0.0);
    glColor3f(0.0f, 0.0f, 1.0f);
    glPointSize(4.5);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}

void myMouse(int button, int state, int x, int y)
{
    if (state == GLUT_DOWN)
    {
        if (button == GLUT_LEFT_BUTTON)
        {
            x1 = x;
            y1 = y;
            glBegin(GL_LINES);
            glVertex2f(x, 480.0 - y);
            glVertex2f(x1 + 10, y1 + 10);
            glEnd();
            glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);
        }
        else if (button == GLUT_RIGHT_BUTTON)
        {
            glClearColor(1.0f, 0.0f, 0.0f, 0.0f);
            glClear(GL_COLOR_BUFFER_BIT);
            glFlush();
        }
    }
    return;
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 450);
    glutInitWindowPosition(100, 150);
    glutCreateWindow("Mouse");
    glutMouseFunc(myMouse);
    myInit();
    glutMainLoop();
    return 0;
}
