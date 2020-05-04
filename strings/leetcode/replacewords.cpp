class Node {
    public:
    char data;
    Node *ch[26];
    bool isEnd;
    
    Node(char data) {
        this->data = data;
        isEnd = false;
        for (int i = 0; i < 26; i++) {
            this->ch[i] = NULL;
        }
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
    
    string search(string word) {
        string temp = "";
        Node *cur = root;
        for (int i = 0; i < word.length(); i++) {
            if (cur->ch[word[i] - 'a'] == NULL)
                return "";
            cur = cur->ch[word[i] - 'a'];
            temp += cur->data;
            if (cur->isEnd) {
                return temp;
            }
        }
        return "";
    }
};

class Solution {
public:
    string replaceWords(vector<string>& dict, string sentence) {
        Trie *trie = new Trie();
        string res = "";
        for (int i = 0; i < dict.size(); i++)
            trie->insert(dict[i]);
        string s = "";
        for (int i = 0; i < sentence.length(); i++) {
            if (sentence[i] != ' ')
                s += sentence[i];
            if (i == sentence.size() - 1 || sentence[i] == ' ') {
                if (trie->search(s) == "")
                    res += s;
                else 
                    res += trie->search(s);
                res += " ";
                s = "";
            }
        }
        if (res[res.size() - 1] = ' ')
            res.pop_back();
        return res;
    }
};