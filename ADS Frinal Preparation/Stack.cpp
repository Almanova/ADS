#include <bits/stdc++.h>

using namespace std;

template<typename T>
class Node {
    public:
    T data;
    Node *next;

    Node(T data) {
        this->data = data;
        this->next = NULL;
    }
};

template<typename T>
class Stack {
    public:
    Node<T> *top;
    int size;

    Stack() {
        this->top = NULL;
        this->size = 0;
    }

    void push(T data) {
        Node<T> *node = new Node<T>(data);
        if (top == NULL) 
            this->top = node;
        else {
            node->next = top;
            top = node;
        }
        size++;
    }

    bool empty() {
        return size == 0;
    }

    void pop() {
        if (!empty()) {
            this->top = top->next;
            size--;  
        }
    }

    T front() {
        return top->data;
    }
};

int main() {
    Stack<int> *st = new Stack<int>();
    st->push(3);
    st->push(4);
    st->push(5);
    while (!st->empty()) {
        cout << st->front() << endl;
        st->pop();
    }
}