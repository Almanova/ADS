#include <bits/stdc++.h>

using namespace std;

template<typename T>
class Node {
    public:
    T data;
    Node *next, *prev;

    Node(T data) {
        this->data = data;
        next = NULL;
        prev = NULL;
    }
};

template<typename T>
class LinkedList {
    public:
    Node<T> *front, *back;
    int size;

    LinekdList() {
        front = NULL;
        back = NULL;
        size = 0;
    }

    void push_front(T data) {
        Node<T> *node = new Node<T>(data);
        if (front == NULL) {
            front = node;
            back = node;
        }
        else {
            node->next = front;
            front->prev = node;
            front = node;
        }
    }

    void push_back(T data) {
        Node<T> *node = new Node<T>(data);
        if (front == NULL) {
            front = node;
            back = node;
        }
        else {
            node->prev = back;
            back->next = node;
            back = node;
        }
    }

    void pop_front() {
        if (front != NULL) {
            front = front->next;
            if (front != NULL)
                front->prev = NULL;
        }
    }

    void pop_back() {
        if (back != NULL) {
            back = back->prev;
            if (back != NULL)
                back->next = NULL;
        }
    }

    Node<T> search(T data) {
        Node<T> *node = front;
        while (node != NULL && node->data != data) 
            node = node->next;
        return node;
    }

    void delete_element(Node<T> *node) {
        if (node == front)
            pop_front();
        else if (node == back)
            pop_back();
        else {
            node->prev->next = node->next;
            node->next->prev = node->prev;
        }
    }

    void insert(Node *node1, Node *node2) {
        if (node1 == back)
            push_back(node2->data);
        else {
            node2->prev = node1;
            node2->next = node1->next;
            node1->next->prev = node2;
            node1->next = node2;
        }
    }

    void reverse_SLL() {
        Node<T> *current = front;
        Node<T> *prev = NULL, *next = NULL;
        while (current != NULL) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }

    void reverse_DLL() {
        Node<T> *temp = NULL, *current = front;
        while (current != NULL) {
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            current = current->prev;
        }
        if (temp != NULL) {
            head = temp->prev;
        }
    }
};

int main() {

}