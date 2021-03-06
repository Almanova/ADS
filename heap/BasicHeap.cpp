#include <bits/stdc++.h>

#define pb push_back

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
            return 2 * i + 2;
        }

        int getMin() {
            return a[0];
        }

        void insert(int k) {
            a.pb(k);
            size++;
            int i = size - 1;
            while (i > 0 && a[parent(i)] > a[i]) {
                swap(a[parent(i)], a[i]);
                i = parent(i);
            }
        }

        void delete_by_index(int i) {
            decreaseKey(i, a[0] - 1);
            extractMin();
        }

        void delete_by_value(int k) {
            for (int i = 0; i < size; i++) {
                if (a[i] == k)
                    k = i;
            }
            delete_by_index(k);
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

        void decreaseKey(int i, int new_value) {
            a[i] = new_value;
            while (i > 0 && a[parent(i)] > a[i]) {
                swap(a[parent(i)], a[i]);
                i = parent(i);
            }
        }

        void increaseKey(int i, int new_value) {
            a[i] = new_value;
            heapify(i);
        }

        int extractMin() {
            int root_value = a[0];
            swap(a[0], a[size - 1]);
            a.erase(a.begin() + size - 1);
            size--;
            heapify(0);
            return root_value;
        }

        void print() {
            for (int i = 0; i < size; i++) {
                cout << a[i] << " ";
            }
            cout << endl;
        }
    };

int main() {
    MinHeap *minHeap = new MinHeap();
    int n, k;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> k;
        minHeap->insert(k);
    }
    for (int i = 0; i < n; i++) {
        cout << minHeap->extractMin() << " ";
    }   
    return 0;
}