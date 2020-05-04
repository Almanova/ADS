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
class Queue {
    public:
    Node<T> *front, *back;
    int size;

    Queue() {
        this->front = NULL;
        this->back = NULL;
        size = 0;
    }

    void push(T data) {
        Node<T> *node = new Node<T>(data);
        if (front == NULL) {
            front = node;
            back = node;
        }
        else {
            back->next = node;
            back = node;
        }
        size++;
    }

    bool empty() {
        return size == 0;
    }

    void pop() {
        if (front != NULL) {
            front = front->next;
            size--;
        }
    }

    T getFront() {
        return front->data;
    }
};

int main() {
    Queue<int> *q = new Queue<int>();
    q->push(3);
    q->push(4);
    q->push(5);
    while (!q->empty()) {
        cout << q->getFront() << endl;
        q->pop();
    }
    q->push(7);
    cout << q->getFront();
}