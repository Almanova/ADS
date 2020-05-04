#include <bits/stdc++.h>

using namespace std;

vector<bool> SieveOfEratosthenes(int n) {
    vector<bool> prime(n + 1, true);
    prime[0] = prime[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (prime[i]) {
            int k = i;
            while (k + i <= n) {
                k += i;
                prime[k] = false;
            }
        }
    }
    return prime;
}

int main() {

}