#include <bits/stdc++.h>

using namespace std;

int partition(int a[], int l, int r) {
    cout << l << " " << r;
    cout << endl;
    int p = a[r];
    int i = l;
    for (int j = l; j <= r; j++) {
        if (a[j] < p) {
            swap(a[i], a[j]);
            i++;
        }
    }
    swap(a[i], a[r]);
    return i;
}

void quicksort(int a[], int l, int r) {
    if (l < r) {
        int p = partition(a, l, r);
        quicksort(a, l, p - 1);
        quicksort(a, p + 1, r);
    }
}

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    quicksort(a, 0, n - 1);
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
}

//The worst case time complexity of a typical implementation of QuickSort is O(n^2). 
//The worst case occurs when the picked pivot is always an extreme (smallest or largest) element. 
//This happens when input array is sorted or reverse sorted and either first or last element is picked as pivot.
//O(n log n) (simple partition)
//O(n) (three-way partition and equal keys)