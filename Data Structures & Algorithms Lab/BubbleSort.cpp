#include<iostream>
using namespace std;

void bubbleSort(int a[], int n)
{
	int flag = 0;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n-i-1; j++)
		{
			if(a[j] > a[j+1])
			{
				swap(a[j], a[j+1]);
				flag = 1;
			}
		}
		if(flag == 0)
			break;
	}	
}

void display(int a[], int n)
{
	for(int i = 0; i < n; i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
}

int main()
{
	int a[] = {12, 54, 65, 7, 23, 9};
    int n = 6;
	display(a, n);
	bubbleSort(a, n);
	display(a, n);
	return 0;
}
