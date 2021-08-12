#include <iostream>
#include <GL/glut.h>
#include <math.h>
using namespace std;

class Color
{
public:
    float r, g, b;
    Color()
    {
        r = g = b = 0;
    }

    Color(float r, float g, float b)
    {
        this->r = r;
        this->g = g;
        this->b = b;
    }
};

int WIDTH = 640, HEIGHT = 480;
Color boundaryColor(0.0, 0.0, 0.0);
Color interiorColor(1.0, 1.0, 1.0);
Color fillColor(187 / 255.0, 178 / 255.0, 233 / 255.0);
int side = 0, myChoice = 0;

class coordinate
{
public:
    int my_x;
    int my_y;
};

coordinate *obj;

Color getPixelColor(int x, int y)
{
    Color color;
    glReadPixels(x, y, 1, 1, GL_RGB, GL_FLOAT, &color);
    return color;
}

void setPixelColor(int x, int y, Color color)
{
    glColor3f(color.r, color.g, color.b);
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
    glFlush();
}

void myInit(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glColor3f(boundaryColor.r, boundaryColor.g, boundaryColor.b);
    glPointSize(1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, WIDTH, 0, HEIGHT);
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

void bresenhamAlgorithm(int x1, int y1, int x2, int y2)
{
    // Step 1
    int x = x1;
    int y = y1;
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int s1 = sign(x2 - x1);
    int s2 = sign(y2 - y1);
    int interchange = 0;

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
    glBegin(GL_POINTS);
    int e = (2 * dy) - dx;
    for (int i = 0; i <= dx; i++)
    {
        while (e >= 0)
        {
            if (interchange)
                x = x + s1;
            else
                y = y + s2;

            e = e - (2 * dx);
        }

        if (interchange)
            y = y + s2;
        else
            x = x + s1;

        e = e + (2 * dy);
        float r_random = (rand() % 11) / 10.0f;
        float g_random = (rand() % 11) / 10.0f;
        float b_random = (rand() % 11) / 10.0f;
        Color random(r_random, g_random, b_random);
        setPixelColor(x, y, random);
    }
    glEnd();
    glFlush();
}

void myDisplay(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    for (int i = 0; i < side; i++)
    {
        bresenhamAlgorithm(obj[i].my_x, obj[i].my_y, obj[(i + 1) % side].my_x, obj[(i + 1) % side].my_y);
    }
}

void floodFill4(int x, int y)
{
    Color readPixel = getPixelColor(x, y);
    if (readPixel.r == interiorColor.r && readPixel.g == interiorColor.g && readPixel.b == interiorColor.b)
    {
        setPixelColor(x, y, fillColor);
        floodFill4(x - 1, y);
        floodFill4(x, y + 1);
        floodFill4(x + 1, y);
        floodFill4(x, y - 1);
        glFlush();
    }
}

void floodFill8(int x, int y)
{
    Color readPixel = getPixelColor(x, y);
    if (readPixel.r == interiorColor.r && readPixel.g == interiorColor.g && readPixel.b == interiorColor.b)
    {
        setPixelColor(x, y, fillColor);
        floodFill8(x + 1, y);
        floodFill8(x + 1, y - 1);
        floodFill8(x, y - 1);
        floodFill8(x - 1, y - 1);
        floodFill8(x - 1, y);
        floodFill8(x - 1, y + 1);
        floodFill8(x, y + 1);
        floodFill8(x + 1, y + 1);
    }
}

void myMenu(int choice)
{
    myChoice = choice;
    if (choice == 3)
    {
        cout << "Exiting..." << endl;
        exit(0);
    }
}

void myMouse(int button, int state, int mouse_x, int mouse_y)
{
    if (state == GLUT_DOWN && button == GLUT_LEFT_BUTTON)
    {
        mouse_x = mouse_x;
        mouse_y = 480 - mouse_y;
        switch (myChoice)
        {
        case 1:
            cout << "Flood Fill 4 Way Method called" << endl;
            floodFill4(mouse_x, mouse_y);
            break;
        case 2:
            cout << "Flood Fill 8 Way Method called" << endl;
            floodFill8(mouse_x, mouse_y);
            break;
        default:
            cout << "Invlid Input" << endl;
            exit(0);
            break;
        }
    }
}

void getInput()
{
    cout << "Enter number of Edges: ";
    cin >> side;
    obj = new coordinate[side];
    for (int i = 0; i < side; i++)
    {
        cout << "Enter x and y: ";
        cin >> obj[i].my_x;
        cin >> obj[i].my_y;
    }
}

int main(int argc, char **argv)
{
    getInput();
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Assignment 4 - Flood Fill");
    glutMouseFunc(myMouse);
    glutCreateMenu(myMenu);
    glutAddMenuEntry("Flood Fill 4 Way Method", 1);
    glutAddMenuEntry("Flood Fill 8 Way Method", 2);
    glutAddMenuEntry("Exit", 3);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    glutDisplayFunc(myDisplay);
    myInit();
    glutMainLoop();
    return 0;
}