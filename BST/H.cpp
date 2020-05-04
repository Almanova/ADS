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
        if (data < node->data)
            node->left = insert(node->left, data);
        else if (data > node->data)
            node->right = insert(node->right, data);
        return node;
    }

    void inOrder(Node *node) {
        if (node == NULL)
            return;
        inOrder(node->left);
        if ((node->left != NULL && node->right == NULL) || (node->left == NULL && node->right != NULL) )
            cout << node->data << endl;
        inOrder(node->right);
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
            bst->root = bst->insert(bst->root, s);
        }
    }
    if (bst->isBalanced(bst->root))
        cout << "YES";
    else 
        cout << "NO";
}