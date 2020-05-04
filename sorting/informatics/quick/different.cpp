#include <bits/stdc++.h>

using namespace std;

void quicksort(int a[], int l, int r) {
    int i = l;
    int j = r;
    int p = a[rand() % (r - l + 1) + l];
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
    ios_base::sync_with_stdio(0);
    int n, ans = 0;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    quicksort(a, 0, n - 1);
    for (int i = 0; i < n - 1; i++) {
        if (a[i] != a[i + 1])
            ans++;
    }
    cout << ans + 1;
}