#include<iostream>
using namespace std;

template <class T>
class Node
{
    public:
    T data;
    Node<T> *next;

    Node()
    {
        data = 0;
        next = NULL;
    }

    Node(T d)
    {
        data = d;
        next = NULL;
    }
};

template <class T>
class STACK
{
    public:
    Node<T> *SP;

    STACK()
    {
        SP = NULL;
    }

    bool isEmpty()
    {
        if(SP == NULL)
            return true;
        else
            return false;
    }

    T top()
    {
        if(isEmpty())
            cout<<"Stack is Empty"<<endl;
        else
            return SP->data;
    }

    void push(T);
    T pop();
};

template <class T>
void STACK<T>::push(T x)
{
    Node<T> *temp = new Node<T>;
    temp->data = x;
    temp->next = SP;
    SP = temp;
}

template <class T>
T STACK<T>::pop()
{
	Node<T> *temp = NULL;
    if(isEmpty())
    {
        cout<<"Stack is Empty"<<endl;
    }
    else
    {
        temp = SP;
        SP = SP->next;
    }
}
