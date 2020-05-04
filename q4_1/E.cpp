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
    char data;
    int cnt;
    Node *ch[26];
    
    Node(char data) {
        this->data = data;
        cnt = 1;
        for (int i = 0; i < 26; i++)
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
            if (cur->ch[word[i] - 'a'] != NULL) {
                cur = cur->ch[word[i] - 'a'];
                cur->cnt++;
            }
            else {
                Node *node = new Node(word[i]);
                cur->ch[word[i] - 'a'] = node;
                cur = node;
            } 
        }
    }
    
    int startsWith(string prefix) {
        Node *cur = root;
        for (int i = 0; i < prefix.length(); i++) {
            if (cur->ch[prefix[i] - 'a'] == NULL)
                return 0;
            cur = cur->ch[prefix[i] - 'a'];
        }
        if (cur != NULL)
            return cur->cnt;
        else 
            return 0;
    }
};

int main() {
    vincit_omnia_veritas;
    int n;
    string q, s;
    Trie *trie = new Trie();
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> q >> s;
        if (q == "add")
            trie->insert(s);
        else 
            cout << trie->startsWith(s) << endl;
    }
    return 0;
}