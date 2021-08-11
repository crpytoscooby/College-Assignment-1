#include<iostream>
using namespace std;

int main()
{
    int i=0,j=0,k,flag;
    char a[30],b[30];
    cout<<"Enter First String\n";
    cin>>a;
    cout<<"Enter Second String\n";
    cin>>b;
    while(a[i])
    {
        i++;
    }
    while(b[j])
    {
        j++;
    }
    if(i==j)
    {
        for(k=0;k<i;k++)
        {
            if(a[k]!=b[k])
            {
                flag=0;                
                break;
            }
            else
            {
                flag=1;
            }
            
        }
    }  
    else
    {
        cout<<"Entered two strings are Not Equal";
    }
    if(flag==1)
    {
        cout<<"Entered two strings are Equal";
    }  
    else if(flag==0)
    {
        cout<<"Entered two strings are Not Equal";
    }
    return 0;
}