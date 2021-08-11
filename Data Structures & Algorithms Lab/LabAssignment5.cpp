#include<iostream>
#include <stack>
using namespace std;

class TreeNode
{
	public:
	int data;
	TreeNode *left;
	TreeNode *right;
	
	TreeNode()
	{
		data = 0;
		left = NULL;
		right = NULL;
	}
	
	TreeNode(int d)
	{
		data = d;
		left = NULL;
		right = NULL;
	}	
};

class BinarySearchTree
{
	public:
	TreeNode *leaf;
	BinarySearchTree()
	{
	    leaf = NULL;
	}
	bool isEmpty();
	void createBST(int);
	void insertNode(int, TreeNode*);
	void searchNode(TreeNode*, int);
	TreeNode* deleteNode(TreeNode*, int);
	TreeNode* minValueNode(TreeNode*);
	void RecursiveTraversal(TreeNode*, int);
	void inorderNonRecursiveTraversal(TreeNode*);
	int displayHeight(TreeNode*);
	void createMirror(TreeNode*);
	TreeNode* createClone(TreeNode*);
};

// this function is use to whether the tree is empty or not 
bool BinarySearchTree::isEmpty()
{
	if(leaf == NULL)
		return true;
	else
		return false;
}


void BinarySearchTree::createBST(int d)
{
	TreeNode *temp = leaf;
	if(leaf == NULL)
	{
		leaf = new TreeNode;
		leaf->data = d;
		leaf->left = NULL;
		leaf->right = NULL;
		cout<<"Value Inserted as Root Node\n";
	}
	else
	{
		insertNode(d, temp);
	}
}

void BinarySearchTree::insertNode(int d, TreeNode* temp)
{
	if(temp->data == d)
	{
		cout<<"No Duplicate allowed! Try entering some other value.\n";
		return;
	}
	else
	{
		if(d < temp->data)
		{
			if(temp->left == NULL)
			{
				temp->left = new TreeNode;
				temp = temp->left;
				temp->data = d;
				temp->left = NULL;
				temp->right = NULL;
				cout<<"Value Inserted as Leaf Node\n";
			}	
			else
			{
				insertNode(d, temp->left);
			}
		}	
		else
		{
			if(temp->right == NULL)
			{
				temp->right = new TreeNode;
				temp = temp->right;
				temp->data = d;
				temp->left = NULL;
				temp->right = NULL;
				cout<<"Value Inserted as Right Node\n";
			}
			else
			{
				insertNode(d, temp->right);
			}
		}	
	}
}

void BinarySearchTree::inorderNonRecursiveTraversal(TreeNode *temp)
{
	stack<TreeNode*> s;
	while(temp != NULL || !s.empty())
	{
		if(temp->left == NULL && temp->right == NULL)
		{
			cout<<temp->data<<" ";
			temp = temp->right;
			if(!s.empty())
			{
				temp = s.top();
				s.pop();
				cout<<temp->data<<" ";
				temp = temp->right;
			}
		}
		else if(temp->left == NULL && temp->right != NULL)
		{
			cout<<temp->data<<" ";
			temp = temp->right;
		}
		else if((temp->left != NULL && temp->right != NULL) || (temp->left != NULL && temp->right == NULL))
		{
			s.push(temp);
			temp = temp->left;
		}	
	}	
}

void BinarySearchTree::searchNode(TreeNode* temp, int d)
{
	if(temp == NULL)
	{
		cout<<"Value not found\n";
		return;	
	}
	else if(temp->data == d)
	{
		cout<<"Value Found!\n";
		return;
	}
	else if(d < temp->data)
	{
		searchNode(temp->left, d);
	}
	else
	{
		searchNode(temp->right, d);
	}	
}

TreeNode* BinarySearchTree::deleteNode(TreeNode* root, int d)
{
	if(root == NULL)
	{
		return NULL;
	}
	else if(d < root->data)
	{
		root->left = deleteNode(root->left, d);
	}
	else if(d > root->data)
	{
		root->right = deleteNode(root->right, d);
	}
	else
	{
		if(root->left == NULL)
		{
			TreeNode* temp = root->right;
			delete root;
			return temp;
		}
		else if(root->right == NULL)
		{
			TreeNode* temp = root->left;
			delete root;
			return temp;
		}
		else
		{
			TreeNode* temp = minValueNode(root->right);
			root->data = temp->data;
			root->right = deleteNode(root->right, temp->data);
		}
	}
}

