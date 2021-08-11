#include<iostream>
#include"STACK.h"	// user defined stack (while saving the header file as UserDefinedStack.h and calling the functions it was showing an error)
#include<stack>		// system defined stack
using namespace std;

//template<class TN>
class treeNode
{
public:
	char data;
	treeNode *left;
	treeNode *right;

	treeNode()
	{
		data = 0;
		left = NULL;
		right = NULL;
	}

	treeNode(char d)
	{
		data = d;
		left = NULL;
		right = NULL;
	}
};

class expressionTree: public treeNode
{
public:
	treeNode *leaf;

	expressionTree()
	{
		leaf = NULL;
	}
	bool isOperator(char);
	bool isOperand(char);
	void expressionPostfix(string);
	void expressionPrefix(string);
	void recursiveTraversal(treeNode*, int);
	int nonRecursiveCase(treeNode*);
	void nonRecursiveInorder(treeNode*, int);
	void nonRecursivePreorder(treeNode*, int);
	void nonRecursivePostorder(treeNode*);
};

// this function checks for operator
bool expressionTree::isOperator(char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
		return true;
	else
		return false;
}

// this function checks for operand
bool expressionTree::isOperand(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
		return true;
	else
		return false;
}

// this function is used to generate an expression tree from postfix expression
void expressionTree::expressionPostfix(string postfix)
{
	stack<treeNode*> s;	// stack of type treeNode
	int i = 0;
	while (postfix[i] != '\0')
	{
		if (isOperand(postfix[i]))
		{
			leaf = new treeNode;
			leaf->data = postfix[i];
			leaf->left = NULL;
			leaf->right = NULL;
			s.push(leaf);
		}
		else if (isOperator(postfix[i]))
		{
			treeNode *op2 = s.top();
			s.pop();
			treeNode *op1 = s.top();
			s.pop();
			leaf = new treeNode;
			leaf->data = postfix[i];
			leaf->left = op1;
			leaf->right = op2;
			s.push(leaf);
		}
		i++;
	}
	cout << endl;
}

// this function is used to generate an expression tree from prefix expression
void expressionTree::expressionPrefix(string prefix)
{
	stack<treeNode*> s;
	int i = 0, n = prefix.length();
	for (int i = 0; i < n / 2; i++)
		swap(prefix[i], prefix[n - i - 1]);
	while (prefix[i] != '\0')
	{
		if (isOperand(prefix[i]))
		{
			leaf = new treeNode;
			leaf->data = prefix[i];
			leaf->left = NULL;
			leaf->right = NULL;
			s.push(leaf);
		}
		else if (isOperator(prefix[i]))
		{
			treeNode *op1 = s.top();
			s.pop();
			treeNode *op2 = s.top();
			s.pop();
			leaf = new treeNode;
			leaf->data = prefix[i];
			leaf->left = op1;
			leaf->right = op2;
			s.push(leaf);
		}
		i++;
	}
}

// this function is used to display inorder, preorder, postorder recursive tree traversal
void expressionTree::recursiveTraversal(treeNode* leaf, int n) // instead of writing 3 functions I have combined all types of traversal in one function
{
	if (n == 1)	// when n = 1 i.e. for inorder traversal
	{
		if (leaf == NULL)
			return;
		else
		{
			recursiveTraversal(leaf->left, 1);
			cout << leaf->data;
			recursiveTraversal(leaf->right, 1);
		}
	}
	else if (n == 2)	// when n = 2 i.e. for preorder traversal
	{
		if (leaf == NULL)
			return;
		else
		{
			cout << leaf->data;
			recursiveTraversal(leaf->left, 2);
			recursiveTraversal(leaf->right, 2);
		}
	}
	else if (n == 3)	// when n = 3 i.e. for postorder traversal
	{
		if (leaf == NULL)
			return;
		else
		{
			recursiveTraversal(leaf->left, 3);
			recursiveTraversal(leaf->right, 3);
			cout << leaf->data;
		}
	}
	else	// this block will never run
		cout << "Invalid Input";
}

int expressionTree::nonRecursiveCase(treeNode* c)
{
	if (c->left == NULL && c->right == NULL)
		return 1;
	else if (c->left == NULL && c->right != NULL)
		return 2;
	else if (c->left != NULL && c->right != NULL)
		return 3;
	else if (c->left != NULL && c->right == NULL)
		return 4;
}

