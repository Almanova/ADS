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
    int n, x, cnt = 0;
    cin >> n;
    vector<vector<int> > v;
    for (int i = 0; i < n; i++) {
        vector<int> vec;
        for(int j = 0; j < n; j++) {
            cin >> x;
            vec.pb(x);
        }
        v.pb(vec);
    }
    for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (v[i][j] == 1)
				cout << i + 1 << " " << j + 1 << endl;
		}
	}
	return 0;
}