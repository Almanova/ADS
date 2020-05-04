#include <bits/stdc++.h>

using namespace std;

class Node {
    public:
    int data;
    Node *next;
    Node *prev;

    Node(int data) {
        this->data = data;
        next = NULL;
        prev = NULL;
    }
};

class LinkedList {
    public:
    Node *head, *tail;

    LinkedList() {
        head = NULL;
        tail = NULL;
    }

    void push_back(int data) {
        Node *node = new Node(data);
        if (tail == NULL) {
            tail = node;
            head = node;
        }
        else {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
    }

    void reverse_list() {
        Node *node = head;
        Node *prev = NULL, *next = NULL;
        while (node != NULL) {
            next = node->next;
            node->next = prev;
            prev = node;
            node = next;
        }
        head = prev;
    }

    int GetNth(Node* head, int index)  
{  
      
    Node* current = head;  
      
    // the index of the  
    // node we're currently  
    // looking at  
    int count = 0;  
    while (current != NULL)  
    {  
        if (count == index)  
            return(current->data);  
        count++;  
        current = current->next;  
    }  
  
    /* if we get to this line,  
    the caller was asking  
    for a non-existent element  
    so we assert fail */
    assert(0);          
}  

    void print() {
        Node *node = head;
        while (node != NULL) {
            cout << node->data << "->";
            node = node->next;
        }
        cout<<"NULL";
    }
};

int main() {
    LinkedList *ll = new LinkedList();
    string s;
    cin >> s;
    string temp = "";
    for (int i = 0; i < s.length(); i++) {
        if (i == 0) {
            temp += s[i];
        }
        else if (s[i] == 'N')
            break;
        else if (s[i] != '-' && s[i] != '>') {
            temp += s[i];
        }
        else {
            if (temp.length() > 0) {
                ll->push_back(stoi(temp));
                temp = "";
            }
        }
    }
    ll->reverse_list();
    ll->print();
}