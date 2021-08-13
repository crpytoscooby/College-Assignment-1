#include<iostream>
#include<string>
using namespace std;

class Employee
{
	private:
		int emp_id,leaves;
		float salary;
		char emp_name[20],emp_designation[20];
	public:
		void getdata();
		void getleaves();
		void getsalary();
		void display();
};

void Employee::getdata()
{
	cout<<"Enter Employee Name: ";
	cin>>emp_name;
	cout<<"Enter Employee ID: ";
	cin>>emp_id;
	cout<<"Enter Employee Designation: ";
	cin>>emp_designation;
}

void Employee::getleaves()
{
	cout<<"Enter Number of Leaves: ";
	cin>>leaves;
}

void Employee::getsalary()
{
	float basic,da1,hra1;
	cout<<"Enter Basic Salary: ";
	cin>>basic;
	cout<<"Enter DA: ";
	cin>>da1;
	cout<<"Enter HRA: ";
	cin>>hra1;
	float da=(da1*basic)/100;
	float hra=(hra1*basic)/100;
	salary=basic+da+hra;
}

void Employee::display()
{
	cout<<"\nEmployee Name: "<<emp_name;
	cout<<"\nEmployee ID: "<<emp_id;
	cout<<"\nEmployee Leaves: "<<leaves;
	cout<<"\n\nTotal Salary of Employee: "<<salary<<" Rs\n";
}

int main()
{
	int n;
	cout<<"Enter Number of Employees: ";
	cin>>n;
	Employee obj[n];
	for(int i=0;i<n;i++)
	{
		obj[i].getdata();
		obj[i].getleaves();
		obj[i].getsalary();
		obj[i].display();	
	}
	return 0;
}
