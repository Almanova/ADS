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
    int n, m, k, f, s, num, x, limit;
    unordered_map<int, pair<int, int> > mapp;
    unordered_map<int, vector<int> > mappy;
    unordered_map<int, int> limitcount;
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        cin >> f >> s;
        mapp[i + 1] = mp(f, s);
    }
    int r;
    cin >> r;
    for (int i = 0; i < r; i++) {
        cin >> f >> num;
        vector<int> v;
        for (int j = 0; j < num; j++) {
            cin >> x;
            v.pb(x);
        }
        mappy[f] = v;
        cin >> limit;
        for (int j = 0; j < v.size(); j++) {
            limitcount[v(j)] = limit;
        }
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> x;
        if (mapp[x])
    }
}