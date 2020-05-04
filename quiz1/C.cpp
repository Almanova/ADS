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
    int maxi;
    int size;

    Stack() {
        top = NULL;
        maxi = NULL;
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

    int getMax() {
        
    }
}

int main() {

}