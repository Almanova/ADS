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
        int l = 0, r = n - 1, m, pos = -1;
        while (r - l > 1) {
            m = l + (r - l) / 2;
            if (v[m] == x) {
                pos = m;
                break;
            }
            else if (v[m] < x)
                l = m;
            else if (v[m] > x)
                r = m;
        }
        if (pos != -1)
            cout << v[pos] << endl;
        else {
            if (x - v[l] < v[r] - x || x - v[l] == v[r] - x)
                cout << v[l] << endl;
            else 
                cout << v[r] << endl;
        }
    }
}