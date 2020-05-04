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

template<typename T>
class Node {
    public:
    int data;
    Node<T> *next;

    Node(T data) {
        this->data = data;
    }
};

template<typename T>
class Stack {
    public:
    Node<T> *top;
    int size;

    Stack() {
        top = NULL;
        size = 0;
    }

    void push(T data) {
        Node<T> *node = new Node<T>(data);
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

    T back() {
        return top->data;
    }

    void clear() {
        while (size > 0)
            pop();
    }
};

int main() {
    vincit_omnia_veritas;
    Stack<char> *st = new Stack<char>();
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); i++) {
        if (st->size == 0) {
            st->push(s[i]);
        }
        else {
            if (st->back() == s[i])
                st->pop();
            else 
                st->push(s[i]);
        }
    }
    if (st->size == 0) 
        cout << "YES";
    else 
        cout << "NO";
}