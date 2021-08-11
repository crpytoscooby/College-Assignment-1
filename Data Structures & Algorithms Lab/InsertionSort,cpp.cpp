#include<iostream>
using namespace std;

void insertionSort(int a[], int n)
{
	int key, j;
	for(int i = 0; i < n; i++)
	{
		key = a[i];
		j = i-1;
		while(j >= 0 && a[j] > key)
		{
			a[j+1] = a[j];
			j--;	
		}
		a[j+1] = key;
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
	int A[] = {12, 54, 65, 7, 23, 9};
    int n = 6 ;
    display(A, n);
    insertionSort(A, n);
    display(A, n);
	return 0;
}
