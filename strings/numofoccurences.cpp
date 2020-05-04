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
    Node *ch[26];
    int isEnd;
    
    Node(char data) {
        this->data = data;
        this->isEnd = 0;
        for (int i = 0; i < 26; i++) 
            this->ch[i] = NULL;
    }
};

class Trie {
    public:
    Node *root;
    string temp;
    
    Trie() {
        root = new Node(' ');
        temp = "";
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
        cur->isEnd++;
    }
    
    void dfs(Node *cur) {
        temp += cur->data;
        if (cur->isEnd > 0)
            cout << temp << " - " << cur->isEnd << endl;
        for (int i = 0; i < 26; i++) {
            if (cur->ch[i] != NULL)
                dfs(cur->ch[i]);
        }
        temp.pop_back();
    }
};

int main() {
    vincit_omnia_veritas;
    int n;
    cin >> n;
    string s;
    Trie *trie = new Trie();
    for (int i = 0; i < n; i++) {
        cin >> s;
        trie->insert(s);
    }
    for (int i = 0; i < 26; i++) {
        trie->temp = "";
        if (trie->root->ch[i] != NULL)
            trie->dfs(trie->root->ch[i]);
    }
    return 0;
}