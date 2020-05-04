#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, x;
    cin >> n >> m;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        cin >> x;
        v.push_back(x);
    }
    for (int i = 0; i < m; i++) {
        cin >> x;
        int l = 0, r = n - 1, m, result = -1;
        while (l <= r)
        {
            m = l + (r - l) / 2;
            if (v[m] == x) {
                r = m - 1;
                result = m;
            }
            else if (v[m] < x) {
                l = m + 1;
            }
            else {
                r = m - 1;
            }
        }
        cout << result  + 1 << " ";
        if (result != -1) {
            l = 0, r = n - 1, m;
            while (l <= r)  {
                m = l + (r - l) / 2;
                if (v[m] == x) {
                    result = m;
                    l = m + 1;
                }
                else if (v[m] < x) {
                    l = m + 1;
                }
                else {
                    r = m - 1;
                }
            }
            cout << result + 1 << endl;
        }
    }
}