#include<iostream>
using namespace std;

class A
{
    public:
    void display()
    {
        cout<<"This is Class A\n";
    }
};

class B:public A
{
    public:
    void display()
    {
        cout<<"This is Class B\n";
    }
};

int main()
{
    B obj;
    obj.A::display();
    obj.display();
    return 0;
}