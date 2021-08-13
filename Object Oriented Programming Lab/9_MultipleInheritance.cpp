#include<iostream>
using namespace std;

class Vehicle
{
    public:
        Vehicle()
        {
            cout<<"Constructor of Vehicle Class\n";
        }
        void info()
        {
            cout<<"This is Vehicle Class\n";
        }
};

class Wheels
{
    public:
        Wheels()
        {
            cout<<"Constructor of Wheels Class\n";
        }
        void info()
        {
            cout<<"This is Wheels Class\n";
        }
};

class Cars:public Vehicle,public Wheels
{
    public:
        Cars()
        {
            cout<<"Constructor of Cars Class\n";
        }
        void info()
        {
            cout<<"This is Cars Class\n";
        }
};
int main()
{
    Cars obj;
    obj.info();
    obj.Vehicle::info();
    obj.Wheels::info();
    return 0;
}