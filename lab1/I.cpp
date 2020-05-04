#include <bits/stdc++.h>

using namespace std;

long long gcd(long long a, long long b) {
    if (b == 0)
        return a;
    else 
        return gcd(b, a % b);
}

int main() {
    long long n, m;
    cin >> n >> m;
    long long temp = gcd(n, m);
    long long ans = (n * m) / temp;
    cout << ans;
}