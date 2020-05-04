#include <bits/stdc++.h>

using namespace std;

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
    
    bool startsWith(string prefix) {
        Node *cur = root;
        for (int i = 0; i < prefix.length(); i++) {
            if (cur->ch[prefix[i] - 'a'] == NULL)
                return false;
            cur = cur->ch[prefix[i] - 'a'];
        }
        return cur != NULL;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */