#include<iostream>
using namespace std;

class Student
{
    protected:
        int rollno;
        char name[20];
    public:
        void getdata();
        void display();
};

void Student::getdata()
{
    cout<<"Enter Student Name: ";
    cin>>name;
    cout<<"Enter Roll No: ";
    cin>>rollno;
}

void Student::display()
{
    cout<<"Student Name: "<<name<<endl;
    cout<<"Roll No: "<<rollno<<endl;
}

class Marks:public Student
{
    protected:
        int marks[5];
    public:
        void getdata();
        void display();
};

void Marks::getdata()
{
    cout<<"Enter Marks for 5 subjects\n";
    for(int i=0; i<5;i++)
    {
        cin>>marks[i];
    }
}

void Marks::display()
{
    cout<<"Marks of 5 Subject\n";
    for(int i=0; i<5;i++)
    {
        cout<<marks[i]<<"\t";
    }
    cout<<endl;
}

class Result:public Marks
{
    protected:
        float percentage=0;
    public:
        void display();
};

void Result::display()
{
    for(int i=0;i<5;i++)
    {
        percentage=marks[i]+percentage;
    }
    percentage=percentage/5.0;
    cout<<"Percentage = "<<percentage<<"%";
}

int main()
{
    Result obj;
    obj.Student::getdata();
    obj.Marks::getdata();
    obj.Student::display();
    obj.Marks::display();
    obj.display();
    return 0;
}