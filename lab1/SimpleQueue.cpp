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

class Queue {
    public:
    Node *head, *tail;
    int size;

    Queue() {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    void push(int data) {
        Node *node = new Node(data);
        if (head == NULL) {
            head = node;    
        }
        else if (tail == NULL) {
            head->next = node;
            tail = node;
        }
        else {
            tail->next = node;
            tail = node;
        }
        size++;
    }

    void pop() {
        if (head != NULL) {
            head = head->next;
            size--;
        }
    }

    int front() {
        return head->data;
    }

    void clear() {
        while (size > 0)
            pop();
        head = NULL;
        tail = NULL;
        size = 0;
    }
};

int main() {
    Queue *st = new Queue();
    string s;
    int temp;
    while (cin >> s) {
        if (s == "push") {
            cin >> temp;
            st->push(temp);
            cout << "ok" << endl;
        }
        else if (s == "pop") {
            cout << st->front() << endl;
            st->pop();
        }
        else if (s == "front") {
            cout << st->front() << endl;
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