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

class MaxHeap {
    public:
    vector<int> a;
    int size;

    MaxHeap() {
        size = 0;
    }

    int parent(int i) {
        return (i - 1) / 2;
    }

    int left(int i) {
        return 2 * i + 1;
    }

    int right(int i) {
        return 2 * i + 2;
    }

    int getMax() {
        return a[0];
    }

    void insert(int k) {
        a.push_back(k);
        size++;
        int i = size - 1;
        while (i > 0 && a[parent(i)] < a[i]) {
            swap(a[parent(i)], a[i]);
            i = parent(i);
        }
    }

    void heapify(int i) {
        if (left(i) > size - 1)
            return;
        int j = left(i);
        if (right(i) < size && a[j] < a[right(i)])
            j = right(i);
        if (a[i] < a[j]) {
            swap(a[i], a[j]);
            heapify(j);
        }
    }

    int extractMax() {
        int root_value = a[0];
        swap(a[0], a[size - 1]);
        a.erase(a.begin() + size - 1);
        size--;
        heapify(0);
        return root_value;
    }

    void increaseKey(int i, int new_value) {
        a[i] = new_value;
        while (i > 0 && a[parent(i)] < a[i]) {
            swap(a[parent(i)], a[i]);
            i = parent(i);
        }
    }

    void decreaseKey(int i, int new_value) {
        a[i] = new_value;
        heapify(i);
    }

    void print() {
        for (int i = 0; i < size; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }

    void addToVector(int k) {
        a.push_back(k);
        size++;
    }
    
    void buildHeap() {
        int index = a.size() / 2 - 1;
        for (int j = index; j >= 0; j--) 
            heapify(j);
    }

    void heapSort() {
        buildHeap();
        int temp = size;
        for (int i = temp - 1; i >= 0; i--) {
            print();
            swap(a[0], a[i]);
            size--;
            heapify(0);
        }
    }
};

int main() {
    vincit_omnia_veritas;
    MaxHeap *maxHeap = new MaxHeap();
    int n, k;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> k;
        maxHeap->addToVector(k);
    }
    maxHeap->heapSort();
    for (int i = 0; i < n; i++) {
        cout << maxHeap->a[i] << " ";
    }
    return 0;
}