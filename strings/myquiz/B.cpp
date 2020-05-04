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
    bool isEnd;
    Node (char data) {
        this->data = data;
        isEnd = false;
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
            if (cur->ch[word[i] - 'a'] != NULL)
                cur = cur->ch[word[i] - 'a'];
            else {
                Node *node = new Node(word[i]);
                cur->ch[word[i] - 'a'] = node;
                cur = node;
            } 
        }
        cur->isEnd = true;
    }
    
    bool search(string word) {
        Node *cur = root;
        for (int i = 0; i < word.length(); i++) {
            if (cur->ch[word[i] - 'a'] == NULL)
                return false;
            cur = cur->ch[word[i] - 'a'];
        }
        return cur->isEnd;
    }
};

int main() {
    vincit_omnia_veritas;
    Trie *trie = new Trie();
    string main, s;
    int n;
    cin >> main >> n;
    set<int> lengths;
    for (int i = 0; i < n; i++) {
        cin >> s;
        trie->insert(s);
        lengths.insert(s.size());
    }
    for (set<int>::iterator it = lengths.begin(); it != lengths.end(); it++) {
            string s1 = main.substr(0, *it);
            if (trie->search(s1)) {
                string s2 = main.substr(*it, main.size() - *it);
                if (trie->search(s2)) {
                    cout << "YES";
                    return 0;
                }
            }
    }
    cout << "NO";
    return 0;
}