TreeNode* BinarySearchTree::minValueNode(TreeNode* root)
{
	TreeNode* current = root;
	while(current->left != NULL)
	{
		current = current->left;
	}
	return current;
}

void BinarySearchTree::RecursiveTraversal(TreeNode* leaf, int c)
{
	if(c == 1)	// Inorder
	{
		if(leaf == NULL)
			return;
		RecursiveTraversal(leaf->left, 1);
		cout<<leaf->data<<" ";
		RecursiveTraversal(leaf->right, 1);
	}
	else if(c == 2)	// Preorder
	{
		if(leaf == NULL)
			return;
		cout<<leaf->data<<" ";
		RecursiveTraversal(leaf->left, 2);
		RecursiveTraversal(leaf->right, 2);
	}
	else if(c == 3)	// Postorder
	{
		if(leaf == NULL)
			return;
		RecursiveTraversal(leaf->left, 3);
		RecursiveTraversal(leaf->right, 3);
		cout<<leaf->data<<" ";
	}
}

int BinarySearchTree::displayHeight(TreeNode* leaf)
{
	if(leaf == NULL)
		return 0;
	int lHeight = displayHeight(leaf->left);
	int rHeight = displayHeight(leaf->right);

	if(lHeight > rHeight)
		return (lHeight + 1);
	else
		return (rHeight + 1);
}

void BinarySearchTree::createMirror(TreeNode* current)
{
	if(current == NULL)
		return;
	TreeNode* temp;
	createMirror(current->left);
	createMirror(current->right);
	
	temp = current->left;
	current->left = current->right;
	current->right = temp;
}

TreeNode* BinarySearchTree::createClone(TreeNode* current)
{	
	if(current == NULL)
		return NULL;
		
	TreeNode* newTree = new TreeNode;
	newTree->data = current->data;
	newTree->left = createClone(current->left);
	newTree->right = createClone(current->right);
	return newTree;
}

int main()
{
	BinarySearchTree tree;
	int data, key, displayChoice;
	cout<<"Binary Search Tree Program\n";
    char choice;
	do
    {
    	cout<<"Perform the following operation\n";
    	cout<<"a) Insert Node in a Binary Search Tree\n";
    	cout<<"b) Delete Node in a Binary Search Tree\n";
    	cout<<"c) Search Node in a Binary Search Tree\n";
		cout<<"d) Display a Binary Search Tree\n";
		cout<<"e) Display Depth of the Binary Search Tree\n";
		cout<<"f) Create a mirror image of Binary Search Tree\n";
		cout<<"g) Create a Clone of existing Binary Search Tree\n";
    	cout<<"To exit press 0\n";
    	cin>>choice;
    	switch(choice)
    	{
    		case '0':
    			break;
    		case 'a':
    			cout<<"Enter Node Data: ";
    			cin>>data;
    			tree.createBST(data);
    			break;
    		case 'b':
    			cout<<"Enter Node to be deleted: ";
    			cin>>key;
    			tree.deleteNode(tree.leaf, key);
    			cout<<"Node with Value "<<key<<" Deleted Succesfully\n";
    			break;
    		case 'c':
    			cout<<"Enter Element you want to Search: ";
    			cin>>key;
				tree.searchNode(tree.leaf, key);
				break;
			case 'd':
				cout<<"1) Inorder Recursive Traversal\n";
				cout<<"2) PreorderRecursive Traversal\n";
				cout<<"3) Postorder Recursive Traversal\n";
				cout<<"4) Inorder Non-Recursive Traversal\n";
				cin>>displayChoice;
				switch(displayChoice)
				{
					case 1:
						tree.RecursiveTraversal(tree.leaf, displayChoice);
						break;
					case 2:
						tree.RecursiveTraversal(tree.leaf, displayChoice);
						break;
					case 3:
						tree.RecursiveTraversal(tree.leaf, displayChoice);
						break;
					case 4:
						tree.inorderNonRecursiveTraversal(tree.leaf);
						break;
					default:
						cout<<"Invalid Input\n";
						break;
				}
				break;
			case 'e':
				cout<<"Depth of the Binary Search Tree = "<<tree.displayHeight(tree.leaf)<<endl;
				break;
			case 'f':
				tree.createMirror(tree.leaf);
				break;
			case 'g':
				cout<<"Coping the contents of existing tree\n";
				cout<<"1) Inorder Recursive Traversal\n";
				cout<<"2) PreorderRecursive Traversal\n";
				cout<<"3) Postorder Recursive Traversal\n";
				cout<<"4) Inorder Non-Recursive Traversal\n";
				cin>>displayChoice;
				switch(displayChoice)
				{
					case 1:
						tree.RecursiveTraversal(tree.createClone(tree.leaf), displayChoice);
						break;
					case 2:
						tree.RecursiveTraversal(tree.createClone(tree.leaf), displayChoice);
						break;
					case 3:
						tree.RecursiveTraversal(tree.createClone(tree.leaf), displayChoice);
						break;
					case 4:
						tree.inorderNonRecursiveTraversal(tree.createClone(tree.leaf));
						break;
					default:
						cout<<"Invalid Input\n";
						break;
				}
				break;
    		default:
    			cout<<"Invalid Input\n";
    			break;
		}
		cout<<endl<<endl;
	}while(choice != '0');

	return 0;
}

