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
    int n, m, x;
    cin >> n >> m;
    map<int, int> mapp;
    vector<int> a, b, temp;
    for (int i = 0; i < n; i++) {
        cin >> x;
        mapp[x]++;
        a.pb(x);
    }
    for (int i = 0; i < m; i++) {
        cin >> x;
        b.pb(x);
    }
    for (int i = 0; i < n; i++) {
        bool exist = false;
        for (int j = 0; j < m; j++) {
            if (a[i] == b[j]) {
                exist = true;
                break;
            }
        }
        if (!exist)
            temp.pb(a[i]);
    }
    for (int i = 0; i < m; i++) {
        if (mapp[b[i]] != 0) {
            for (int j = 0; j < mapp[b[i]]; j++) {
                cout << b[i] << " ";
            }
        }
    }
    sort(temp.begin(), temp.end());
    for (int i = 0; i < temp.size(); i++) {
        cout << temp[i] << " ";
    }
    //for (auto it = mapp.begin(); it != mapp.end(); it++) {
        //cout << (*it).F << " " << (*it).second << endl;
    //}
}