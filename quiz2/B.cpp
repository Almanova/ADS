#include <bits/stdc++.h>

#define vincit_omnia_veritas ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
#define pb push_back
#define mp make_pair
#define F first
#define S second

using namespace std;

const int inf = (int)1e9;
const double eps = (int)1e-9;
const int maxchar = 26;

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

    Node* find(Node* root, int x) {
		if (root == NULL) {
			return NULL;
		} else if (root->data == x) {
			return root;
		} else if (root->data < x) {
			return find(root->right, x);
		} else {
			return find(root->left, x);
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
};

int main() {
    vincit_omnia_veritas;
    int n, x, k;
    cin >> n;
    BST *bst = new BST();
    for (int i = 0; i < n ; i++) {
        cin >> x;
        bst->root = bst->insert(bst->root, x);
    }
    cin >> k;
    Node *node = bst->find(bst->root, k);
    cout << bst->maxDepth(node);
}