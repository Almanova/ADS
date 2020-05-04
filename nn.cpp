#include <bits/stdc++.h>

using namespace std;

long long cnt(long long n, long long t) {
    return n / t;
}

long long findsum(long long a, long long b) {
    return (b - a) * (a + b + 1) / 2;
}

int main() {
    long long a, b, sum = 0;
    cin >> a >> b;
    long long m = sqrt(b);
    for (int d = 1; d <= m; d++) {
        sum += d * (cnt(b, d) - cnt(a - 1, d)) + findsum(max(m, cnt(a - 1, d)), max(m, cnt(b, d)));
    }
 
    cout << sum << endl;
}