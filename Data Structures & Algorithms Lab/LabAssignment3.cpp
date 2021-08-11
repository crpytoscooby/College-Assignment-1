#include<iostream>
using namespace std;

struct Student	// structure of Student
{
	int srno;
	string name;
	float sgpa;
};

class Queue
{
private:
	int front, rear, record, size, entry;
	Student arr[6], finalList[100];
public:
	Queue(struct Student s)
	{
		record = 0;
		front = rear = -1;
		size = 6;
		entry = 0;
		for (int i = 0; i < size; i++)
		{
			arr[i].sgpa = 0;
			arr[i].name = "NULL";
		}
	}
	bool isEmpty();
	bool isFull();
	void enqueue(struct Student);
	void dequeue();
	void displayQueue(int);
	void displayMerit();
};

bool Queue::isEmpty()
{
	if (front == -1 && rear == -1)
		return true;
	else
		return false;
}

bool Queue::isFull()
{
	if ((rear + 1) % size == front)
		return true;
	else
		return false;
}

void Queue::enqueue(struct Student s)
{
	if (isFull())
	{
		cout << "Waiting List is full try after sometime\n";
		return;
	}
	else if (isEmpty())
	{
		front = rear = 0;
		arr[rear].srno = entry + 1;
		arr[rear].sgpa = s.sgpa;
		arr[rear].name = s.name;
	}
	else
	{
		rear = (rear + 1) % size;
		arr[rear].srno = entry + 1;
		arr[rear].sgpa = s.sgpa;
		arr[rear].name = s.name;
	}
	entry++;
}

void Queue::dequeue()
{
	if (isEmpty())
	{
		cout << "Waiting list is Empty Apply for Admission\n";
		return;
	}
	if (rear == front)
	{
		finalList[record] = arr[front];
		arr[front].sgpa = 0;
		arr[front].name = "NULL";
		rear = -1;
		front = -1;
	}
	else
	{
		finalList[record] = arr[front];
		arr[front].sgpa = 0;
		arr[front].name = "NULL";
		front = (front + 1) % size;
	}
	cout << "Admission allocated to " << finalList[record].name << endl;
	record++;
	return;
}

void Queue::displayQueue(int n = 6)	//	this fuction displays the element of queue
{
	int k = n - 1;
	cout << "\nWaiting List\n";
	if (k == 0)
	{
		for (int j = k; j < size; j++)
		{
			cout << "Name: " << arr[j].name << "\tSGPA: " << arr[j].sgpa << endl;
		}
	}
	else
	{
		for (int j = k; j < size; j++)
		{
			cout << "Name: " << arr[j].name << "\tSGPA: " << arr[j].sgpa << endl;
		}
		for (int j = 0; j < k; j++)
		{
			cout << "Name: " << arr[j].name << "\tSGPA: " << arr[j].sgpa << endl;
		}
	}
	cout << endl;
}

void Queue::displayMerit()		// this function displays the name and sgpa of students who got admitted
{
	cout << "\nCongratulation!!! Students\n";
	cout << "==================================================";
	cout << "\nSR NO.\t\tNAME\t\tSGPA\n";
	for (int j = 0; j < record; j++)
	{
		cout << finalList[j].srno << "\t\t" << finalList[j].name << "\t\t" << finalList[j].sgpa << endl;
	}
	cout << "==================================================\n";
}

int main()
{
	Student stud;	// creating stud of type Student
	Queue obj(stud);	// parameterized constuctor
	cout << "Welcome to Admission Portal of ABC College, Pune.\n";
	int choice, choice2, n;
	do
	{
		cout << "1) Apply for Admission\n";
		cout << "2) Admit the Candidate\n";
		cout << "3) Display Waiting List\n";
		cout << "To exit press 0 and Display Final Merit List\n";
		cout << "Enter your Choice: ";
		cin >> choice;
		switch (choice)
		{
		case 0:
			cout << "Exiting...\n\n";
			break;
		case 1:
			cout << "Enter Student Name: ";
			cin >> stud.name;
			cout << "Enter SGPA: ";
			cin >> stud.sgpa;
			obj.enqueue(stud);
			cout << "Display Waiting list from? \n1) Starting\n2) Intermediate\n3) End\n";
			cin >> choice2;
			switch (choice2)
			{
			case 1:
				obj.displayQueue(1);
				break;
			case 2:
				cout << "From which Number: ";
				cin >> n;
				obj.displayQueue(n);
				break;
			case 3:
				obj.displayQueue();
				break;
			default:
				cout << "Invalid Input";
				break;
			}
			break;
		case 2:
			obj.dequeue();
			cout << "Display Waiting list from? \n1) Starting\n2) Intermediate\n3) End\n";
			cin >> choice2;
			switch (choice2)
			{
			case 1:
				obj.displayQueue(1);
				break;
			case 2:
				cout << "From which Number: ";
				cin >> n;
				obj.displayQueue(n);
				break;
			case 3:
				obj.displayQueue();
				break;
			default:
				cout << "Invalid Input";
				break;
			}
			break;
		case 3:
			cout << "Display Waiting list from? \n1) Starting\n2) Intermediate\n3) End\n";
			cin >> choice2;
			switch (choice2)
			{
			case 1:
				obj.displayQueue(1);
				break;
			case 2:
				cout << "From which Number: ";
				cin >> n;
				obj.displayQueue(n);
				break;
			case 3:
				obj.displayQueue();
				break;
			default:
				cout << "Invalid Input";
				break;
			}
			break;
		default:
			cout << "Invalid Input\n";
			break;
		}
	} while (choice != 0);
	obj.displayMerit();
	return 0;
}

