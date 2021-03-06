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
    int maxi;

    MaxHeap() {
        size = 0;
        maxi = 0;
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

    void getMax() {
        maxi = a[0];
    }

    int insert(int k) {
        a.push_back(k);
        size++;
        int i = size - 1;
        while (i > 0 && a[parent(i)] < a[i]) {
            swap(a[parent(i)], a[i]);
            i = parent(i);
        }
        return i + 1;
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
        swap(a[0], a[size - 1]);
        a.erase(a.begin() + size - 1);
        size--;
        return heapify(0) + 1;
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

    int delete_element(int i) {
        int temp = a[i];
        swap(a[i], a[size - 1]);
        a.erase(a.begin() + size - 1);
        size--;
        if (i > 0 && a[i] > a[parent(i)]) {
            while (i > 0 && a[parent(i)] < a[i]) {
                swap(a[parent(i)], a[i]);
                i = parent(i);
            }
        } else 
        int j = heapify(i);
        return temp;
    }
};

int main() {
    vincit_omnia_veritas;
    MaxHeap *maxHeap = new MaxHeap();
    int n, m, x, y;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> x;
        if (x == 1) {
            if (maxHeap->size == 0)
                cout << "-1" << endl;
            else {
                maxHeap->getMax();
                if (maxHeap->size > 1) {
                    cout << maxHeap->extractMax() << " " << maxHeap->maxi << endl;
                }
                else {
                    int j = maxHeap->extractMax();
                    cout << "0 "<< maxHeap->maxi << endl;
                }
            }
        }
        else if (x == 2) {
            cin >> y;
            if (maxHeap->size >= n) 
                cout << "-1" << endl;
            else {
                cout << maxHeap->insert(y) << endl;
            }
        }
        else if (x == 3) {
            cin >> y;
            if (y - 1 < 0 || y - 1 > maxHeap->size - 1 || maxHeap->size < 1) 
                cout << "-1" << endl;
            else if (y == 1) {
                maxHeap->getMax();
                int j = maxHeap->extractMax();
                cout << maxHeap->maxi << endl;
            }
            else {
                cout << maxHeap->delete_element(y - 1) << endl;
            }
        }
    }
    maxHeap->print();
    return 0;
}