#include <GL/glut.h>
#include <math.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int w = 640, h = 480;
int xi, y2, xf, yf, xx, yy;
float boundaryColor[3] = {0, 0, 0}, interiorColor[3] = {1, 1, 1}, fillColor[3] = {0, 0, 0};
float readPixel[3];

void setPixel(int x, int y)
{
  glColor3fv(fillColor);
  glBegin(GL_POINTS);
  glVertex2f(x, y);
  glEnd();
  glFlush();
}

void getPixel(int x, int y, float *color)
{

  glReadPixels(x, y, 1, 1, GL_RGB, GL_FLOAT, color);
}

int sign(float arg)
{
  if (arg < 0)
    return -1;
  else if (arg == 0)
    return 0;
  else
    return 1;
}

void Bre(int X1, int Y1, int X2, int Y2)
{
  float dx = abs(X2 - X1);
  float dy = abs(Y2 - Y1);
  int s1, s2, exc, y, x, i;
  float g, temp;
  x = X1;
  y = Y1;
  s1 = sign(X2 - X1);
  s2 = sign(Y2 - Y1);

  glBegin(GL_POINTS);

  if (dy > dx)
  {
    temp = dx;
    dx = dy;
    dy = temp;
    exc = 1;
  }
  else
  {
    exc = 0;
  }
  g = 2 * dy - dx;
  i = 1;
  while (i <= dx)
  {
    glVertex2d(x, y);
    while (g >= 0)
    {
      if (exc == 1)
        x = x + s1;
      else
        y = y + s2;
      g = g - 2 * dx;
    }
    if (exc == 1)
      y = y + s2;
    else
      x = x + s1;
    g = g + 2 * dy;
    i++;
  }
  glEnd();
  glFlush();
}
void rot(int x1, int y1, int x2, int y2)
{

  int xn1, yn1, xn2, yn2;
  xn1 = (x1 * cos(45)) + (y1 * sin(45));
  yn1 = (x1 * sin(45)) - (y1 * cos(45));
  xn2 = (x2 * cos(45)) + (y2 * sin(45));
  yn2 = (x2 * sin(45)) - (y2 * cos(45));
  Bre(xn1, yn1, xn2, yn2);
}

void display()
{
  glClearColor(1.0, 1.0, 1.0, 0.0);
  glColor3f(0.0, 1.0, 0.0);
  glLoadIdentity();
  gluOrtho2D(0, 640, 0, 480);

  glClear(GL_COLOR_BUFFER_BIT);
  Bre(200, 200, 300, 200);
  Bre(300, 200, 300, 300);
  Bre(300, 300, 200, 300);
  Bre(200, 300, 200, 200);

  Bre(200, 225, 300, 225);
  Bre(200, 250, 300, 250);
  Bre(200, 275, 300, 275);

  Bre(225, 200, 225, 300);
  Bre(250, 200, 250, 300);
  Bre(275, 200, 275, 300);

  rot(200, 200, 300, 200);
  rot(300, 200, 300, 300);
  rot(300, 300, 200, 300);
  rot(200, 300, 200, 200);

  rot(200, 225, 300, 225);
  rot(200, 250, 300, 250);
  rot(200, 275, 300, 275);

  rot(225, 200, 225, 300);
  rot(250, 200, 250, 300);
  rot(275, 200, 275, 300);
}
void floodFill(int x, int y)
{
  getPixel(x, y, readPixel);

  if (readPixel[0] == interiorColor[0] && readPixel[1] == interiorColor[1] && readPixel[2] == interiorColor[2])
  {
    setPixel(x, y);
    floodFill(x + 1, y);
    floodFill(x, y + 1);
    floodFill(x - 1, y);
    floodFill(x, y - 1);
    glFlush();
  }
}
void mouse(int btn, int state, int x, int y)
{
  if ((btn == GLUT_LEFT_BUTTON) && (state == GLUT_DOWN))
  {
    xi = x;
    y2 = 480 - y;
    floodFill(xi, y2);
  }
}

int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(w, h);
  glutCreateWindow("Chess");
  glutDisplayFunc(display);
  glutMouseFunc(mouse);
  glutMainLoop();
  return 0;
}
