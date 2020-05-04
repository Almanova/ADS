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

pair<int, int> g[100];

int main() {
    vincit_omnia_veritas;
    int n, m, x, y;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        x--;
        y--;
        g[y].F++;
        g[x].S++;
    }
    for (int i = 0; i < n; i++) {
        cout << g[i].F << endl << g[i].S << endl;
    }
	return 0;
}