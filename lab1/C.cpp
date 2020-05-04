#include <bits/stdc++.h>

using namespace std;

bool isPrime(int n) {
    for (int i = 2; i * i < n; i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}

void SieveOfEratosthenes (int n) {
    vector<char> prime (n + 1, true);
    prime[0] = prime[1] = false;
    for (int i = 2; i <= n; i++) {
        if (prime[i])
            if (i + 1ll * i <= n)
                for (int j = i * i; j <= n; j += i)
                    prime[j] = false;
    }

    for (int i = 2; i <= n/2; i++) {
        if (prime[i] && n % i == 0)
            cout << i << " ";
    }
    if (prime[n])
        cout << n;
}

int main() {
    int n;
    cin >> n;
    for (int i = 2; i <= n/2; i++) {
        if (n % i == 0) {
            if (isPrime(i)) {
                cout << i << " ";
            }
        }
    }
    if (isPrime(n))
        cout << n;
}