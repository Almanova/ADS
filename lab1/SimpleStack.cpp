#include <bits/stdc++.h>

using namespace std;

class Node {
    public:
    int data;
    Node *next;

    Node(int data) {
        this->data = data;
    }
};

class Stack {
    public:
    Node *top;
    int size;

    Stack() {
        top = NULL;
        size = 0;
    }

    void push(int data) {
        Node *node = new Node(data);
        if (top != NULL)
            node->next = top;
        top = node;
        size++;
    }

    void pop() {
        if (top != NULL) {
            top = top->next;
            size--;
        }
    }

    int back() {
        return top->data;
    }

    void clear() {
        while (size > 0)
            pop();
    }
};

int main() {
    Stack *st = new Stack();
    string s;
    int temp;
    while (cin >> s) {
        if (s == "push") {
            cin >> temp;
            st->push(temp);
            cout << "ok" << endl;
        }
        else if (s == "pop") {
            cout << st->back() << endl;
            st->pop();
        }
        else if (s == "back") {
            cout << st->back() << endl;
        }
        else if (s == "size") {
            cout << st->size << endl;
        }
        else if (s == "clear") {
            st->clear();
            cout << "ok" << endl;
        }
        else {
            cout << "bye" << endl;
            break;
        }
    }
}