/*
Binary Search Tree Program
Perform the following operation
a) Insert Node in a Binary Search Tree
b) Delete Node in a Binary Search Tree
c) Search Node in a Binary Search Tree
d) Display a Binary Search Tree
e) Display Depth of the Binary Search Tree
f) Create a mirror image of Binary Search Tree
g) Create a Clone of existing Binary Search Tree
To exit press 0
a
Enter Node Data: 45
Value Inserted as Root Node


Perform the following operation
a) Insert Node in a Binary Search Tree
b) Delete Node in a Binary Search Tree
c) Search Node in a Binary Search Tree
d) Display a Binary Search Tree
e) Display Depth of the Binary Search Tree
f) Create a mirror image of Binary Search Tree
g) Create a Clone of existing Binary Search Tree
To exit press 0
a
Enter Node Data: 26
Value Inserted as Leaf Node


Perform the following operation
a) Insert Node in a Binary Search Tree
b) Delete Node in a Binary Search Tree
c) Search Node in a Binary Search Tree
d) Display a Binary Search Tree
e) Display Depth of the Binary Search Tree
f) Create a mirror image of Binary Search Tree
g) Create a Clone of existing Binary Search Tree
To exit press 0
a
Enter Node Data: 68
Value Inserted as Right Node


Perform the following operation
a) Insert Node in a Binary Search Tree
b) Delete Node in a Binary Search Tree
c) Search Node in a Binary Search Tree
d) Display a Binary Search Tree
e) Display Depth of the Binary Search Tree
f) Create a mirror image of Binary Search Tree
g) Create a Clone of existing Binary Search Tree
To exit press 0
a
Enter Node Data: 7
Value Inserted as Leaf Node


Perform the following operation
a) Insert Node in a Binary Search Tree
b) Delete Node in a Binary Search Tree
c) Search Node in a Binary Search Tree
d) Display a Binary Search Tree
e) Display Depth of the Binary Search Tree
f) Create a mirror image of Binary Search Tree
g) Create a Clone of existing Binary Search Tree
To exit press 0
a
Enter Node Data: 33
Value Inserted as Right Node


Perform the following operation
a) Insert Node in a Binary Search Tree
b) Delete Node in a Binary Search Tree
c) Search Node in a Binary Search Tree
d) Display a Binary Search Tree
e) Display Depth of the Binary Search Tree
f) Create a mirror image of Binary Search Tree
g) Create a Clone of existing Binary Search Tree
To exit press 0
a
Enter Node Data: 51
Value Inserted as Leaf Node


Perform the following operation
a) Insert Node in a Binary Search Tree
b) Delete Node in a Binary Search Tree
c) Search Node in a Binary Search Tree
d) Display a Binary Search Tree
e) Display Depth of the Binary Search Tree
f) Create a mirror image of Binary Search Tree
g) Create a Clone of existing Binary Search Tree
To exit press 0
a
Enter Node Data: 75
Value Inserted as Right Node


Perform the following operation
a) Insert Node in a Binary Search Tree
b) Delete Node in a Binary Search Tree
c) Search Node in a Binary Search Tree
d) Display a Binary Search Tree
e) Display Depth of the Binary Search Tree
f) Create a mirror image of Binary Search Tree
g) Create a Clone of existing Binary Search Tree
To exit press 0
d
1) Inorder Recursive Traversal
2) PreorderRecursive Traversal
3) Postorder Recursive Traversal
4) Inorder Non-Recursive Traversal
1
7 26 33 45 51 68 75

Perform the following operation
a) Insert Node in a Binary Search Tree
b) Delete Node in a Binary Search Tree
c) Search Node in a Binary Search Tree
d) Display a Binary Search Tree
e) Display Depth of the Binary Search Tree
f) Create a mirror image of Binary Search Tree
g) Create a Clone of existing Binary Search Tree
To exit press 0
d
1) Inorder Recursive Traversal
2) PreorderRecursive Traversal
3) Postorder Recursive Traversal
4) Inorder Non-Recursive Traversal
2
45 26 7 33 68 51 75

Perform the following operation
a) Insert Node in a Binary Search Tree
b) Delete Node in a Binary Search Tree
c) Search Node in a Binary Search Tree
d) Display a Binary Search Tree
e) Display Depth of the Binary Search Tree
f) Create a mirror image of Binary Search Tree
g) Create a Clone of existing Binary Search Tree
To exit press 0
d
1) Inorder Recursive Traversal
2) PreorderRecursive Traversal
3) Postorder Recursive Traversal
4) Inorder Non-Recursive Traversal
3
7 33 26 51 75 68 45

Perform the following operation
a) Insert Node in a Binary Search Tree
b) Delete Node in a Binary Search Tree
c) Search Node in a Binary Search Tree
d) Display a Binary Search Tree
e) Display Depth of the Binary Search Tree
f) Create a mirror image of Binary Search Tree
g) Create a Clone of existing Binary Search Tree
To exit press 0
d
1) Inorder Recursive Traversal
2) PreorderRecursive Traversal
3) Postorder Recursive Traversal
4) Inorder Non-Recursive Traversal
4
7 26 33 45 51 68 75

Perform the following operation
a) Insert Node in a Binary Search Tree
b) Delete Node in a Binary Search Tree
c) Search Node in a Binary Search Tree
d) Display a Binary Search Tree
e) Display Depth of the Binary Search Tree
f) Create a mirror image of Binary Search Tree
g) Create a Clone of existing Binary Search Tree
To exit press 0
b
Enter Node to be deleted: 7
Node with Value 7 Deleted Succesfully


Perform the following operation
a) Insert Node in a Binary Search Tree
b) Delete Node in a Binary Search Tree
c) Search Node in a Binary Search Tree
d) Display a Binary Search Tree
e) Display Depth of the Binary Search Tree
f) Create a mirror image of Binary Search Tree
g) Create a Clone of existing Binary Search Tree
To exit press 0
d
1) Inorder Recursive Traversal
2) PreorderRecursive Traversal
3) Postorder Recursive Traversal
4) Inorder Non-Recursive Traversal
1
26 33 45 51 68 75

Perform the following operation
a) Insert Node in a Binary Search Tree
b) Delete Node in a Binary Search Tree
c) Search Node in a Binary Search Tree
d) Display a Binary Search Tree
e) Display Depth of the Binary Search Tree
f) Create a mirror image of Binary Search Tree
g) Create a Clone of existing Binary Search Tree
To exit press 0
a
Enter Node Data: 7
Value Inserted as Leaf Node


Perform the following operation
a) Insert Node in a Binary Search Tree
b) Delete Node in a Binary Search Tree
c) Search Node in a Binary Search Tree
d) Display a Binary Search Tree
e) Display Depth of the Binary Search Tree
f) Create a mirror image of Binary Search Tree
g) Create a Clone of existing Binary Search Tree
To exit press 0
d
1) Inorder Recursive Traversal
2) PreorderRecursive Traversal
3) Postorder Recursive Traversal
4) Inorder Non-Recursive Traversal
1
7 26 33 45 51 68 75

Perform the following operation
a) Insert Node in a Binary Search Tree
b) Delete Node in a Binary Search Tree
c) Search Node in a Binary Search Tree
d) Display a Binary Search Tree
e) Display Depth of the Binary Search Tree
f) Create a mirror image of Binary Search Tree
g) Create a Clone of existing Binary Search Tree
To exit press 0
b
Enter Node to be deleted: 45
Node with Value 45 Deleted Succesfully


Perform the following operation
a) Insert Node in a Binary Search Tree
b) Delete Node in a Binary Search Tree
c) Search Node in a Binary Search Tree
d) Display a Binary Search Tree
e) Display Depth of the Binary Search Tree
f) Create a mirror image of Binary Search Tree
g) Create a Clone of existing Binary Search Tree
To exit press 0
d
1) Inorder Recursive Traversal
2) PreorderRecursive Traversal
3) Postorder Recursive Traversal
4) Inorder Non-Recursive Traversal
1
7 26 33 51 68 75

Perform the following operation
a) Insert Node in a Binary Search Tree
b) Delete Node in a Binary Search Tree
c) Search Node in a Binary Search Tree
d) Display a Binary Search Tree
e) Display Depth of the Binary Search Tree
f) Create a mirror image of Binary Search Tree
g) Create a Clone of existing Binary Search Tree
To exit press 0
c
Enter Element you want to Search: 68
Value Found!


Perform the following operation
a) Insert Node in a Binary Search Tree
b) Delete Node in a Binary Search Tree
c) Search Node in a Binary Search Tree
d) Display a Binary Search Tree
e) Display Depth of the Binary Search Tree
f) Create a mirror image of Binary Search Tree
g) Create a Clone of existing Binary Search Tree
To exit press 0
e
Depth of the Binary Search Tree = 3


Perform the following operation
a) Insert Node in a Binary Search Tree
b) Delete Node in a Binary Search Tree
c) Search Node in a Binary Search Tree
d) Display a Binary Search Tree
e) Display Depth of the Binary Search Tree
f) Create a mirror image of Binary Search Tree
g) Create a Clone of existing Binary Search Tree
To exit press 0
f


Perform the following operation
a) Insert Node in a Binary Search Tree
b) Delete Node in a Binary Search Tree
c) Search Node in a Binary Search Tree
d) Display a Binary Search Tree
e) Display Depth of the Binary Search Tree
f) Create a mirror image of Binary Search Tree
g) Create a Clone of existing Binary Search Tree
To exit press 0
d
1) Inorder Recursive Traversal
2) PreorderRecursive Traversal
3) Postorder Recursive Traversal
4) Inorder Non-Recursive Traversal
1
75 68 51 33 26 7

Perform the following operation
a) Insert Node in a Binary Search Tree
b) Delete Node in a Binary Search Tree
c) Search Node in a Binary Search Tree
d) Display a Binary Search Tree
e) Display Depth of the Binary Search Tree
f) Create a mirror image of Binary Search Tree
g) Create a Clone of existing Binary Search Tree
To exit press 0
f


Perform the following operation
a) Insert Node in a Binary Search Tree
b) Delete Node in a Binary Search Tree
c) Search Node in a Binary Search Tree
d) Display a Binary Search Tree
e) Display Depth of the Binary Search Tree
f) Create a mirror image of Binary Search Tree
g) Create a Clone of existing Binary Search Tree
To exit press 0
d
1) Inorder Recursive Traversal
2) PreorderRecursive Traversal
3) Postorder Recursive Traversal
4) Inorder Non-Recursive Traversal
1
7 26 33 51 68 75

Perform the following operation
a) Insert Node in a Binary Search Tree
b) Delete Node in a Binary Search Tree
c) Search Node in a Binary Search Tree
d) Display a Binary Search Tree
e) Display Depth of the Binary Search Tree
f) Create a mirror image of Binary Search Tree
g) Create a Clone of existing Binary Search Tree
To exit press 0
g
Coping the contents of existing tree
1) Inorder Recursive Traversal
2) PreorderRecursive Traversal
3) Postorder Recursive Traversal
4) Inorder Non-Recursive Traversal
1
7 26 33 51 68 75

Perform the following operation
a) Insert Node in a Binary Search Tree
b) Delete Node in a Binary Search Tree
c) Search Node in a Binary Search Tree
d) Display a Binary Search Tree
e) Display Depth of the Binary Search Tree
f) Create a mirror image of Binary Search Tree
g) Create a Clone of existing Binary Search Tree
To exit press 0
0
*/
