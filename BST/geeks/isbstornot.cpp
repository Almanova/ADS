#include<bits/stdc++.h> 
#include<iostream> 
using namespace std; 

/* A binary tree node has data, 
pointer to left child and 
a pointer to right child */
class node 
{ 
	public: 
	int data; 
	node* left; 
	node* right; 
	
	/* Constructor that allocates 
	a new node with the given data 
	and NULL left and right pointers. */
	node(int data) 
	{ 
		this->data = data; 
		this->left = NULL; 
		this->right = NULL; 
	} 
}; 

int isBSTUtil(node* node, int min, int max); 

/* Returns true if the given 
tree is a binary search tree 
(efficient version). */
int isBST(node* node) 
{ 
	return(isBSTUtil(node, INT_MIN, INT_MAX)); 
} 

/* Returns true if the given 
tree is a BST and its values 
are >= min and <= max. */
int isBSTUtil(node* node, int min, int max) 
{ 
	/* an empty tree is BST */
	if (node==NULL) 
		return 1; 
			
	/* false if this node violates 
	the min/max constraint */
	if (node->data < min || node->data > max) 
		return 0; 
	
	/* otherwise check the subtrees recursively, 
	tightening the min or max constraint */
	return
		isBSTUtil(node->left, min, node->data-1) && // Allow only distinct values 
		isBSTUtil(node->right, node->data+1, max); // Allow only distinct values 
} 


/* Driver code*/
int main() 
{ 
	node *root = new node(4); 
	root->left = new node(2); 
	root->right = new node(5); 
	root->left->left = new node(1); 
	root->left->right = new node(3); 
	
	if(isBST(root)) 
		cout<<"Is BST"; 
	else
		cout<<"Not a BST"; 
		
	return 0; 
} 

// This code is contributed by rathbhupendra 


// C++ program to check if a given tree is BST. 
#include <bits/stdc++.h> 
using namespace std; 

/* A binary tree node has data, pointer to 
left child and a pointer to right child */
struct Node 
{ 
	int data; 
	struct Node* left, *right; 
}; 

// Returns true if given tree is BST. 
bool isBST(Node* root, Node* l=NULL, Node* r=NULL) 
{ 
	// Base condition 
	if (root == NULL) 
		return true; 

	// if left node exist then check it has 
	// correct data or not i.e. left node's data 
	// should be less than root's data 
	if (l != NULL and root->data <= l->data) 
		return false; 

	// if right node exist then check it has 
	// correct data or not i.e. right node's data 
	// should be greater than root's data 
	if (r != NULL and root->data >= r->data) 
		return false; 

	// check recursively for every node. 
	return isBST(root->left, l, root) and 
		isBST(root->right, root, r); 
} 

/* Helper function that allocates a new node with the 
given data and NULL left and right pointers. */
struct Node* newNode(int data) 
{ 
	struct Node* node = new Node; 
	node->data = data; 
	node->left = node->right = NULL; 
	return (node); 
} 

/* Driver program to test above functions*/
int main() 
{ 
	struct Node *root = newNode(3); 
	root->left	 = newNode(2); 
	root->right	 = newNode(5); 
	root->left->left = newNode(1); 
	root->left->right = newNode(4); 

	if (isBST(root,NULL,NULL)) 
		cout << "Is BST"; 
	else
		cout << "Not a BST"; 

	return 0; 
} 
