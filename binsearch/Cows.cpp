#include <bits/stdc++.h>

using namespace std;

int n, k;
vector<long long> v;

bool funct(long long m) {
    long long cnt = k;
    long long first = v[0];
    cnt--;
    for (int i = 1; i < n; i++) {
        if (v[i] - first >= m) {
            first = v[i];
            cnt--;
        }
    }
    if (cnt <= 0)
        return true;
    else 
        return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> k;
    long long x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        v.push_back(x);
    }
    long long l = 0, r = 1000000000, m;
    while (r - l > 1) {
        m = l + (r - l) / 2;
        if (funct(m))
            l = m;
        else if (!funct(m))
            r = m - 1;
    }
    if (funct(r))
        cout << r;
    else 
        cout << l;
}