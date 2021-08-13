#include<iostream>
using namespace std;

class Shape
{
    protected:
        int a, b;
    public:
        Shape()
        {
            a = 0;
            b = 0;
        }

        void getdata(int x, int y)
        {
            a = x;
            b = y;
        }
};

class Rectangle:public Shape
{
    protected:
        int area;
    public:
        Rectangle()
        {
            area = 0;
        }

        void Area()
        {
            area = a * b;
            cout<<"Area of Rectangle = "<<area<<endl;
        }
};

class Triangle:public Shape
{
    private:
        float area;
    public:
        Triangle()
        {
            area = 0;
        }

        void Area()
        {
            area = 0.5 * a *b;
            cout<<"Area of Triangle = "<<area<<endl;   
        }
};

int main()
{
    Rectangle obj1;
    Triangle obj2;
    int a,b;
    cout<<"Enter Value of A and B\n";
    cin>>a>>b;
    obj1.getdata(a, b);
    obj2.getdata(a, b);
    obj1.Area();
    obj2.Area();
    return 0;
}