#include<iostream>
using namespace std;

int main()
{
    int number,t,num,n=0;
    cout<<"Enter a number\n";
    cin>>number;
    num=number;
    while(num>0)
    {
        t=num%10;
        n=(n*10)+t;
        num=num/10;
    }
    if(number==n)
        cout<<"Entered Number is a Palindrome";
    else
        cout<<"Entered Number is not a Palindrome";
    return 0;
}