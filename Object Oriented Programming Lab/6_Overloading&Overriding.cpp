#include<iostream>
using namespace std;

class Base
{
    public:
        void add(int,int);		// Method Overloading or Function Overloading
        void add(int,float);	// Method Overloading or Function Overloading
        void add(float,float);	// Method Overloading or Function Overloading
        void display()          // Method Overriding or Function Overriding
        {
            cout<<"Base Class is called\n";
        }
};

void Base::add(int a,int b)     // Method Overloading or Function Overloading
{
    cout<<"Sum="<<a+b<<endl;
}

void Base::add(int a,float b)   // Method Overloading or Function Overloading
{
    cout<<"Sum="<<a+b<<endl;
}

void Base::add(float a,float b) // Method Overloading or Function Overloading
{
    cout<<"Sum="<<a+b<<endl;
}

class Derived:public Base
{
    public:
        void display()          // Method Overriding or Function Overriding
        {
            cout<<"Derived Class is called\n";
        }
};
int main()
{
    Base *bptr;
    Base b;
    bptr=&b;
    bptr->display();
    // Derived *ptr;
    Derived d;
    bptr=&d;
    bptr->display();
    Derived *dptr=&d;
    dptr->display();
    Base a;
    a.add(1,2);
    a.add(4,9.1f);
    a.add(3.142f,9.81f);
    return 0;
}