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

class MinHeap {
        public:
        vector<double> a;
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

        void insert(double k) {
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

        double extractMin() {
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
    vincit_omnia_veritas;
    int n;
    double sum = 0, x;
    cin >> n;
    MinHeap *minHeap = new MinHeap();
    for (int i = 0; i < n; i++) {
        cin >> x;
        minHeap->insert(x);
    }
    while (minHeap->size > 1) {
        double a = minHeap->extractMin();
        double b = minHeap->extractMin();
        double next = a + b;
        double temp = next * 0.05;
        cout << a << " " << b << endl;
        sum += temp;
        minHeap->insert(next);
    }
    printf("%.6f", sum);
    cout << setprecision(6) << fixed << sum;
}