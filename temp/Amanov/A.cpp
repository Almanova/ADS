#include <bits/stdc++.h>

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

    void inOrder(Node *node) {
        if (node == NULL)
            return;
        inOrder(node->left);
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

    void levelSum(Node *node, int level, int sum[]) {
        if (node == NULL)
            return;
        levelSum(node->left, level + 1, sum);
        sum[level] += node->data;
        levelSum(node->right, level + 1, sum);
    }
};

int main() {
    BST *bst = new BST();
    int n, x;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        bst->root = bst->insert(bst->root, x, 0);
    }
    cout << maxi << endl;
    int sum[maxi] = {0};
    bst->levelSum(bst->root, 0, sum);
    for (int i = 0; i < maxi; i++) {
        cout << sum[i] << " ";
    }
}