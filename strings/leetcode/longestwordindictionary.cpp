#include <bits/stdc++.h>

using namespace std;

class Node {
    public:
    char data;
    bool isEnd;
    bool checked;
    Node *ch[26];
    
    Node(char data) {
        this->data = data;
        isEnd = false;
        checked = false;
        for (int i = 0; i < 26; i++)
            this->ch[i] = NULL;
    }
};

class Trie {
    public:
    Node *root;
    string ans;
    string res;
    
    Trie() {
        root = new Node(' ');
        ans = "";
        res = "";
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
    
    void dfs(Node *cur) {
        cur->checked = true;
        ans += cur->data;
        for (int i = 0; i < 26; i++) {
            if (cur->ch[i] != NULL && cur->ch[i]->checked != true && cur->ch[i]->isEnd)
                dfs(cur->ch[i]);
        }
        if (ans.size() > res.size())
            res = ans;
        ans.pop_back();
    }
};
class Solution {
public:
    string longestWord(vector<string>& words) {
        Trie *trie = new Trie();
        for (int i = 0; i < words.size(); i++)
            trie->insert(words[i]);
        for (int i = 0; i < 26; i++) {
            trie->ans = "";
            if (trie->root->ch[i] != NULL && trie->root->ch[i]->isEnd)
                trie->dfs(trie->root->ch[i]);
        }
        return trie->res;
    }
};

int main() {
    vector<string> v;
    string s;
    for (int i = 0; i < 5; i++) {
        cin >> s;
        v.push_back(s);
    }
    Solution *solution = new Solution();
    cout << solution->longestWord(v);
}