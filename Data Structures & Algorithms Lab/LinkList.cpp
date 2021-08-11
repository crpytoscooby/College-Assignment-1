#include<iostream>
//#include"LinkedList.h"
using namespace std;

class Node
{
public:
    int data;
    Node* next;
};

class LinkedList
{
private:
    Node *head, *temp;
public:
    void createList();
    void printList();
    void insertAtBeginning(int);
    void insertAfter(int, int);
    void insertAtEnd(int);
    void deleteNode(int);
};

void LinkedList::createList()
{
    int n;
    cout << "Enter How Many Nodes: ";
    cin >> n;
    cout << "Enter Element: ";
    head = new Node;
    temp = head;
    cin >> head->data;
    for (int i = 0; i < n - 1; i++)
    {
        head->next = new Node;
        head = head->next;
        cout << "Enter Element: ";
        cin >> head->data;
    }
    head->next = NULL;
}

void LinkedList::printList()
{
    head = temp;
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void LinkedList::insertAtBeginning(int d)
{
    head = temp;
    Node *newNode = new Node;
    newNode->data = d;
    newNode->next = head;
    head = newNode;
    temp = head;
}

void LinkedList::insertAfter(int d, int refNode)
{
    head = temp;
    while (head->data != refNode)
    {
        head = head->next;
        if (head == NULL)
        {
            cout << "Node Not Found!\n";
            return;
        }
    }

    Node *newNode = new Node;
    newNode->data = d;
    newNode->next = head->next;
    head->next = newNode;
}

void LinkedList::insertAtEnd(int d)
{
    head = temp;
    while (head->next != NULL)
    {
        head = head->next;
    }
    head->next = new Node;
    head->next->data = d;
    head->next->next = NULL;
}

void LinkedList::deleteNode(int d)
{
    Node *delNode = temp;
    if (delNode->data == d)
    {
        temp = delNode->next;
        delete delNode;
        return;
    }

    while (delNode->next->data != d)
    {
        delNode = delNode->next;
    }

    if (delNode == NULL)
        return;

    delNode->next = delNode->next->next;
}

int main()
{
    LinkedList obj;
    obj.createList();
    obj.printList();
    obj.insertAtBeginning(10);
    obj.printList();
    obj.insertAtEnd(11);
    obj.printList();
    obj.insertAfter(12, 3);
    obj.printList();
    obj.deleteNode(10);
    obj.printList();
    obj.deleteNode(12);
    obj.printList();
    return 0;
}
