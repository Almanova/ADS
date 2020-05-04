#include <bits/stdc++.h>

#define pb push_back

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    int n, m, x, k, ans = 0;
    vector<int> a, b;
    cin >> n >> m;
    for (int i = 0; i < n * m; i++) {
        cin >> x;
        a.pb(x);
    }
    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> x;
        b.pb(x);
    }
    int cnt = 0;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for (int i = 0; i < n * m; i++) {
        if (a[i] >= b[cnt]) {
            ans++;
            if (cnt + 1 < k)
                cnt++;
            else 
                break;
        }
    }
    cout << ans;
}