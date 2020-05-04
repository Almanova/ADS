vector<vector<string> > word;

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
            word[cur->isEnd].push_back(temp);
        for (int i = 0; i < 26; i++) {
            if (cur->ch[i] != NULL)
                dfs(cur->ch[i]);
        }
        temp.pop_back();
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        word.clear();
        vector<string> ans;
        Trie *trie = new Trie();
        for (int i = 0; i <= words.size(); i++) {
            vector<string> v;
            word.push_back(v);
            if (i < words.size())
                trie->insert(words[i]);
        }
        for (int i = 0; i < 26; i++) {
            trie->temp = "";
            if (trie->root->ch[i] != NULL)
                trie->dfs(trie->root->ch[i]);
        }
        int cnt = 0;
        for (int i = word.size() - 1; i >= 0; i--) {
            for (int j = 0; j < word[i].size(); j++) {
                ans.push_back(word[i][j]);
                cnt++;
                if (cnt == k)
                    return ans;
            }
        }
        return ans;
    }
};