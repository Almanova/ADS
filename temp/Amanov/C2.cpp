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

bool isPrime(int n) {
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main() {
    vincit_omnia_veritas;
    vector<int> v;
    v.pb(2);
    for (int i = 3; i < 10000; i++) {
        if (isPrime(i) == true)
            v.pb(i);
    }
    int n;
    cin >> n;
    cout << v[n - 1];
}