#include <bits/stdc++.h>

using namespace std;

int main() {
    long long n, m, a, b, c;
    cin >> n >> a >> b >> c;
    long long l = 1, r = n * (a + b + c), m;
    while (l < r) {
        m = l + (r - l) / 2;
        if (m / a + m / b + m / c >= n)
            r = m;
        else
            l = m + 1;;
    }
    cout << l;
}