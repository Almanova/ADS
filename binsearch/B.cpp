#include <bits/stdc++.h>

using namespace std;

int main() {
    long long n, cnt = 1;
    cin >> n;
    long long l = 1, r = n, m;
    while (l < r) {
        m = l + (r - l) / 2;
        r = m - 1;
        cnt++;
    }
    cout << cnt;
}