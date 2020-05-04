#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, x, y, ans = 0;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        cin >> x;
        v.push_back(x);
    }
    cin >> y;
    for (int i = 0; i < n; i++) {
        if (v[i] == y)
            ans++;
    }
    cout << ans;
}