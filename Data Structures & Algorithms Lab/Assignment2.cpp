#include<iostream>
using namespace std;

int main()
{
    int number,n=0,temp=0;
    cout<<"Enter a number\n";
    cin>>number;
    while(number>0)
    {
        temp=number%10;  //last digit of number
        n=(n*10)+temp;  //appending the number
        number=number/10;  //removing the last digit
    }
    cout<<"Number in reverse order is "<<n;
    return 0;
}