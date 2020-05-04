#include <bits/stdc++.h>

#define vincit_omnia_veritas ios_base::sync_with_stdio(0);
#define pb push_back

using namespace std;

void merge(int a[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1];
    int R[n2];
    for (int i = 0; i < n1; i++)
        L[i] = a[l + i];
    for (int i = 0; i < n2; i++)
        R[i] = a[m + i + 1];
    int uk1 = 0, uk2 = 0, k = l;
    while (uk1 < n1 && uk2 < n2) {
        if (L[uk1] <= R[uk2]) {
            a[k] = L[uk1];
            uk1++;
        }
        else if (L[uk1] > R[uk2]) {
            a[k] = R[uk2];
            uk2++;
        }
        else {
            a[k] = L[uk1];
            uk1++;
            uk2++;
        }
        k++;
    }
    while (uk1 < n1) {
        a[k] = L[uk1];
        uk1++;
        k++;
    }
    while (uk2 < n2) {
        a[k] = R[uk2];
        uk2++;
        k++;
    }
}

void mergesort(int a[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergesort(a, l, m);
        mergesort(a, m + 1, r);
        merge(a, l, m, r);
    }
}

int main() {
    vincit_omnia_veritas;
    int n, m, x;
    cin >> n;
    int v1[n];
    for (int i = 0; i < n; i++) {
        cin >> x;
        v1[i] = x;
    }
    cin >> m;
    int v2[m];
    for (int i = 0; i < n; i++) {
        cin >> x;
        v2[i] = x;
    }
    mergesort(v1, 0, n - 1);
    mergesort(v2, 0, m - 1);
    for (int i = 0; i < n; i++) {
        cout << v1[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < v2.size(); i++) {
        cout << v2[i] << " ";
    }
}