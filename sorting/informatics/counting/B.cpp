#include <bits/stdc++.h>

using namespace std;

int a[10001];

int main() {
    ios_base::sync_with_stdio(0);
    int l, n, m, b, e, x;
    cin >> l >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> b >> e;
        for (int j = b; j <= e; j++) 
            a[j]++;
    }
    for (int i = 0; i < m; i++) {
        cin >> x;
        cout << a[x] << endl;
    }
}