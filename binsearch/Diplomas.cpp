#include <bits/stdc++.h>

using namespace std;

int main() {
    long long w, h, n;
    cin >> w >> h >> n;
    long long mini = min(w, h), maxi = max(w, h) * n;
    long long m;
    while (mini < maxi) {
        m = mini + (maxi - mini) / 2;
        if (n <= ((m / w) * (m / h)))
            maxi = m;
        else 
            mini = m + 1;
    }
    cout << mini;
}