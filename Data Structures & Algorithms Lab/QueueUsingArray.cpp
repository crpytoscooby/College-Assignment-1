#include<iostream>
using namespace std;
class Queue
{
private:
	int front;
	int rear;
	int arr[5];
	int size;
public:
	Queue()
	{
		front = -1;
		rear = -1;
		size = 5;
		for (int i = 0; i < size; i++)
		{
			arr[i] = 0;
		}
	}

	bool isEmpty()
	{
		if (front == -1 && rear == -1)
			return true;
		else
			return false;
	}

	bool isFull()
	{
		if (rear == size - 1)
			return true;
		else
			return false;
	}

	void enqueue(int value)
	{
		if (isFull())
		{
			cout << "Queue is Full\n";
			return;
		}
		else if (isEmpty())
		{
			front = rear = 0;
			arr[rear] = value;
		}
		else
		{
			rear++;
			arr[rear] = value;
		}
	}

	int dequeue()
	{
		int x = 0;
		if (isEmpty())
		{
			cout << "Queue is Empty" << endl;
			return x;
		}
		else if (rear == front)
		{
			x = arr[rear];
			arr[rear] = 0;
			rear = -1;
			front = -1;
			return x;
		}
		else
		{
			cout << "front value: " << front << endl;
			x = arr[front];
			arr[front] = 0;
			front++;
			return x;
		}
	}

	void display()
	{
		cout << "All Value of Queue\n";
		for (int i = 0; i < size; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}
};

int main()
{
	Queue q;
	int choice;
	do
	{
		cout << "1) Enqueue\n";
		cout << "2) Dequeue\n";
		cout << "3) Clear Screen\n";
		cout << "4) 0 to stop\n" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			int value;
			cout << "Enter a no ";
			cin >> value;
			q.enqueue(value);
			q.display();
			break;
		case 2:
			cout << "Dequeue\n";
			q.dequeue();
			q.display();
			break;
		case 3:
			system("cls");
			break;
		default:
			cout << "Invalid input";
			break;
		}
//		cout<<"Do you want to continue? 1/0";
//		cin>>choice;
	} while (choice != 0);
	return 0;
}
