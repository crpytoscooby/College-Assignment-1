#include<iostream>
using namespace std;

class Shape                         // Shape is an Abstract Class
{
    protected:
        int a, b;
    public:
        virtual void display() = 0; // Pure Virtual Function
};

class Rectangle:public Shape
{
    int area;
    public:
        Rectangle(int x, int y)
        {
            area = 0;
            a = x;
            b = y;
        }

        void display()
        {
            area = a * b;
            cout<<"Area of Rectangle = "<<area<<endl;
        }
};

class Triangle:public Shape
{
    float area;
    public:
        Triangle(int x, int y)
        {
            area = 0;
            a = x;
            b = y;
        }

        void display()
        {
            area = 0.5 * a * b;
            cout<<"Area of Triangle = "<<area<<endl;
        }
};

int main()
{
    int a, b;

    // for Rectangle
    cout<<"Enter Length and Breadth of Rectangle\n";
    cin>>a>>b;
    Rectangle r(a,b);

    // for Triangle
    cout<<"Enter Base and Height of Triangle\n";
    cin>>a>>b;
    Triangle t(a,b);

    Shape *tut[2];
    tut[0]=&r;
    tut[1]=&t;

    tut[0]->display();
    tut[1]->display();
    return 0;
}