#include <bits/stdc++.h>

using namespace std;

bool isPrime(int n) {
    for (int i = 2; i * i < n; i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0 && isPrime(i)) {
            cout << i << " ";
            n /= i;
        }
        if (n > 1) 
            cout << n;
    }
}