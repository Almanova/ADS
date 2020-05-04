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

vector<string> uniques;

class Node {
    public:
    char data;
    bool checked;
    Node *ch[26];

    Node (char data) {
        this->data = data;
        this->checked = false;
        for (int i = 0; i < maxchar; i++)
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

    void dfs(Node *cur) {
        cur->checked = true;
        temp += cur->data;
        for (int i = 0; i < 26; i++) {
            if (cur->ch[i] != NULL)
                dfs(cur->ch[i]);
        }
        uniques.pb(temp);
        temp.pop_back();
    }
};

int main() {
    vincit_omnia_veritas;
    string s1, s2;
    cin >> s1 >> s2;
    int cnt = 0;
    Trie *trie = new Trie();
    Trie *trie2 = new Trie();
    for (int i = 0; i < s1.size(); i++)
        trie->insert(s1.substr(i));
    for (int j = 0; j < s2.size(); j++)
        trie2->insert(s2.substr(j));
    for (int i = 0; i < 26; i++) {
            trie->temp = "";
            if (trie->root->ch[i] != NULL)
                trie->dfs(trie->root->ch[i]);
        }
    for (int i = 0; i < uniques.size(); i++) {
        if (trie2->search(uniques[i]))
            cnt++;
    }
    cout << cnt;
}