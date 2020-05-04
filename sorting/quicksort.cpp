#include <bits/stdc++.h>

using namespace std;

void quicksort(int a[], int l, int r) {
    for (int k = l; k <= r; k++) {
        cout << a[k] << " ";
    }
    cout << endl;
    int i = l;
    int j = r;
    //int p = a[rand() % (r - l + 1) + l];
    int p = a[(r + l) / 2];
    while (i < j) {
        while (a[i] < p) 
            i++;
        while (a[j] > p)
            j--;
        if (i <= j) {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }
    if (l < j)
        quicksort(a, l, j);
    if (i < r)
        quicksort(a, i, r);
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