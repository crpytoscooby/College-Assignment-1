#include<iostream>
using namespace std;

int main()
{
    int *num = new int(5);  // Creating an int variable Dynamically
    cout<<"Number is "<<*num;
    delete num;             // Deleting an int variable
    int *arr = new int[3];  // Creating an Array Dynamically
    arr[0]=10;
    arr[1]=20;
    arr[2]=30;
    cout<<endl;
    cout<<"Value of arr[0] = "<<arr[0];
    cout<<"\nValue of arr[1] = "<<arr[1];
    cout<<"\nValue of arr[2] = "<<arr[2];
    delete[] arr;           // Deleting an integer Array
    return 0;
}
/*#include<iostream>
using namespace std;

int main()
{
    int *marks=new int[5],*sum=new int(0);  //Dynamic Memory Allocation
    cout<<"Enter marks of Five Subjects out of 25\n";
    for(int i=0;i<5;i++)
    {
        cout<<"Subject "<<(i+1)<<" ";
        cin>>marks[i];
    }
    for(int i=0;i<5;i++)
    {
        *sum=*sum+marks[i];   
    }
    cout<<"Percentage="<<(*sum*100)/125<<"%";
    delete marks;   //Deleting marks to release memory which is has been created by new operator
    delete sum;     //Deleting sum to release memory which is has been created by new operator
    return 0;
}*/
