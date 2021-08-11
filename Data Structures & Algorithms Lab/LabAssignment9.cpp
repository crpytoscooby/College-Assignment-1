#include<iostream>
using namespace std;

class Heap
{
public:
    void doReverse(int[], int, int);
    void generateHeap(int[], int);
    void displayTree(int[] , int);
    void maxHeap(int[], int, int);
    void minHeap(int[], int, int);
    void maxHeapSort(int[], int, int);
    void minHeapSort(int[], int, int);
};

// this function is used to reverse a string in some conditions
void Heap::doReverse(int heap[], int start, int end)
{
    if (start >= end)
        return;

    int temp = heap[start];
    heap[start] = heap[end];
    heap[end] = temp;

    doReverse(heap, start + 1, end - 1);
}

// this function will take input from the user to create a heap
void Heap::generateHeap(int heap[], int n)
{
    int d;
    cout << "Enter Data: ";
    cin >> heap[n];
}

// this funtion is used to display the heap
void Heap::displayTree(int heap[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << heap[i] << " ";
    }
    cout << endl;
}

// this function is used to create a max heap i.e. child elements should be smaller parent element
void Heap::maxHeap(int heap[], int n, int i)
{
    int temp = i;
    int leftChild = (i * 2) + 1;
    int rightChild = (i * 2) + 2;

    if (leftChild <= n - 1 && heap[leftChild] > heap[temp])
        temp = leftChild;
    if (rightChild <= n - 1 && heap[rightChild] > heap[temp])
        temp = rightChild;

    if (i != temp)
    {
        swap(heap[i], heap[temp]);
//      displayTree(heap, n);
        maxHeap(heap, n, temp);
    }
}

// this function is used to create a min heap i.e. child elements should be greater than parent element
void Heap::minHeap(int heap[], int n, int i)
{
    int temp = i;
    int leftChild = (2 * i) + 1;
    int rightChild = (2 * i) + 2;

    if (leftChild <= n - 1 && heap[leftChild] < heap[temp])
        temp = leftChild;
    if (rightChild <= n - 1 && heap[rightChild] < heap[temp])
        temp = rightChild;

    if (i != temp)
    {
        swap(heap[i], heap[temp]);
        minHeap(heap, n, temp);
    }
}

// this function is used to sort the element in ascending or descending order
void Heap::maxHeapSort(int heap[], int n, int choice)
{
    // the below for loop is used to create a maxHeap
    for (int i = (n / 2) - 1; i >= 0; i--)
    {
        maxHeap(heap, n, i);
    }

    // the below for loop is used to move the first element to the position of last element to sort them
    for (int i = n - 1; i >= 0; i--)
    {
        swap(heap[0], heap[i]);
        maxHeap(heap, i, 0);
        cout << "  ";
        displayTree(heap, n);
    }

    // by default when we apply heapSort on a max heap the elements will be sorted in ascending order,
    // so inorder to sort element in descending order we call this doReverse function.
    if (choice == 2)
        doReverse(heap, 0, n - 1);
}

// this function is used to sort the element in ascending or descending order
void Heap::minHeapSort(int heap[], int n, int choice)
{
    // the below for loop is used to create a minHeap
    for (int i = (n / 2) - 1; i >= 0; i--)
    {
        minHeap(heap, n, i);
    }

    // the below for loop is used to move the first element to the position of last element to sort them
    for (int i = n - 1; i >= 0; i--)
    {
        swap(heap[0], heap[i]);
        minHeap(heap, i, 0);
        cout << "  Pass by Pass: ";
        displayTree(heap, n);
    }

    // by default when we apply heapSort on a min heap the elements will be sorted in descending order,
    // so inorder to sort element in ascending order we call this doReverse function.
    if (choice == 1)
        doReverse(heap, 0, n - 1);
}

