#include <bits/stdc++.h>

using namespace std;

void quicksort(int a[], int l, int r, int k) {
    int i = l;
    int j = r;
    int p = a[l + (r - l) / 2];
    while (i < j) {
        while (a[i] < p) 
            i++;
        while (a[j] > p)
            j--;
        if (i <= j) {
            //if (i == j && i == k) 
                //return;
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }
    if ((l == j && j == k) || (i == r && i == k))
        return;
    else if (l < j && k <= j)
        quicksort(a, l, j, k);
    else if (i < r && k >= i)
        quicksort(a, i, r, k);
}

int main() {
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    quicksort(a, 0, n - 1, k);
    cout << a[k] << endl;
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
}