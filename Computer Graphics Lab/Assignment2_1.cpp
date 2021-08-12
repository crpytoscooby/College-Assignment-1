/* Date 20 March 2021
Write-up - House
1. How to install Open-Gl?
2. OpenGl Architecture and Opengl libraries(three)
3. OpenGL command
4. Explain Program structure of OpenGL
5. What is call back function and explain some callback func and list temp
6. Opengl premitives
7. Expain glcolor, glclearcolor
8. Attach Basic Programs
9. mouse interfacing and keyboard interfacing
10. glcolorbufferbit
11. control function
*/

/*
Write-up - DDA
1. what is scan convertion of line
2. discuss abt the dda algo using slope cases and how those pixel will be selected
3. tracing of the algo(example)
4. validation of the dda program
5. how to create menu
6. glutcreatemenu and glutaddmenuentry
7. dda program and o/p
*/

/*
1. what is need for bla
2. actual algo explain
3. validation
4. comparison betw dda and bla
5. tracing it with eg
6. i/o validation
7.
*/
#include <iostream>
#include <math.h>
#include <GL/glut.h>
using namespace std;

double my_x1 = 0, my_y1 = 0, my_x2 = 0, my_y2 = 0, length = 0;
double x = 0, y = 0, dx = 0, dy = 0;

void plot(int x, int y)
{
    glVertex2i(x, y);
}

int sign(int num)
{
    if (num >= 0)
        return 1;
    else
        return -1;
}

void myInit(void)
{
    glClearColor(0, 0, 0, 0);
    glColor3f(1.0f, 1.0f, 1.0f);
    glPointSize(3.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-250.0, 250.0, -250.0, 250.0);
}

void myDisplay(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POINTS);
    for (int i = -250; i <= 250; i++)
    {
        if (i % 5 == 0)
        {
            plot(i, 0);
            plot(0, i);
        }
    }
    glEnd();
    glFlush();
}

void straightLine()
{
    x = 0, y = 0, dx = 0, dy = 0, length = 0;

    // step 1
    if (abs(my_x2 - my_x1) >= abs(my_y2 - my_y1))
        length = abs(my_x2 - my_x1);
    else
        length = abs(my_y2 - my_y1);

    // step 2
    dx = (my_x2 - my_x1) / (length * 1.0);
    dy = (my_y2 - my_y1) / (length * 1.0);

    // step 3
    x = my_x1 + 0.5 * sign(dx);
    y = my_y1 + 0.5 * sign(dy);

    glBegin(GL_POINTS);
    int i = 0;
    while (i <= length)
    {
        x = x + dx;
        y = y + dy;
        i++;
        plot(x, y);
    }
    glEnd();
    glFlush();
}

void dottedLine()
{
    x = 0, y = 0, dx = 0, dy = 0, length = 0;

    // step 1
    if (abs(my_x2 - my_x1) >= abs(my_y2 - my_y1))
        length = abs(my_x2 - my_x1);
    else
        length = abs(my_y2 - my_y1);

    // step 2
    dx = (my_x2 - my_x1) / (length * 1.0);
    dy = (my_y2 - my_y1) / (length * 1.0);

    // step 3
    x = my_x1 + 0.5 * sign(dx);
    y = my_y1 + 0.5 * sign(dy);

    glBegin(GL_POINTS);
    int i = 0;
    while (i <= length)
    {
        x = x + dx;
        y = y + dy;
        if (i % 5 == 0)
            plot(x, y);
        i++;
    }
    glEnd();
    glFlush();
}

void dashedLine()
{
    x = 0, y = 0, dx = 0, dy = 0, length = 0;

    // step 1
    if (abs(my_x2 - my_x1) >= abs(my_y2 - my_y1))
        length = abs(my_x2 - my_x1);
    else
        length = abs(my_y2 - my_y1);

    // step 2
    dx = (my_x2 - my_x1) / (length * 1.0);
    dy = (my_y2 - my_y1) / (length * 1.0);

    // step 3
    x = my_x1 + 0.5 * sign(dx);
    y = my_y1 + 0.5 * sign(dy);

    glBegin(GL_POINTS);
    int i = 0, count = 0;
    while (i <= length)
    {
        x = x + dx;
        y = y + dy;
        if (count < 5)
        {
            plot(x, y);
            count++;
        }
        else if (count >= 5 && count < 10)
        {
            count++;
        }
        else
        {
            count = 0;
        }
        i++;
    }
    glEnd();
    glFlush();
}

void myMenu(int choice)
{
    if (choice == 1)
    {
        cout << "Printing Straignt Line" << endl;
        straightLine();
    }
    else if (choice == 2)
    {
        cout << "Printing Dotted Line" << endl;
        dottedLine();
    }
    else if (choice == 3)
    {
        cout << "Printing Dashed Line" << endl;
        dashedLine();
    }
    else if (choice == 4)
    {
        cout << "Exiting..." << endl;
        exit(0);
    }
    else
        cout << "Invalid Input" << endl;
}

void takeInput()
{
    cout << "Enter the value of x1 : ";
    cin >> my_x1;
    cout << "Enter the value of y1 : ";
    cin >> my_y1;
    cout << "Enter the value of x2 : ";
    cin >> my_x2;
    cout << "Enter the value of y2 : ";
    cin >> my_y2;
}

int main(int argc, char **argv)
{
    takeInput();
    if (my_x1 == my_x2 && my_y1 == my_y2)
    {
        cout << "Invalid Input" << endl;
        cout << "\nAgain Enter the Values:" << endl;
        takeInput();
    }

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(100, 150);
    glutCreateWindow("Assignment 2");
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
