#include<iostream>
using namespace std;
class Base
{
    public:
        virtual void display()
        {
            cout<<"Base Class\n";
        }
};

class Derived:public Base
{
    public:
        void display()
        {
            cout<<"Derived Class\n";
        }
};

int main()
{
    Base *bptr;
    Base objb;
    Derived objd;
    bptr=&objd;
    bptr->display();

    // Derived *dptr;
    // Base objb;
    // dptr = &objb;
    // dptr->display();
    return 0;
}
