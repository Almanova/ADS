#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, x;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        cin >> x;
        v.push_back(x);
    }
    cin >> x;
    int l = 0, r = n - 1, m;
    while (l < r) {
        m = l + (r - l) / 2;
        if (v[m] == x)
            l = m;
        else if (v[m] > x)
            r = m - 1;
        else 
            l = m + 1;
    }
    cout << l;
}