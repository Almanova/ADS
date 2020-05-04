#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k, x;
    cin >> n >> k;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        cin >> x;
        v.push_back(x);
    }
    for (int i = 0; i < k; i++) {
        cin >> x;
        int l = 0, r = n - 1, m;
        bool found = false;
        while (l <= r) {
            m = l + (r - l) / 2;
            if (v[m] == x) {
                found = true;
                break;
            }
            else if (v[m] < x)
                l = m + 1;
            else if (v[m] > x)
                r = m - 1;
        }
        if (found == true)
            cout << "YES" << endl;
        else 
            cout << "NO" << endl;
    }
}