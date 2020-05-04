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

    int heapify(int i) {
        int temp = i;
        while(true) {
            if (left(temp) > size - 1)
                return temp;
            int j = left(temp);
            if (right(temp) < size && a[j] < a[right(temp)])
                j = right(temp);
            if (a[temp] < a[j]) {
                swap(a[temp], a[j]);
                temp = j;
            }
            else
                break;
        }
        return temp;
    }

    int extractMax() {
        int root_value = a[0];
        swap(a[0], a[size - 1]);
        a.erase(a.begin() + size - 1);
        size--;
        heapify(0);
        return root_value;
    }

    int increaseKey(int i, int new_value) {
        a[i] = new_value;
        while (i > 0 && a[parent(i)] < a[i]) {
            swap(a[parent(i)], a[i]);
            i = parent(i);
        }
        return i;
    }

    int decreaseKey(int i, int new_value) {
        a[i] = new_value;
        return heapify(i);
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
    MaxHeap *maxHeap = new MaxHeap();
    int n, k, x, b, c;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> k;
        maxHeap->insert(k);
    } 
    cin >> x;
    for (int i = 0; i < x; i++) {
        cin >> b >> c;
        cout << maxHeap->decreaseKey(b - 1, maxHeap->a[b - 1] - c) + 1 << endl;
    }
    maxHeap->print();
    return 0;
}