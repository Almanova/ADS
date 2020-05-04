#include <bits/stdc++.h>

using namespace std;

class Node {
    public:
    int data, rep;
    Node *left, *right;

    Node(int data) {
        this->data = data;
        rep = 1;
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
        if (data < node->data) {
            node->left = insert(node->left, data);
        }
        else if (data > node->data) {
            node->right = insert(node->right, data);
        }
        return node;
    }

    bool ifNodeExists(Node *node, int key) 
{ 
    if (node == NULL) 
        return false; 
  
    if (node->data == key) 
        return true; 
  
    /* then recur on left sutree */
    bool res1 = ifNodeExists(node->left, key); 
  
    /* now recur on right subtree */
    bool res2 = ifNodeExists(node->right, key); 
  
    return res1 || res2; 
} 

    void inOrder(Node *node) {
        if (node == NULL)
            return;
        inOrder(node->left);
            cout << node->data << " " << node->rep << endl;
        inOrder(node->right);
    }

    Node *findElement(Node *node, int data) {
        if (node == NULL || node->data == data)
            return node;
        if (node->data < data)
            return findElement(node->right, data);
        else 
            return findElement(node->left, data);
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

    /*int size(Node *node) {  
        if (node == NULL)  
            return 0;  
        else
            return(size(node->left) + 1 + size(node->right));  
    }*/
};

int main() {
    BST *bst = new BST();
    int s;
    while (true) {
        cin >> s;
        if (s == 0)
            break;
        else {
            if (bst->ifNodeExists(bst->root, s)) {
                Node *node = bst->findElement(bst->root, s);
                node->rep++;
            }
            bst->root = bst->insert(bst->root, s);
        }
    }
    bst->inOrder(bst->root);
}