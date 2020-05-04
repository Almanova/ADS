#include <bits/stdc++.h>

using namespace std;

class Node {
    public:
    int data;
    Node *left, *right;

    Node(int data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

class BST {
    public:
    Node *root;

    BST() {
        root = NULL;
    }

    Node *insert(Node *node, int data) {
        if (node == NULL) {
            node = new Node(data);
            return node;
        }
        else if (data <= node->data)
            node->left = insert(node->left, data);
        else 
            node->right = insert(node->right, data);
        return node;
    }

    /*struct node* search(struct node* root, int key) 
{ 
    // Base Cases: root is null or key is present at root 
    if (root == NULL || root->key == key) 
       return root; 
     
    // Key is greater than root's key 
    if (root->key < key) 
       return search(root->right, key); 
  
    // Key is smaller than root's key 
    return search(root->left, key); 
} */

    void inOrder(Node *node) {
        if (node == NULL)
            return;
        inOrder(node->left);
        cout << node->data << " ";
        inOrder(node->right);
    }

    Node *findMin(Node *node) {
        while (node->left != NULL)
            node = node->left;
        return node;
    }

    Node *findMax(Node *node) {
        while (node->right != NULL)
            node = node->right;
        return node;
    }   

    Node *delete_node(Node *node, int data) {
        if (node == NULL)
            return NULL;
        else if (data < node->data) 
            node->left = delete_node(node->left, data);
        else if (data > node->data)
            node->right = delete_node(node->right, data);
        else {
            if (node->right == NULL && node->left == NULL)
                node = NULL;
            else if (node->left == NULL) 
                node = node->right;
            else if (node->right == NULL)
                node = node->left;
            else {
                Node *temp = findMin(node->right);
                node->data = temp->data;
                node->right = delete_node(node->right, temp->data);
            }
        }
    }

    int maxDepth(Node *node) {
        if (node == NULL)
            return 0;
        else {
            int lDepth = maxDepth(node->left);
            int rDepth = maxDepth(node->right);

            if (lDepth > rDepth)
                return lDepth + 1;
            else 
                return rDepth + 1;
        }
    }

    bool isBalanced(Node *node) {   
        int lHeight;
        int rHeight;
        if (node == NULL) 
        return 1; 

        lHeight = maxDepth(node->left); 
        rHeight = maxDepth(node->right); 
  
        if (abs(lHeight - rHeight) <= 1 && isBalanced(node->left) && isBalanced(node->right)) 
            return true; 
        return false; 
    }

    void printPostorder(struct Node* node) 
{ 
    if (node == NULL) 
        return; 
  
    // first recur on left subtree 
    printPostorder(node->left); 
  
    // then recur on right subtree 
    printPostorder(node->right); 
  
    // now deal with the node 
    cout << node->data << " "; 
} 
  
/* Given a binary tree, print its nodes in inorder*/
void printInorder(struct Node* node) 
{ 
    if (node == NULL) 
        return; 
  
    /* first recur on left child */
    printInorder(node->left); 
  
    /* then print the data of node */
    cout << node->data << " "; 
  
    /* now recur on right child */
    printInorder(node->right); 
} 
  
/* Given a binary tree, print its nodes in preorder*/
void printPreorder(struct Node* node) 
{ 
    if (node == NULL) 
        return; 
  
    /* first print data of node */
    cout << node->data << " "; 
  
    /* then recur on left sutree */
    printPreorder(node->left);  
  
    /* now recur on right subtree */
    printPreorder(node->right); 
}
};

int main() {
    BST *bst = new BST();
    int s;
    while (true) {
        cin >> s;
        if (s == 0)
            break;
        else {
            bst->root = bst->insert(bst->root, s);
        }
    }
    bst->printPreorder(bst->root);
}

//Searching: For searching element 1, we have to traverse all elements (in order 3, 2, 1). 
//Therefore, searching in binary search tree has worst case complexity of O(n). 
//In general, time complexity is O(h) where h is height of BST.
//Insertion: For inserting element 0, it must be inserted as left child of 1. 
//Therefore, we need to traverse all elements (in order 3, 2, 1) to insert 0 which has worst case complexity of O(n).
//In general, time complexity is O(h).
//Deletion: For deletion of element 1, we have to traverse all elements to find 1 (in order 3, 2, 1). 
//Therefore, deletion in binary tree has worst case complexity of O(n). In general, time complexity is O(h).