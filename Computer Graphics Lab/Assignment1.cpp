#include <iostream>
#include <GL/glut.h>
using namespace std;

// shifting my co-ordinate system to (50, 50)
int newX = 50;
int newY = 50;

void myInit(void)
{
    glClearColor(1, 1, 0, 0);
    glColor3f(0.0f, 0.0f, 0.0f);
    glLineWidth(8.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 400.0, 0.0, 450.0);
}

void myDisplay(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    // Wall + Roof
    glBegin(GL_LINE_LOOP);
    glVertex2i(newX + 0, newY + 0);
    glVertex2i(newX + 0, newY + 200);
    glVertex2i(newX + 100, newY + 300);
    glVertex2i(newX + 200, newY + 200);
    glVertex2i(newX + 200, newY + 0);
    glEnd();

    // Roof Edge
    glBegin(GL_LINES);
    glVertex2i(newX - 20, newY - 20 + 200);
    glVertex2i(newX + 0, newY + 200);
    glVertex2i(newX + 200, newY + 200);
    glVertex2i(newX + 200 + 20, newY + 200 - 20);
    glEnd();

    // Door
    glBegin(GL_LINE_LOOP);
    glVertex2i(newX + 30, newY + 0);
    glVertex2i(newX + 30, newY + 125);
    glVertex2i(newX + 100, newY + 125);
    glVertex2i(newX + 100, newY + 0);
    glEnd();

    // Window
    glBegin(GL_LINE_LOOP);
    glVertex2i(newX + 130, newY + 110);
    glVertex2i(newX + 130, newY + 140);
    glVertex2i(newX + 170, newY + 140);
    glVertex2i(newX + 170, newY + 110);
    glEnd();

    // Chimney
    glBegin(GL_LINE_LOOP);
    glVertex2i(newX + 35, newY + 235);
    glVertex2i(newX + 35, newY + 300);
    glVertex2i(newX + 65, newY + 300);
    glVertex2i(newX + 65, newY + 265);
    glEnd();
    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(100, 150);
    glutCreateWindow("Assignment 1 - House");
    glutDisplayFunc(myDisplay);
    myInit();
    glutMainLoop();
    return 0;
}