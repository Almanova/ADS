#include <bits/stdc++.h>

using namespace std;

int gcd (int a, int b) {
    if (b == 0)
        return a;
    else return gcd(b, a % b);
}

int main() {
    int n, x;
    vector<int> v;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        v.push_back(x);
    }
    int ans = v[0];
    for (int i = 0; i < n; i++) {
        ans = gcd(ans, v[i]);
    }
    cout << ans;
}