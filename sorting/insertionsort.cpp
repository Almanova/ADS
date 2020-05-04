#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, i, k, j;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i < n; i++) {
        bool check = false;
        k = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > k) {
            check = true;
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = k;
        if (check) {
            for (int m = 0; m < n; m++) {
                 cout << a[m] << " ";
            }
            cout << endl;
        }
    }
}