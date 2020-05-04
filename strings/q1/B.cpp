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
    bool isEnd;
    Node *ch[10];

    Node (int data) {
        this->data = data;
        this->isEnd = false;
        for (int i = 0; i < 10; i++)
            this->ch[i] = NULL;
    }
};

class Trie {
    public:
    Node *root;

    Trie() {
        root = new Node(' ');
    }

    void insert(string word) {
        Node *cur = root;
        for (int i = 0; i < word.size(); i++) {
            if (cur->ch[word[i] - 'a'] != NULL)
                cur = cur->ch[word[i] - 'a'];
            else {
                Node *node = new Node(word[i]);
                cur->ch[word[i] - 'a'] = node;
                cur = node;
            } 
        }
    }

    bool search(string word) {
        Node *cur = root;
        for (int i = 0; i < word.length(); i++) {
            if (cur->ch[word[i] - 'a'] == NULL)
                return false;
            cur = cur->ch[word[i] - 'a'];
        }
        return true;
    }
};

int main() {
    vincit_omnia_veritas;
}