#include <bits/stdc++.h>

using namespace std;

bool isPrime(int n) {
    for (int i = 2; i * i < n; i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}

vector<char> SieveOfEratosthenes (long long n) {
    vector<char> prime (n + 1, true);
    prime[0] = prime[1] = false;
    for (long long i = 2; i <= n; i++) {
        if (prime[i])
            if (i * 1ll * i <= n)
                for (long long j = i * i; j <= n; j += i)
                    prime[j] = false;
    }

    return prime;
}

int main() {
    int n;
    cin >> n;
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0 && isPrime(i)) {
            cout << i << " ";
            n /= i;
        }
    }
    if (n > 1)
        cout << n;
    
    return 0;
}