int main()
{
    Heap obj;
    int choice, choice2, n = 0;
    int heap[20];
    cout << "Heap Sort Program";
    do
    {
        cout << endl;
        cout << "1) Create Heap\n";
        cout << "2) Display Heap\n";
        cout << "3) Display Max Heap\n";
        cout << "4) Display Min Heap\n";
        cout << "5) Sort Max Heap\n";
        cout << "6) Sort Min Heap\n";
        cout << "Press 0 to exit\n";
        cout << "Enter your choice:\n";
        cin >> choice;
        switch (choice)
        {
        case 0:
            cout << "Exiting...";
            break;
        case 1:
            obj.generateHeap(heap, n);
            n++;
            cout << endl;
            break;
        case 2:
            cout << "Elements in Heap: ";
            obj.displayTree(heap, n);
            cout << endl;
            break;
        case 3:
            for (int i = (n / 2) - 1; i >= 0; i--)
                obj.maxHeap(heap, n, i);
            cout << "Elements in Heap: ";
            obj.displayTree(heap, n);
            cout << endl;
            break;
        case 4:
            for (int i = (n / 2) - 1; i >= 0; i--)
                obj.minHeap(heap, n, i);
            cout << "Elements in Heap: ";
            obj.displayTree(heap, n);
            cout << endl;
            break;
        case 5:
            cout << "  Sort in which order?\n";
            cout << "  1) Ascending Order\n";
            cout << "  2) Descending Order\n  ";
            cin >> choice2;
            obj.maxHeapSort(heap, n, choice2);
            cout << "  Sorted Heap: ";
            obj.displayTree(heap, n);
            cout << endl;
            break;
        case 6:
            cout << "  Sort in which order?\n";
            cout << "  1) Ascending Order\n";
            cout << "  2) Descending Order\n  ";
            cin >> choice2;
            obj.minHeapSort(heap, n, choice2);
            cout << "  Sorted Heap: ";
            obj.displayTree(heap, n);
            cout << endl;
            break;
        default:
            cout << "Invalid Input\n";
            break;
        }
    } while (choice != 0);

    return 0;
}

