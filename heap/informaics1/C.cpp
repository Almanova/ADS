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

        int insert(int k, int in[]) {
            a.pb(k);
            size++;
            int i = size - 1;
            while (i > 0 && a[parent(i)] > a[i]) {
                swap(a[parent(i)], a[i]);
                i = parent(i);
            }
            return i;
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

        int heapify(int i) {
            int temp = i;
        while(true) {
            if (left(temp) > size - 1)
                return temp;
            int j = left(temp);
            if (right(temp) < size && a[j] < a[right(temp)])
                j = right(temp);
            if (a[temp] > a[j]) {
                swap(a[temp], a[j]);
                temp = j;
            }
            else
                break;
        }
        return temp;
        }

        int decreaseKey(int i, int new_value) {
            a[i] = new_value;
            while (i > 0 && a[parent(i)] > a[i]) {
                swap(a[parent(i)], a[i]);
                i = parent(i);
            }
            return i;
        }

        int increaseKey(int i, int new_value) {
            a[i] = new_value;
            return heapify(i);
        }

        int extractMin() {
            int root_value = a[0];
            swap(a[0], a[size - 1]);
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

        delete_element(int i) {
        int temp = a[i];
        swap(a[i], a[size - 1]);
        a.erase(a.begin() + size - 1);
        size--;
        if (i > 0 && a[i] < a[parent(i)]) {
            while (i > 0 && a[parent(i)] > a[i]) {
                swap(a[parent(i)], a[i]);
                i = parent(i);
            }
        } else 
        temp = heapify(i);
        return temp;
    }
    };

int main() {
    int n, k;
    cin >> n >> k;
    int b[n], in[n] = {0};
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    MinHeap *minHeap = new MinHeap();
    for (int i = 0; i < k; i++) {
        in[i] = minHeap->insert(b[i]);
    }
    cout << minHeap->getMin() << endl;
    for (int i = 1; i < n - k + 1; i++) {
        minHeap->print();
        if (b[i - 1] < b[i + k - 1]) {
            in[i + k - 1] = minHeap->increaseKey(in[i - 1], b[i + k - 1]);
        }
        else if (b[i - 1] > b[i + k - 1]) {
            in[i + k - 1] = minHeap->decreaseKey(in[i - 1], b[i + k - 1]);
        }
        cout << minHeap->getMin() << endl;
    }
}