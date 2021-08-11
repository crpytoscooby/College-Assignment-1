#include<iostream>
using namespace std;

int Partition(int A[], int low, int high)
{
	int pivot = A[low];
	int i = low + 1;
	int j = high;
	int temp;
	do
	{
		while(A[i] < pivot)
			i++;
		while(A[i] > pivot)
			j--;
			
		if(i < j)
		{
			temp = A[i];
			A[i] = A[j];
			A[j] = temp;
		}
	}while(i < j);	
	
	temp = A[low];
	A[low] = A[j];
	A[j] = temp;
	
	return j;
}

void QuickSort(int A[], int low, int high)
{
	if(low < high)
	{
		int partitionIndex = Partition(A, low, high);
		QuickSort(A, low, partitionIndex-1);
		QuickSort(A, partitionIndex+1, high);
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
    int n = 6;
    display(A, n);
    QuickSort(A, 0, n-1);
    display(A, n);
	return 0;
}