// this function is used to print inorder non-recursive tree traversal
void expressionTree::nonRecursiveInorder(treeNode* current, int n)
{
	STACK<treeNode*> s;	// user defined stack
	/*int i = 0;
	while(i != n)
	{
		if(nonRecursiveCase(current) == 1)
		{
			cout<<current->data;
			if(!s.isEmpty())
			{
				current = s.top();
				s.pop();
				cout<<current->data;
				current = current->right;
			}
		}
		else if(nonRecursiveCase(current) == 2)
		{
			cout<<current->data;
			current = current->right;
		}
		else if(nonRecursiveCase(current) == 3 || nonRecursiveCase(current) == 4)
		{
			s.push(current);
			current = current->left;
		}
		i++;
	}*/
	while (current != NULL || !s.isEmpty())
	{
		if (current->left == NULL && current->right == NULL)
		{
			cout << current->data << " ";
			if (!s.isEmpty())
			{
				current = s.top();
				s.pop();
				cout << current->data << " ";
				current = current->right;
			}
		}
		else if (current->left == NULL && current->right != NULL)
		{
			cout << current->data << " ";
			current = current->right;
		}
		else if ((current->left != NULL && current->right != NULL) || (current->left != NULL && current->right == NULL))
		{
			s.push(current);
			current = current->left;
		}
	}
}

// this function is used to print preorder non-recursive tree traversal
void expressionTree::nonRecursivePreorder(treeNode* current, int n)
{
	STACK<treeNode*> s;
	int i = 0;
	while (i != n)
	{
		if (nonRecursiveCase(current) == 1)
		{
			cout << current->data;
			if (!s.isEmpty())
			{
				current = s.top();
				s.pop();
				current = current->right;
			}
		}
		else if (nonRecursiveCase(current) == 2)
		{
			cout << current->data;
			current = current->right;
		}
		else if (nonRecursiveCase(current) == 3 || nonRecursiveCase(current) == 4)
		{
			cout << current->data;
			s.push(current);
			current = current->left;
		}
		i++;
	}
}

// this function is used to print postorder non-recursive tree traversal
void expressionTree::nonRecursivePostorder(treeNode* current)
{
	STACK<treeNode*> s1, s2;
	s1.push(current);
	while (!s1.isEmpty())
	{
		if (nonRecursiveCase(s1.top()) == 1)
		{
			current = s1.top();
			s1.pop();
			s2.push(current);
		}
		else if (nonRecursiveCase(s1.top()) == 2)
		{
			current = s1.top();
			s1.pop();
			s2.push(current);
			s1.push(current->right);
		}
		else if (nonRecursiveCase(s1.top()) == 3 || nonRecursiveCase(s1.top()) == 4)
		{
			current = s1.top();
			s1.pop();
			s2.push(current);
			if (current->left != NULL)
			{
				s1.push(current->left);
			}
			if (current->right != NULL)
			{
				s1.push(current->right);
			}

		}
	}
	while (!s2.isEmpty())
	{
		cout << s2.top()->data;
		s2.pop();
	}
}

