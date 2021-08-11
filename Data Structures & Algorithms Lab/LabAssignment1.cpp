#include<iostream>
using namespace std;

struct Student
{
	string name;
	int rollno;
	float sgpa;
};

class Students
{
public:
	void rollno	(struct Student[], int);
	void name(struct Student[], int);
	void tentoppers(struct Student[], int);
	void QuickSort(struct Student[], int, int);
	int Partition(struct Student[], int, int);
	void searchSGPA(struct Student[], int);
	void binarySearch(struct Student[], int);
};

void Students::rollno(struct Student s1[], int n)
{
	Student temp;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (s1[j].rollno > s1[j + 1].rollno)
			{
				temp = s1[j];
				s1[j] = s1[j + 1];
				s1[j + 1] = temp;
			}
		}
	}
	cout << endl << "Students name are as follows\n";
	cout << "RollNo\tName\tSGPA\n";
	for (int i = 0; i < n; i++)
	{
		cout << s1[i].rollno << "\t" << s1[i].name << "\t" << s1[i].sgpa << endl;
	}
}

void Students::name(struct Student s1[], int n)
{
	Student temp;
	for (int i = 1; i < n; i++)
	{
		int hole = i;
		string value = s1[hole].name;
		while (s1[hole - 1].name > value && hole > 0)
		{
			temp = s1[hole];
			s1[hole] = s1[hole - 1];
			s1[hole - 1] = temp;
			hole--;
		}
	}
	cout << endl << "Students name are as follows\n";
	cout << "RollNo\tName\tSGPA\n";
	for (int i = 0; i < n; i++)
	{
		cout << s1[i].rollno << "\t" << s1[i].name << "\t" << s1[i].sgpa << endl;
	}
}

void Students::tentoppers(struct Student s1[], int n)
{
	QuickSort(s1, 0, n);
	cout << "\nTop Ten Toppers are\n";
	cout << "RollNo\tName\tSGPA\n";
	for (int i = 0; i < 10; i++)
	{
		cout << s1[i].rollno << "\t" << s1[i].name << "\t" << s1[i].sgpa << endl;
	}
}

void Students::QuickSort(struct Student s1[], int start, int end)
{
	if (start < end)
	{
		int partition = Partition(s1, start, end);
		QuickSort(s1, start, partition - 1);
		QuickSort(s1, partition + 1, end);
	}
	else
		return;
}

int Students::Partition(struct Student s1[], int start, int end)
{
	float pivot = s1[end].sgpa;
	int pIndex = start;
	for (int i = start; i < end; i++)
	{
		if (s1[i].sgpa >= pivot)
		{
			swap(s1[i], s1[pIndex]);
			pIndex++;
		}
	}
	swap(s1[pIndex], s1[end]);
	return pIndex;
}

void Students::searchSGPA(struct Student s1[], int n)
{
	float search;
	int flag = 0;
	cout << "Enter SGPA to be searched: ";
	cin >> search;
	cout << endl << "Students haveing same SGPA are as follows\n";
	cout << "RollNo\tName\tSGPA\n";
	for (int i = 0; i < n; i++)
	{
		if (search == s1[i].sgpa)
		{
			flag = 1;
			cout << s1[i].rollno << "\t" << s1[i].name << "\t" << s1[i].sgpa << endl;
		}
	}
	if (flag == 0)
	{
		cout << "No Student having " << search << " SGPA Found !!!";
	}
}

void Students::binarySearch(struct Student s1[], int n)
{
	Student temp;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (s1[j].name > s1[j + 1].name)
			{
				temp = s1[j];
				s1[j] = s1[j + 1];
				s1[j + 1] = temp;
			}
		}
	}
	string search;
	cout << "Enter Name of the Student to be Searched (First Letter is Capital): ";
	cin >> search;
	int left = 0, right = n, flag = 0;
	cout << "RollNo\tName\tSGPA\n";
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (s1[mid].name == search)
		{
			cout << s1[mid].rollno << "\t" << s1[mid].name << "\t" << s1[mid].sgpa << endl;
			flag = 1;
			break;
		}
		else if (search > s1[mid].name)
		{
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}
	if (flag == 0)
		cout << "No Student having Name '" << search << "' Found !!!";
}


int main()
{
	cout << "Welcome User\n";
	int std;
	cout << "Enter total number of Students: ";
	cin >> std;
	Students obj;
	Student s[std];

	for (int i = 0; i < std; i++)
	{
		cout << "Enter Studends name: ";
		cin >> s[i].name;
		cout << "Enter Rollno: ";
		cin >> s[i].rollno;
		cout << "Enter SGPA: ";
		cin >> s[i].sgpa;
	}

	cout << "\nNice!! Good Going\n";
	int choice;
	char exit;
	do {
		cout << "\nHere are Some Options\n";
		cout << "1) Generate a list of Students according to the Roll No.\n";
		cout << "2) Generate a list of Students according to their Name is Ascending Order\n";
		cout << "3) Generate a list of top 10 Students\n";
		cout << "4) Search Number of Students having same SGPA\n";
		cout << "5) Search a Student in the enterd List\n";
		cout << "Enter your choice: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			obj.rollno(s, std);
			break;
		case 2:
			obj.name(s, std);
			break;
		case 3:
		{
			obj.tentoppers(s, std);
			break;
		}
		case 4:
			obj.searchSGPA(s, std);
			break;
		case 5:
			obj.binarySearch(s, std);
			break;
		default:
			cout << "Invalid Input\n";
		}
		cout << "Do You want to continue (Y/n)? ";
		cin >> exit;
	} while (exit == 'Y');
	return 0;
}
