#include <bits/stdc++.h>

using namespace std;

void SieveOfEratosthenes(int n) {
        vector<char> prime (n + 1, true);
        prime[0] = prime[1] = false;
        for (int i = 2; i <= n; i++) {
            if (prime[i])
                if (i * 1ll * i <= n)
                    for (int j = i * i; j <= n; j += i)
                        prime[j] = false;
        }

        for (int i = 2; i <= n; i++) {
            if (prime[i] && prime[n-i]) {
                cout << i << " " << n - i;
                break;
            }
        }
    }

int main() {
    int n;
    cin >> n;
    SieveOfEratosthenes(n);
}