#include <iostream>

using namespace std;

int maxi = 0;

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

    Node *insert(Node *node, int data, int cnt) {
        cnt++;
        if (cnt > maxi)
            maxi = cnt;
        if (node == NULL) {
            node = new Node(data);
            return node;
        }
        if (data < node->data)
            node->left = insert(node->left, data, cnt);
        else if (data > node->data)
            node->right = insert(node->right, data, cnt);
        return node;
    }

    /*int maxDepth(Node *node) {
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
            bst->root = bst->insert(bst->root, s, 0);
        }
    }
    cout << maxi;
}