/*
OUTPUT:
Test Case 1: (from PPT)
Heap Sort Program
1) Create Heap
2) Display Heap
3) Display Max Heap
4) Display Min Heap
5) Sort Max Heap
6) Sort Min Heap
Press 0 to exit
Enter your choice:
1
Enter Data: 82


1) Create Heap
2) Display Heap
3) Display Max Heap
4) Display Min Heap
5) Sort Max Heap
6) Sort Min Heap
Press 0 to exit
Enter your choice:
1
Enter Data: 90


1) Create Heap
2) Display Heap
3) Display Max Heap
4) Display Min Heap
5) Sort Max Heap
6) Sort Min Heap
Press 0 to exit
Enter your choice:
1
Enter Data: 10


1) Create Heap
2) Display Heap
3) Display Max Heap
4) Display Min Heap
5) Sort Max Heap
6) Sort Min Heap
Press 0 to exit
Enter your choice:
1
Enter Data: 12


1) Create Heap
2) Display Heap
3) Display Max Heap
4) Display Min Heap
5) Sort Max Heap
6) Sort Min Heap
Press 0 to exit
Enter your choice:
1
Enter Data: 15


1) Create Heap
2) Display Heap
3) Display Max Heap
4) Display Min Heap
5) Sort Max Heap
6) Sort Min Heap
Press 0 to exit
Enter your choice:
1
Enter Data: 77


1) Create Heap
2) Display Heap
3) Display Max Heap
4) Display Min Heap
5) Sort Max Heap
6) Sort Min Heap
Press 0 to exit
Enter your choice:
1
Enter Data: 2


1) Create Heap
2) Display Heap
3) Display Max Heap
4) Display Min Heap
5) Sort Max Heap
6) Sort Min Heap
Press 0 to exit
Enter your choice:
1
Enter Data: 23


1) Create Heap
2) Display Heap
3) Display Max Heap
4) Display Min Heap
5) Sort Max Heap
6) Sort Min Heap
Press 0 to exit
Enter your choice:
2
Elements in Heap: 82 90 10 12 15 77 2 23


1) Create Heap
2) Display Heap
3) Display Max Heap
4) Display Min Heap
5) Sort Max Heap
6) Sort Min Heap
Press 0 to exit
Enter your choice:
3
Elements in Heap: 90 82 77 23 15 10 2 12


1) Create Heap
2) Display Heap
3) Display Max Heap
4) Display Min Heap
5) Sort Max Heap
6) Sort Min Heap
Press 0 to exit
Enter your choice:
4
Elements in Heap: 2 12 10 23 15 90 77 82


1) Create Heap
2) Display Heap
3) Display Max Heap
4) Display Min Heap
5) Sort Max Heap
6) Sort Min Heap
Press 0 to exit
Enter your choice:
5
  Sort in which order?
  1) Ascending Order
  2) Descending Order
  1
82 23 77 12 15 10 2 90
77 23 10 12 15 2 82 90
23 15 10 12 2 77 82 90
15 12 10 2 23 77 82 90
12 2 10 15 23 77 82 90
10 2 12 15 23 77 82 90
2 10 12 15 23 77 82 90
2 10 12 15 23 77 82 90
  Sorted Heap: 2 10 12 15 23 77 82 90


1) Create Heap
2) Display Heap
3) Display Max Heap
4) Display Min Heap
5) Sort Max Heap
6) Sort Min Heap
Press 0 to exit
Enter your choice:
5
  Sort in which order?
  1) Ascending Order
  2) Descending Order
  2
82 23 77 15 2 10 12 90
77 23 12 15 2 10 82 90
23 15 12 10 2 77 82 90
15 10 12 2 23 77 82 90
12 10 2 15 23 77 82 90
10 2 12 15 23 77 82 90
2 10 12 15 23 77 82 90
2 10 12 15 23 77 82 90
  Sorted Heap: 90 82 77 23 15 12 10 2


1) Create Heap
2) Display Heap
3) Display Max Heap
4) Display Min Heap
5) Sort Max Heap
6) Sort Min Heap
Press 0 to exit
Enter your choice:
6
  Sort in which order?
  1) Ascending Order
  2) Descending Order
  1
10 15 12 23 90 82 77 2
12 15 77 23 90 82 10 2
15 23 77 82 90 12 10 2
23 82 77 90 15 12 10 2
77 82 90 23 15 12 10 2
82 90 77 23 15 12 10 2
90 82 77 23 15 12 10 2
90 82 77 23 15 12 10 2
  Sorted Heap: 2 10 12 15 23 77 82 90


1) Create Heap
2) Display Heap
3) Display Max Heap
4) Display Min Heap
5) Sort Max Heap
6) Sort Min Heap
Press 0 to exit
Enter your choice:
6
  Sort in which order?
  1) Ascending Order
  2) Descending Order
  2
10 15 12 90 23 77 82 2
12 15 77 90 23 82 10 2
15 23 77 90 82 12 10 2
23 82 77 90 15 12 10 2
77 82 90 23 15 12 10 2
82 90 77 23 15 12 10 2
90 82 77 23 15 12 10 2
90 82 77 23 15 12 10 2
  Sorted Heap: 90 82 77 23 15 12 10 2


1) Create Heap
2) Display Heap
3) Display Max Heap
4) Display Min Heap
5) Sort Max Heap
6) Sort Min Heap
Press 0 to exit
Enter your choice:
0
Exiting...


Test Case 2:
Heap Sort Program
1) Create Heap
2) Display Heap
3) Display Max Heap
4) Display Min Heap
5) Sort Max Heap
6) Sort Min Heap
Press 0 to exit
Enter your choice:
1
Enter Data: 10


1) Create Heap
2) Display Heap
3) Display Max Heap
4) Display Min Heap
5) Sort Max Heap
6) Sort Min Heap
Press 0 to exit
Enter your choice:
1
Enter Data: 1


1) Create Heap
2) Display Heap
3) Display Max Heap
4) Display Min Heap
5) Sort Max Heap
6) Sort Min Heap
Press 0 to exit
Enter your choice:
1
Enter Data: 2


1) Create Heap
2) Display Heap
3) Display Max Heap
4) Display Min Heap
5) Sort Max Heap
6) Sort Min Heap
Press 0 to exit
Enter your choice:
1
Enter Data: 6


1) Create Heap
2) Display Heap
3) Display Max Heap
4) Display Min Heap
5) Sort Max Heap
6) Sort Min Heap
Press 0 to exit
Enter your choice:
1
Enter Data: 8


1) Create Heap
2) Display Heap
3) Display Max Heap
4) Display Min Heap
5) Sort Max Heap
6) Sort Min Heap
Press 0 to exit
Enter your choice:
1
Enter Data: 16


1) Create Heap
2) Display Heap
3) Display Max Heap
4) Display Min Heap
5) Sort Max Heap
6) Sort Min Heap
Press 0 to exit
Enter your choice:
1
Enter Data: 4


1) Create Heap
2) Display Heap
3) Display Max Heap
4) Display Min Heap
5) Sort Max Heap
6) Sort Min Heap
Press 0 to exit
Enter your choice:
1
Enter Data: 7


1) Create Heap
2) Display Heap
3) Display Max Heap
4) Display Min Heap
5) Sort Max Heap
6) Sort Min Heap
Press 0 to exit
Enter your choice:
1
Enter Data: 9


1) Create Heap
2) Display Heap
3) Display Max Heap
4) Display Min Heap
5) Sort Max Heap
6) Sort Min Heap
Press 0 to exit
Enter your choice:
1
Enter Data: 15


1) Create Heap
2) Display Heap
3) Display Max Heap
4) Display Min Heap
5) Sort Max Heap
6) Sort Min Heap
Press 0 to exit
Enter your choice:
2
Elements in Heap: 10 1 2 6 8 16 4 7 9 15


1) Create Heap
2) Display Heap
3) Display Max Heap
4) Display Min Heap
5) Sort Max Heap
6) Sort Min Heap
Press 0 to exit
Enter your choice:
3
Elements in Heap: 16 15 10 9 8 2 4 7 6 1


1) Create Heap
2) Display Heap
3) Display Max Heap
4) Display Min Heap
5) Sort Max Heap
6) Sort Min Heap
Press 0 to exit
Enter your choice:
4
Elements in Heap: 1 6 2 7 8 10 4 16 9 15


1) Create Heap
2) Display Heap
3) Display Max Heap
4) Display Min Heap
5) Sort Max Heap
6) Sort Min Heap
Press 0 to exit
Enter your choice:
5
  Sort in which order?
  1) Ascending Order
  2) Descending Order
  1
15 9 10 7 8 2 4 1 6 16
10 9 6 7 8 2 4 1 15 16
9 8 6 7 1 2 4 10 15 16
8 7 6 4 1 2 9 10 15 16
7 4 6 2 1 8 9 10 15 16
6 4 1 2 7 8 9 10 15 16
4 2 1 6 7 8 9 10 15 16
2 1 4 6 7 8 9 10 15 16
1 2 4 6 7 8 9 10 15 16
1 2 4 6 7 8 9 10 15 16
  Sorted Heap: 1 2 4 6 7 8 9 10 15 16


1) Create Heap
2) Display Heap
3) Display Max Heap
4) Display Min Heap
5) Sort Max Heap
6) Sort Min Heap
Press 0 to exit
Enter your choice:
5
  Sort in which order?
  1) Ascending Order
  2) Descending Order
  2
15 10 9 6 7 8 4 1 2 16
10 7 9 6 2 8 4 1 15 16
9 7 8 6 2 1 4 10 15 16
8 7 4 6 2 1 9 10 15 16
7 6 4 1 2 8 9 10 15 16
6 2 4 1 7 8 9 10 15 16
4 2 1 6 7 8 9 10 15 16
2 1 4 6 7 8 9 10 15 16
1 2 4 6 7 8 9 10 15 16
1 2 4 6 7 8 9 10 15 16
  Sorted Heap: 16 15 10 9 8 7 6 4 2 1


1) Create Heap
2) Display Heap
3) Display Max Heap
4) Display Min Heap
5) Sort Max Heap
6) Sort Min Heap
Press 0 to exit
Enter your choice:
6
  Sort in which order?
  1) Ascending Order
  2) Descending Order
  1
2 4 6 9 8 7 10 16 15 1
4 8 6 9 15 7 10 16 2 1
6 8 7 9 15 16 10 4 2 1
7 8 10 9 15 16 6 4 2 1
8 9 10 16 15 7 6 4 2 1
9 15 10 16 8 7 6 4 2 1
10 15 16 9 8 7 6 4 2 1
15 16 10 9 8 7 6 4 2 1
16 15 10 9 8 7 6 4 2 1
16 15 10 9 8 7 6 4 2 1
  Sorted Heap: 1 2 4 6 7 8 9 10 15 16


1) Create Heap
2) Display Heap
3) Display Max Heap
4) Display Min Heap
5) Sort Max Heap
6) Sort Min Heap
Press 0 to exit
Enter your choice:
6
  Sort in which order?
  1) Ascending Order
  2) Descending Order
  2
2 6 4 10 7 8 9 16 15 1
4 6 8 10 7 15 9 16 2 1
6 7 8 10 16 15 9 4 2 1
7 9 8 10 16 15 6 4 2 1
8 9 15 10 16 7 6 4 2 1
9 10 15 16 8 7 6 4 2 1
10 16 15 9 8 7 6 4 2 1
15 16 10 9 8 7 6 4 2 1
16 15 10 9 8 7 6 4 2 1
16 15 10 9 8 7 6 4 2 1
  Sorted Heap: 16 15 10 9 8 7 6 4 2 1


1) Create Heap
2) Display Heap
3) Display Max Heap
4) Display Min Heap
5) Sort Max Heap
6) Sort Min Heap
Press 0 to exit
Enter your choice:
0
Exiting...


Test Case 3:
Heap Sort Program
1) Create Heap
2) Display Heap
3) Display Max Heap
4) Display Min Heap
5) Sort Max Heap
6) Sort Min Heap
Press 0 to exit
Enter your choice:
1
Enter Data: 97


1) Create Heap
2) Display Heap
3) Display Max Heap
4) Display Min Heap
5) Sort Max Heap
6) Sort Min Heap
Press 0 to exit
Enter your choice:
1
Enter Data: 46


1) Create Heap
2) Display Heap
3) Display Max Heap
4) Display Min Heap
5) Sort Max Heap
6) Sort Min Heap
Press 0 to exit
Enter your choice:
1
Enter Data: 37


1) Create Heap
2) Display Heap
3) Display Max Heap
4) Display Min Heap
5) Sort Max Heap
6) Sort Min Heap
Press 0 to exit
Enter your choice:
1
Enter Data: 12


1) Create Heap
2) Display Heap
3) Display Max Heap
4) Display Min Heap
5) Sort Max Heap
6) Sort Min Heap
Press 0 to exit
Enter your choice:
1
Enter Data: 3


1) Create Heap
2) Display Heap
3) Display Max Heap
4) Display Min Heap
5) Sort Max Heap
6) Sort Min Heap
Press 0 to exit
Enter your choice:
1
Enter Data: 7


1) Create Heap
2) Display Heap
3) Display Max Heap
4) Display Min Heap
5) Sort Max Heap
6) Sort Min Heap
Press 0 to exit
Enter your choice:
1
Enter Data: 31


1) Create Heap
2) Display Heap
3) Display Max Heap
4) Display Min Heap
5) Sort Max Heap
6) Sort Min Heap
Press 0 to exit
Enter your choice:
1
Enter Data: 6


1) Create Heap
2) Display Heap
3) Display Max Heap
4) Display Min Heap
5) Sort Max Heap
6) Sort Min Heap
Press 0 to exit
Enter your choice:
1
Enter Data: 9


1) Create Heap
2) Display Heap
3) Display Max Heap
4) Display Min Heap
5) Sort Max Heap
6) Sort Min Heap
Press 0 to exit
Enter your choice:
2
Elements in Heap: 97 46 37 12 3 7 31 6 9


1) Create Heap
2) Display Heap
3) Display Max Heap
4) Display Min Heap
5) Sort Max Heap
6) Sort Min Heap
Press 0 to exit
Enter your choice:
3
Elements in Heap: 97 46 37 12 3 7 31 6 9


1) Create Heap
2) Display Heap
3) Display Max Heap
4) Display Min Heap
5) Sort Max Heap
6) Sort Min Heap
Press 0 to exit
Enter your choice:
4
Elements in Heap: 3 6 7 9 46 37 31 12 97


1) Create Heap
2) Display Heap
3) Display Max Heap
4) Display Min Heap
5) Sort Max Heap
6) Sort Min Heap
Press 0 to exit
Enter your choice:
5
  Sort in which order?
  1) Ascending Order
  2) Descending Order
  1
46 12 37 9 3 7 31 6 97
37 12 31 9 3 7 6 46 97
31 12 7 9 3 6 37 46 97
12 9 7 6 3 31 37 46 97
9 6 7 3 12 31 37 46 97
7 6 3 9 12 31 37 46 97
6 3 7 9 12 31 37 46 97
3 6 7 9 12 31 37 46 97
3 6 7 9 12 31 37 46 97
  Sorted Heap: 3 6 7 9 12 31 37 46 97


1) Create Heap
2) Display Heap
3) Display Max Heap
4) Display Min Heap
5) Sort Max Heap
6) Sort Min Heap
Press 0 to exit
Enter your choice:
5
  Sort in which order?
  1) Ascending Order
  2) Descending Order
  2
46 12 37 9 3 31 7 6 97
37 12 31 9 3 6 7 46 97
31 12 7 9 3 6 37 46 97
12 9 7 6 3 31 37 46 97
9 6 7 3 12 31 37 46 97
7 6 3 9 12 31 37 46 97
6 3 7 9 12 31 37 46 97
3 6 7 9 12 31 37 46 97
3 6 7 9 12 31 37 46 97
  Sorted Heap: 97 46 37 31 12 9 7 6 3


1) Create Heap
2) Display Heap
3) Display Max Heap
4) Display Min Heap
5) Sort Max Heap
6) Sort Min Heap
Press 0 to exit
Enter your choice:
6
  Sort in which order?
  1) Ascending Order
  2) Descending Order
  1
6 12 7 31 97 9 37 46 3
7 12 9 31 97 46 37 6 3
9 12 37 31 97 46 7 6 3
12 31 37 46 97 9 7 6 3
31 46 37 97 12 9 7 6 3
37 46 97 31 12 9 7 6 3
46 97 37 31 12 9 7 6 3
97 46 37 31 12 9 7 6 3
97 46 37 31 12 9 7 6 3
  Sorted Heap: 3 6 7 9 12 31 37 46 97


1) Create Heap
2) Display Heap
3) Display Max Heap
4) Display Min Heap
5) Sort Max Heap
6) Sort Min Heap
Press 0 to exit
Enter your choice:
6
  Sort in which order?
  1) Ascending Order
  2) Descending Order
  2
6 9 7 46 12 31 37 97 3
7 9 31 46 12 97 37 6 3
9 12 31 46 37 97 7 6 3
12 37 31 46 97 9 7 6 3
31 37 97 46 12 9 7 6 3
37 46 97 31 12 9 7 6 3
46 97 37 31 12 9 7 6 3
97 46 37 31 12 9 7 6 3
97 46 37 31 12 9 7 6 3
  Sorted Heap: 97 46 37 31 12 9 7 6 3


1) Create Heap
2) Display Heap
3) Display Max Heap
4) Display Min Heap
5) Sort Max Heap
6) Sort Min Heap
Press 0 to exit
Enter your choice:
0
Exiting...
*/

