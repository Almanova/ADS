#include <bits/stdc++.h>

using namespace std;

int partition(int a[], int l, int r) {
    int p = a[r];
    int i = l - 1;
    for (int j = l; j < r; j++) {
        if (a[j] <= p) {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[r]);
    return i + 1;
}

void quicksort(int a[], int l, int r) {
    if (l < r) {
        int q = partition(a, l, r);
        if (l < q - 1)
            quicksort(a, l, q - 1);
        if (q + 1 < r)
            quicksort(a, q + 1, r);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
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