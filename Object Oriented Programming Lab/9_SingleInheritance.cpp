#include<iostream>
using namespace std;

class Vehicle   // Vehicle is a Base Class or a Parent Class
{
    public:
    Vehicle()
    {
        cout<<"Vehicle Class is Called\n";
    }
};

class Car:public Vehicle    // Car is a Derived Class or a Child Class
{
    public:
    Car()
    {
        cout<<"Car Class is Called\n";
    }
};

int main()
{
    Car obj;    // Creating the object of base class
    return 0;
}