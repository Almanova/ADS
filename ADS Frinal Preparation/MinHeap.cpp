#include <bits/stdc++.h>

using namespace std;

class MinHeap {
    public:
    vector<int> a;
    int size;

    MinHeap() {
        size = 0;
    }

    int parent(int i) {
        return (i - 1) / 2;
    }

    int left(int i) {
        return 2 * i + 1;
    }

    int right(int i) {
        return 2 * i + 1;
    }

    int getMin() {
        return a[0];
    }

    void insert(int k) {
        a.push_back(k);
        size++;
        int i = size - 1;
        while (i > 0 && a[i] < a[parent(i)]) {
            swap(a[i], a[parent(i)]);
            i = parent(i);
        }
    }

    void heapify(int i) {
        if (left(i) > size - 1)
            return;
        int j = left(i);
        if (right(i) < size && a[j] > a[right(i)])
            j = right(i);
        if (a[i] > a[j]) {
            swap(a[i], a[j]);
            heapify(j);
        }
    }

    int extractMin() {
        int root_value = a[0];
        swap(a[0], a[size - 1]);
        a.erase(a.begin() + size - 1);
        size--;
        heapify(0);
        return root_value;
    }

    void decreaseKey(int i, int new_value) {
        a[i] = new_value;
        while (i > 0 && a[i] < a[parent(i)]) {
            swap(a[i], a[parent(i)]);
            i = parent(i);
        }
    }

    void increaseKey(int i, int new_value) {
        a[i] = new_value;
        heapify(i);
    }

    void delete_element(int i) {
        decreaseKey(i, a[0] - 1);
        extractMin();
    }

    void print() {
        for (int i = 0; i < size; i++) {
            cout << a[i] << " ";
        }
    }
};

int main() {
    MinHeap *heap = new MinHeap();
    int x;
    for (int i = 0; i < 5; i++) {
        cin >> x;
        heap->insert(x);
    }
    heap->print();
}

//time complexity of building a heap O(nlogn);