int main()
{
	expressionTree tree;
	int choice1, n;
	char choice2;
	string postfix, prefix;
	cout << "Program to Create an Expression Tree and Traverse it\n";
	do
	{
		cout << "Construct an Expression Tree from\n";
		cout << "1) Postfix\n";
		cout << "2) Prefix\n";
		cout << "Press 0 to exit\n";
		cin >> choice1;
		switch (choice1)
		{
		case 0:
			cout << "Exiting...";
			break;
		case 1:

			cout << "Enter Postfix Expression: ";
			cin >> postfix;
			tree.expressionPostfix(postfix);
			do
			{
				cout << "  Traverse Tree in\n";
				cout << "  a) Recursive Inorder\n";
				cout << "  b) Recursive Preorder\n";
				cout << "  c) Recursive Postoder\n";
				cout << "  d) Non-Recursive Inorder\n";
				cout << "  e) Non-Recursive Preorder\n";
				cout << "  f) Non-Recursive Postorder\n";
				cout << "  Press 'N' to exit\n  ";
				cin >> choice2;
				switch (choice2)
				{
				case 'a':
					cout << "  Inorder Traversal: ";
					tree.recursiveTraversal(tree.leaf, 1);
					cout << endl << endl;
					break;
				case 'b':
					cout << "  Preorder Traversal: ";
					tree.recursiveTraversal(tree.leaf, 2);
					cout << endl << endl;
					break;
				case 'c':
					cout << "  Postoder Traversal: ";
					tree.recursiveTraversal(tree.leaf, 3);
					cout << endl << endl;
					break;
				case 'd':
					n = postfix.length();
					cout << "  Non-Recursive Inorder Traversal: ";
					tree.nonRecursiveInorder(tree.leaf, n);
					cout << endl << endl;
					break;
				case 'e':
					n = postfix.length();
					cout << "  Non-Recursive Preorder Traversal: ";
					tree.nonRecursivePreorder(tree.leaf, n);
					cout << endl << endl;
					break;
				case 'f':
					cout << "  Non-Recursive Postorder Traversal: ";
					tree.nonRecursivePostorder(tree.leaf);
					cout << endl << endl;
					break;
				case 'N':
					cout << "  Exiting...\n\n";
					break;
				default:
					cout << "  Invalid Input\n\n";
					break;
				}
			} while (choice2 != 'N');
			break;
		case 2:
			cout << "Enter Prefix Expression: ";
			cin >> prefix;
			tree.expressionPrefix(prefix);
			do
			{
				cout << "  Traverse Tree in\n";
				cout << "  a) Recursive Inorder\n";
				cout << "  b) Recursive Preorder\n";
				cout << "  c) Recursive Postoder\n";
				cout << "  d) Non-Recursive Inorder\n";
				cout << "  e) Non-Recursive Preorder\n";
				cout << "  f) Non-Recursive Postorder\n";
				cout << "  To exit press 'N'\n  ";
				cin >> choice2;
				switch (choice2)
				{
				case 'a':
					cout << "  Inorder Traversal: ";
					tree.recursiveTraversal(tree.leaf, 1);
					cout << endl << endl;
					break;
				case 'b':
					cout << "  Preorder Traversal: ";
					tree.recursiveTraversal(tree.leaf, 2);
					cout << endl << endl;
					break;
				case 'c':
					cout << "  Postoder Traversal: ";
					tree.recursiveTraversal(tree.leaf, 3);
					cout << endl << endl;
					break;
				case 'd':
					n = postfix.length();
					cout << "  Non-Recursive Inorder Traversal: ";
					tree.nonRecursiveInorder(tree.leaf, n);
					cout << endl << endl;
					break;
				case 'e':
					n = postfix.length();
					cout << "  Non-Recursive Preorder Traversal: ";
					tree.nonRecursivePreorder(tree.leaf, n);
					cout << endl << endl;
					break;
				case 'f':
					cout << "  Non-Recursive Postorder Traversal: ";
					tree.nonRecursivePostorder(tree.leaf);
					cout << endl << endl;
					break;
				case 'N':
					cout << "  Exiting...\n\n";
					break;
				default:
					cout << "  Invalid Input\n\n";
					break;
				}
			} while (choice2 != 'N');
			break;
		default:
			cout << "Invalid Input\n";
			break;
		}
	} while (choice1 != 0);
	return 0;
}

