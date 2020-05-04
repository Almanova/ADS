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

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

vector<int> countprefsum(vector<int> v) {
    int sum = 0;
    vector<int> res;
    for (int i = 0; i < v.size(); i++) {
        sum += v[i];
        res.pb(sum);
    }
    return res;
}

int main() {
    vincit_omnia_veritas;
    int n, m, x, q, l, r, sum = 0;
    cin >> n >> m;
    vector<int> initial, preffixsum;
    for (int i = 0; i < n; i++) {
        cin >> x;
        sum += x;
        initial.pb(x);
        preffixsum.pb(sum);
    }
    for (int i = 0; i < m; i++) {
        cin >> q >> l >> r;
        if (q == 1) {
            cin >> x;
            for (int j = l; j <= r; j++) {
                initial[j - 1] = x;
            }
            preffixsum = countprefsum(initial);
        }
        else if (q == 2) {
            cin >> x;
            for (int j = l; j <= r; j++) {
                initial[j - 1] = gcd(initial[j - 1], x);
            }
            preffixsum = countprefsum(initial);
        }
        else if (q == 3) {
            int largest = 0;
            for (int j = l; j <= r; j++) {
                if (initial[j - 1] > largest)
                    largest = initial[j - 1];
            }
            cout << largest << endl;
        }
        else {
            if (l == 1) {
                cout << preffixsum[r - 1] << endl;
            }
            else 
                cout << preffixsum[r - 1] - preffixsum[l - 2] << endl; 
        }
    }
}