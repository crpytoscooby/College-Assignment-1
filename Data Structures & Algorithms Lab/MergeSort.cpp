#include<iostream>
using namespace std;

void merge(int a[], int low, int mid, int high)
{
	int i = low, j = mid + 1, k = low;
	int B[high - low + 1];
	
	while(i <= mid && j <= high)
	{
		if(a[i] < a[j])
		{
			B[k] = a[i];
			i++;
			k++;
		}
		else
		{
			B[k] = a[j];
			j++;
			k++;
		}
	}
	while(i <= mid)
	{
		B[k] = a[i];
		i++;
		k++;
	}
	while(j <= high)
	{
		B[k] = a[j];
		j++;
		k++;
	}
	
	for(int i = low; i <= high; i++)
	{
		a[i] = B[i];
	}
}

void MergeSort(int a[], int low, int high)
{
	int mid;
	if(low < high)
	{
		mid = (low + high) / 2;
		MergeSort(a, low, mid);
		MergeSort(a, mid + 1, high);
		merge(a, low, mid, high);
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
    MergeSort(A, 0, n-1);
    display(A, n);
	return 0;
}
