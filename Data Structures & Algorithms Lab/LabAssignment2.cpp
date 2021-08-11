#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node *next;
};

class List:public Node
{
    protected:
        Node *head, *temp;
    public:
        void create();
        void display();
};

void List::create()
{
    int n;
    cout<<"How many Nodes: "; 
    cin>>n;
    head = new Node;
    temp = head;
    cout<<"Enter the data:\n";
    cin>>head->data;
    for(int i=1;i<n;i++)
    {
        head->next = new Node;
        head = head->next;
        cin>>head->data;
    }
    head->next = NULL;
}

void List::display()
{
    head = temp;
    while(head!=NULL)
    {
        cout<<"Element: "<<head->data<<endl;
        head = head->next;
    }
}

int main()
{
    List obj;
    obj.create();
    obj.display();
    return 0;
}