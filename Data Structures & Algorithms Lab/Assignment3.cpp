#include<iostream>
using namespace std;

int main()
{
    int number,r,c=0,a[10];
    cout<<"Enter a number\n";
    cin>>number;
    while(number>0)
    {
        r=number%2;
        a[c]=r;
        number=number/2;
        c++;
    }
    cout<<"Number in binary format is\n";
    for(int i=c-1;i>=0;i--)
    {
        cout<<a[i];
    }
    return 0;
}