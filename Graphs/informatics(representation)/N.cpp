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

int g[101][101];

int main() {
    vincit_omnia_veritas;
    int n, x, y;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> g[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        int in = 0, out = 0;
        for (int j = 0; j < n; j++) {
            if (g[i][j] > 0)
                out++;
            if (g[j][i] > 0)
                in++;
        }
        cout << in << endl << out << endl;
    }
	return 0;
}