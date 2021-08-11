#include <iostream>
using namespace std;
class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;
    int lTag, rTag; // lTag or rTag will be 1 if that node points to a child node and will be 0 if that node points to parent node

    // default constructor of class TreeNode
    TreeNode()
    {
        data = 0;
        left = right = NULL;
        lTag = rTag = 0;
    }
};
class ThreadedBinarySearchTree
{
public:
    TreeNode *dummyNode;
    TreeNode *leaf;
    // default constructor of class ThreadedBinarySearchTree
    ThreadedBinarySearchTree()
    {
        dummyNode = NULL;
        leaf = NULL;
    }
    void createTBST(int);
    void insert(TreeNode *, int);
    void displayInorder(TreeNode *);
    void displayPreorder(TreeNode *);
};
// this function is used to create a Threaded Binary Search Tree
void ThreadedBinarySearchTree::createTBST(int d)
{
    if (leaf == NULL) // first node
    {
        leaf = new TreeNode;
        dummyNode = new TreeNode;

        leaf->data = d;
        leaf->left = dummyNode;
        leaf->right = dummyNode;
        leaf->lTag = leaf->rTag = 0;
        dummyNode->data = 0;          // let say dummy node has data as 0
        dummyNode->left = leaf;       // pointind dummyNode's left to point to root node
        dummyNode->right = dummyNode; // pointing dummyNode's right to point to itself
        dummyNode->lTag = dummyNode->rTag = 1;
    }
    else
    {
        insert(leaf, d);
    }
}
// this function is used to insert element in Threaded Binary Search Tree at proper location
void ThreadedBinarySearchTree::insert(TreeNode *leaf, int d)
{
    TreeNode *temp = leaf;
    if (leaf->data == d)
    {
        cout << "No duplicates allowed! Try entering some other value\n ";
        return;
    }
    else
    {
        if (d < leaf->data)
        {
            if (leaf->lTag == 0)
            {
                temp = new TreeNode;
                temp->data = d;
                temp->left = leaf->left;
                temp->right = leaf;
                leaf->left = temp;
                leaf->lTag = 1;
                temp->lTag = temp->rTag = 0;
            }
            else
            {
                insert(leaf->left, d);
            }
        }
        else if (d > leaf->data)
        {
            if (leaf->rTag == 0)
            {
                temp = new TreeNode;
                temp->data = d;
                temp->left = leaf;
                temp->right = leaf->right;
                leaf->right = temp;
                leaf->rTag = 1;
                temp->lTag = temp->rTag = 0;
            }
            else
            {
                insert(leaf->right, d);
            }
        }
    }
}
// this function is used to display inorder traversal of Threaded Binary Search Tree
void ThreadedBinarySearchTree::displayInorder(TreeNode *leaf)
{
    TreeNode *temp = leaf;
    do
    {
        while (temp->lTag != 0)
        {
            temp = temp->left;
        }
        cout << temp->data << " ";
        while (temp->rTag == 0)
        {
            if (temp->right == dummyNode)
                return;
            temp = temp->right;
            cout << temp->data << " ";
        }
        temp = temp->right;
    } while (temp != dummyNode);
}
// this function is used to display preorder traversal of Threaded Binary Search Tree
void ThreadedBinarySearchTree::displayPreorder(TreeNode *temp)
{
    do
    {
        cout << temp->data << " ";
        while (temp->lTag != 0)
        {
            temp = temp->left;
            cout << temp->data << " ";
        }
        while (temp->rTag == 0)
        {
            if (temp->right == dummyNode)
                return;
            temp = temp->right;
        }
        temp = temp->right;
    } while (temp != dummyNode);
}
int main()
{
    ThreadedBinarySearchTree tree;
    int d, choice;
    cout << "Program to create a Threaded Binary Search Tree\n";
    do
    {
        cout << "1) Insert Node in Threaded Binary Search Tree\n";
        cout << "2) Display Inorder Traversal of Threaded Binary Search Tree\n";
        cout << "3) Display Preorder Traversal of Threaded Binary Search Tree\n";
        cout << "To exit press 0\n";
        cin >> choice;
        switch (choice)
        {
        case 0:
            cout << "\nExiting...";
            break;
        case 1:
            cout << "Enter Node Data: ";
            cin >> d;
            tree.createTBST(d);
            break;
        case 2:
            cout << "Inorder Traversal of Threaded Binary Search Tree : ";
            tree.displayInorder(tree.leaf);
            cout << endl;
            break;
        case 3:
            cout << "Preorder Traversal of Threaded Binary Search Tree : ";
            tree.displayPreorder(tree.leaf);
            cout << endl;
            break;
        default:
            cout << "Invalid Input!\n";
            break;
        }
        cout << endl;
    } while (choice != 0);
    return 0;
}
