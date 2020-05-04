#include <bits/stdc++.h>

using namespace std;

int main() {
    long long n, x, y;
    cin >> n >> x >> y;
    long long first = min(x, y);
    long long mini = 0, maxi = max(x, y) * (n - 1), m;
    while (mini < maxi) {
        m = mini + (maxi - mini) / 2;
        if (n - 1 <= m / x + m / y)
            maxi = m;
        else 
            mini = m + 1;
    }
    cout << mini + first;
}