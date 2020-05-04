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
    vector<int> v;
    int n, x, y;
    cin >> n;
    int level = 0, index = 0;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x == 1) {
            cin >> y;
            v.pb(y);
        }
        else if (x == 2) {
            cin >> y;
            level += y;
        }
        else if (x == 3) {
            /*sort(v.begin(), v.end());
            int l = 0, r = v.size() - 1, m, cnt = 0;
            while (l <= r) {
                m = l + (r - l) / 2;
                if (v[m] <= level)
                    l = m + 1;
                else
                    r = m - 1;
            }
            if (l >= v.size())
                cout << "-1" << endl;
            else 
                cout << v[l] << endl;*/
            while (v[index] <= level && index < v.size()) {
                index++;
            }
            if (index >= v.size())
                cout << "-1" << endl;
            else 
                cout << v[index] << endl;
        }
    }
}