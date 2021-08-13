#include<iostream>
using namespace std;

class Item
{
    private:
        int a;
    public:
        Item()
        {
            a=0;
            cout<<"Default Constructor\n";
        }

        Item(int n)
        {
            a=n;
            cout<<"Parameterized Constructor\n";
        }

        Item(Item &obj)
        {
            a=obj.a;
            cout<<"Copy Constructor\n";
        }
};

int main()
{
    Item a;     // Default constructor is invoked
    Item b(2);  // Parameterized constructor is invoked
    Item c(a);  // Copy constructor is invoked
    Item d=b;   // Copy constructor is invoked
    return 0;
}