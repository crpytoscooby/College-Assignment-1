#include<iostream>
using namespace std;

class A
{
    protected:
        int a;
    public:
        void getdata()
        {
            cout<<"Enter Value of A: ";
            cin>>a;
        }

        void display()
        {
            cout<<"The value of A: "<<a<<endl;
        }
};

class B:virtual public A
{
    protected:
        int b;
    public:
        void getdata()
        {
            cout<<"Enter Value of B: ";
            cin>>b;
        }

        void display()
        {
            cout<<"The value of B: "<<b<<endl;
        }
};

class C:virtual public A
{
    protected:
        int c;
    public:
        void getdata()
        {
            cout<<"Enter Value of C: ";
            cin>>c;
        }

        void display()
        {
            cout<<"The value of C: "<<c<<endl;
        }
};

class D:public B, public C
{
    private:
        int d;
    public:
        void getdata()
        {
           cout<<"Enter Value of D: ";
           cin>>d;
        }

        void display()
        {
            cout<<"The value of D: "<<d<<endl;
        }

        void multi()
        {
            A::getdata();
            B::getdata();
            C::getdata();
            getdata();
            A::display();
            B::display();
            C::display();
            display();
            cout<<"Multiplication of a,b,c,d is "<<a*b*c*d;
        }
};

int main()
{
    D obj;
    obj.multi();
    return 0;
}