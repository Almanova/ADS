#include <bits/stdc++.h>

#define vincit_omnia_veritas ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
#define pb push_back
#define mp make_pair
#define F first
#define S second

using namespace std;

const int inf = (int)1e9;
const double eps = (int)1e-9;
const int maxchar = 26;

class Node {
    public:
    int data;
    Node *next;
    Node *prev;

    Node (int data) {
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

    void pop_back() {
        if (tail != NULL) {
            tail = tail->prev;
            if (tail != NULL)
                tail->next = NULL;
        }
    }

    void pop_front() {
        if (head != NULL) {
            head = head->next;
            head->prev = NULL;
        }
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

    void push_front(int data) {
        Node *node = new Node(data);
        if (head == NULL) {
            tail = node;
            head = node;
        }
        else {
            head->prev = node;
            node->next = head;
            head = node;
        }
    }

    void delete_element(Node *node) {
        if (node == head)
            pop_front();
        else if (node == tail) {
            pop_back();
        }
        else {
            node->prev->next = node->next;
            node->next->prev = node->prev;
        }
    }

    Node* search(int data) {
        Node *node = head;
        while (node != NULL && node->data != data)
            node = node->next;
        return node;
    }

    void print() {
        Node *node = head;
        while (node != NULL) {
            cout << node->data << " ";
            node = node->next;
        }
        cout << endl;
    }

    int count(int x) {
        int cnt = 0;
        Node *node = head;
        while (node != NULL) {
            if (node->data == x)
                cnt++;
            node = node->next;
        }
        return cnt;
    }

    int serch_by_index(int i) {
        int index = 0;
        Node *node = head;
        while (index != i) {
            node = node->next;
            index++;
        }
        return node->data;
    }
};

int main() {
    vincit_omnia_veritas;
    LinkedList *list = new LinkedList();
    int n, x;
    string q;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> q;
        if (q == "insertFirst") {
            cin >> x;
            list->push_front(x);
        }
        else if (q == "insertLast") {
            cin >> x;
            list->push_back(x);
        }
        else if (q == "cnt") {
            cin >> x;
            cout << list->count(x) << endl;
        }
        else if (q == "getNth") {
            cin >> x;
            cout << list->serch_by_index(x) << endl;
        }
    }
    list->print();
}