/*
OUTPUT
Test Case 1:
Program to Create an Expression Tree and Traverse it
Construct an Expression Tree from
1) Postfix
2) Prefix
Press 0 to exit
1
Enter Postfix Expression: 437*+534+/-6+

  Traverse Tree in
  a) Recursive Inorder
  b) Recursive Preorder
  c) Recursive Postoder
  d) Non-Recursive Inorder
  e) Non-Recursive Preorder
  f) Non-Recursive Postorder
  Press 'N' to exit
  a
  Inorder Traversal: 4+3*7-5/3+4+6

  Traverse Tree in
  a) Recursive Inorder
  b) Recursive Preorder
  c) Recursive Postoder
  d) Non-Recursive Inorder
  e) Non-Recursive Preorder
  f) Non-Recursive Postorder
  Press 'N' to exit
  b
  Preorder Traversal: +-+4*37/5+346

  Traverse Tree in
  a) Recursive Inorder
  b) Recursive Preorder
  c) Recursive Postoder
  d) Non-Recursive Inorder
  e) Non-Recursive Preorder
  f) Non-Recursive Postorder
  Press 'N' to exit
  c
  Postoder Traversal: 437*+534+/-6+

  Traverse Tree in
  a) Recursive Inorder
  b) Recursive Preorder
  c) Recursive Postoder
  d) Non-Recursive Inorder
  e) Non-Recursive Preorder
  f) Non-Recursive Postorder
  Press 'N' to exit
  d
  Non-Recursive Inorder Traversal: 4+3*7-5/3+4+6

  Traverse Tree in
  a) Recursive Inorder
  b) Recursive Preorder
  c) Recursive Postoder
  d) Non-Recursive Inorder
  e) Non-Recursive Preorder
  f) Non-Recursive Postorder
  Press 'N' to exit
  e
  Non-Recursive Preorder Traversal: +-+4*37/5+346

  Traverse Tree in
  a) Recursive Inorder
  b) Recursive Preorder
  c) Recursive Postoder
  d) Non-Recursive Inorder
  e) Non-Recursive Preorder
  f) Non-Recursive Postorder
  Press 'N' to exit
  f
  Non-Recursive Postorder Traversal: 437*+534+/-6+

  Traverse Tree in
  a) Recursive Inorder
  b) Recursive Preorder
  c) Recursive Postoder
  d) Non-Recursive Inorder
  e) Non-Recursive Preorder
  f) Non-Recursive Postorder
  Press 'N' to exit
  N
  Exiting...

Construct an Expression Tree from
1) Postfix
2) Prefix
Press 0 to exit
2
Enter Prefix Expression: +-+4*37/5+346
  Traverse Tree in
  a) Recursive Inorder
  b) Recursive Preorder
  c) Recursive Postoder
  d) Non-Recursive Inorder
  e) Non-Recursive Preorder
  f) Non-Recursive Postorder
  To exit press 'N'
  a
  Inorder Traversal: 4+3*7-5/3+4+6

  Traverse Tree in
  a) Recursive Inorder
  b) Recursive Preorder
  c) Recursive Postoder
  d) Non-Recursive Inorder
  e) Non-Recursive Preorder
  f) Non-Recursive Postorder
  To exit press 'N'
  b
  Preorder Traversal: +-+4*37/5+346

  Traverse Tree in
  a) Recursive Inorder
  b) Recursive Preorder
  c) Recursive Postoder
  d) Non-Recursive Inorder
  e) Non-Recursive Preorder
  f) Non-Recursive Postorder
  To exit press 'N'
  c
  Postoder Traversal: 437*+534+/-6+

  Traverse Tree in
  a) Recursive Inorder
  b) Recursive Preorder
  c) Recursive Postoder
  d) Non-Recursive Inorder
  e) Non-Recursive Preorder
  f) Non-Recursive Postorder
  To exit press 'N'
  d
  Non-Recursive Inorder Traversal: 4+3*7-5/3+4+6

  Traverse Tree in
  a) Recursive Inorder
  b) Recursive Preorder
  c) Recursive Postoder
  d) Non-Recursive Inorder
  e) Non-Recursive Preorder
  f) Non-Recursive Postorder
  To exit press 'N'
  e
  Non-Recursive Preorder Traversal: +-+4*37/5+346

  Traverse Tree in
  a) Recursive Inorder
  b) Recursive Preorder
  c) Recursive Postoder
  d) Non-Recursive Inorder
  e) Non-Recursive Preorder
  f) Non-Recursive Postorder
  To exit press 'N'
  f
  Non-Recursive Postorder Traversal: 437*+534+/-6+

  Traverse Tree in
  a) Recursive Inorder
  b) Recursive Preorder
  c) Recursive Postoder
  d) Non-Recursive Inorder
  e) Non-Recursive Preorder
  f) Non-Recursive Postorder
  To exit press 'N'
  N
  Exiting...

Construct an Expression Tree from
1) Postfix
2) Prefix
Press 0 to exit
0
Exiting...



Test Case 2:
Program to Create an Expression Tree and Traverse it
Construct an Expression Tree from
1) Postfix
2) Prefix
Press 0 to exit
1
Enter Postfix Expression: AB-CEF/*+

  Traverse Tree in
  a) Recursive Inorder
  b) Recursive Preorder
  c) Recursive Postoder
  d) Non-Recursive Inorder
  e) Non-Recursive Preorder
  f) Non-Recursive Postorder
  Press 'N' to exit
  a
  Inorder Traversal: A-B+C*E/F

  Traverse Tree in
  a) Recursive Inorder
  b) Recursive Preorder
  c) Recursive Postoder
  d) Non-Recursive Inorder
  e) Non-Recursive Preorder
  f) Non-Recursive Postorder
  Press 'N' to exit
  b
  Preorder Traversal: +-AB*C/EF

  Traverse Tree in
  a) Recursive Inorder
  b) Recursive Preorder
  c) Recursive Postoder
  d) Non-Recursive Inorder
  e) Non-Recursive Preorder
  f) Non-Recursive Postorder
  Press 'N' to exit
  c
  Postoder Traversal: AB-CEF/*+

  Traverse Tree in
  a) Recursive Inorder
  b) Recursive Preorder
  c) Recursive Postoder
  d) Non-Recursive Inorder
  e) Non-Recursive Preorder
  f) Non-Recursive Postorder
  Press 'N' to exit
  d
  Non-Recursive Inorder Traversal: A-B+C*E/F

  Traverse Tree in
  a) Recursive Inorder
  b) Recursive Preorder
  c) Recursive Postoder
  d) Non-Recursive Inorder
  e) Non-Recursive Preorder
  f) Non-Recursive Postorder
  Press 'N' to exit
  e
  Non-Recursive Preorder Traversal: +-AB*C/EF

  Traverse Tree in
  a) Recursive Inorder
  b) Recursive Preorder
  c) Recursive Postoder
  d) Non-Recursive Inorder
  e) Non-Recursive Preorder
  f) Non-Recursive Postorder
  Press 'N' to exit
  f
  Non-Recursive Postorder Traversal: AB-CEF/*+

  Traverse Tree in
  a) Recursive Inorder
  b) Recursive Preorder
  c) Recursive Postoder
  d) Non-Recursive Inorder
  e) Non-Recursive Preorder
  f) Non-Recursive Postorder
  Press 'N' to exit
  N
  Exiting...

Construct an Expression Tree from
1) Postfix
2) Prefix
Press 0 to exit
2
Enter Prefix Expression: +-AB*C/EF
  Traverse Tree in
  a) Recursive Inorder
  b) Recursive Preorder
  c) Recursive Postoder
  d) Non-Recursive Inorder
  e) Non-Recursive Preorder
  f) Non-Recursive Postorder
  To exit press 'N'
  a
  Inorder Traversal: A-B+C*E/F

  Traverse Tree in
  a) Recursive Inorder
  b) Recursive Preorder
  c) Recursive Postoder
  d) Non-Recursive Inorder
  e) Non-Recursive Preorder
  f) Non-Recursive Postorder
  To exit press 'N'
  b
  Preorder Traversal: +-AB*C/EF

  Traverse Tree in
  a) Recursive Inorder
  b) Recursive Preorder
  c) Recursive Postoder
  d) Non-Recursive Inorder
  e) Non-Recursive Preorder
  f) Non-Recursive Postorder
  To exit press 'N'
  c
  Postoder Traversal: AB-CEF/*+

  Traverse Tree in
  a) Recursive Inorder
  b) Recursive Preorder
  c) Recursive Postoder
  d) Non-Recursive Inorder
  e) Non-Recursive Preorder
  f) Non-Recursive Postorder
  To exit press 'N'
  d
  Non-Recursive Inorder Traversal: A-B+C*E/F

  Traverse Tree in
  a) Recursive Inorder
  b) Recursive Preorder
  c) Recursive Postoder
  d) Non-Recursive Inorder
  e) Non-Recursive Preorder
  f) Non-Recursive Postorder
  To exit press 'N'
  e
  Non-Recursive Preorder Traversal: +-AB*C/EF

  Traverse Tree in
  a) Recursive Inorder
  b) Recursive Preorder
  c) Recursive Postoder
  d) Non-Recursive Inorder
  e) Non-Recursive Preorder
  f) Non-Recursive Postorder
  To exit press 'N'
  f
  Non-Recursive Postorder Traversal: AB-CEF/*+

  Traverse Tree in
  a) Recursive Inorder
  b) Recursive Preorder
  c) Recursive Postoder
  d) Non-Recursive Inorder
  e) Non-Recursive Preorder
  f) Non-Recursive Postorder
  To exit press 'N'
  N
  Exiting...

Construct an Expression Tree from
1) Postfix
2) Prefix
Press 0 to exit
0
Exiting...

*/
