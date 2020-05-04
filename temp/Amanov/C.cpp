#include <bits/stdc++.h>

#define vincit_omnia_veritas ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
#define pb push_back
#define mp make_pair
#define F first
#define S second

using namespace std;

const int inf = (int)1e9;
const double eps = (int)1e-9;
const int maxchar = 26;

int a[1001];

void SieveOfEratosthenes (int n) {
    vector<char> prime (n + 1, true);
    prime[0] = prime[1] = false;
    for (int i = 2; i <= n; i++) {
        if (prime[i])
            if (i * 1ll * i <= n)
                for (int j = i * i; j <= n; j += i)
                    prime[j] = false;
    }

    int cnt = 1;
    for (int i = 0; i < n; i++) {
        if (prime[i]) {
            a[cnt] = i; 
            cnt++;
        }
        if (cnt >= 1001) 
            break;
    }
}

int main() {
    vincit_omnia_veritas;
    SieveOfEratosthenes(100000);
    int n;
    cin >> n;
    cout << a[n];
}