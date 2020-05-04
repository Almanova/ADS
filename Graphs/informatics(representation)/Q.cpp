#include <bits/stdc++.h>

#define vincit_omnia_veritas ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
#define pb push_back
#define mp make_pair
#define F first
#define S second

using namespace std;

const int inf = (int)1e9;

vector<int> g[100];

int main() {
    vincit_omnia_veritas;
    int n, m, x, y;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        x--;
        y--;
        g[x].pb(y);
        g[y].pb(x);
    }
    int temp = g[0].size();
    for (int i = 1; i < n; i++) {
        if (g[i].size() != temp) {
            cout << "NO";
            return 0;
        }
    }
        cout << "YES";
	return 0;
}