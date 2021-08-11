#include<iostream>
using namespace std;

int main()
{
    int n,a,b,c,i;
    cout<<"Enter how many elements in an Fibonacci Series\n";
    cin>>n;
    a=0;
    b=1;
    cout<<"Even no. in the Fibonacci is\n";
    cout<<a;
    for(i=1;i<n-2;i++)
    {
        c=a+b;
        a=b;
        b=c;
        if(c%2==0)
        {
            cout<<" "<<c;
        }
    }
    return 0;
}