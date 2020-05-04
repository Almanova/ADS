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

int g[100][100];
pair<int, int> gr[100];

int main() {
    vincit_omnia_veritas;
    int n, x, y;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> g[i][j];
            if (g[i][j] > 0) {
                gr[i].S++;
                gr[j].F++;
            }
        }
    }
    vector<int> out;
    vector<int> in;
    for (int i = 0; i < n; i++) {
        if (gr[i].S == 0) {
            out.pb(i + 1);
        }
        if (gr[i].F == 0) {
            in.pb(i + 1);
        }
    }
    cout << in.size() << endl;
    for (int i = 0; i < in.size(); i++) {
        cout << in[i] << endl;
    }
    cout << out.size() << endl;
    for (int i = 0; i < out.size(); i++) {
        cout << out[i] << endl;
    }
	return 0;
}