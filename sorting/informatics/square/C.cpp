#include <bits/stdc++.h>

#define vincit_omnia_veritas ios_base::sync_with_stdio(0);

using namespace std;

int main() {
    vincit_omnia_veritas;
    int n, x, t;
    cin >> n;
    int a[n + 1];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> x >> t;
    for (int i = n; i >= t; i--) {
        a[i] = a[i - 1];
    }
    a[t - 1] = x;
    for (int i = 0; i < n + 1; i++) {
        cout << a[i] << " ";
    }
}