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

int main() {
    vincit_omnia_veritas;
    double n, h, x;
    cin >> n >> h;
    vector<double> v;
    for (int i = 0; i < n; i++) {
        cin >> x;
        v.pb(x);
    }
    int l = 0, r = 1000000000, m;
    while (r - l > 1)
    {
        m = l + (r - l) / 2;
        double temp = 0;
        for (int i = 0; i < n; i++) {
            double d = ceil(v[i] / m);
            temp += d;
        }
        if (temp <= h)
        {
            r = m;
        }
        else
            l = m + 1;
    }
    cout << l;
}