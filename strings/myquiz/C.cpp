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

vector<int> prefix_function(string s) {
    int n = s.size();
    vector<int> p(n);
    p[0] = 0;
    for (int i = 1; i < n; i++) {
        int j = p[i - 1];
        while (j > 0 && s[i] != s[j])
            j = p[j - 1];
        if (s[i] == s[j])
            j++;
        p[i] = j;
    }
    return p;
}

int main() {
    vincit_omnia_veritas;
    string prev, s;
    vector<string> v;
    vector<int> occ;
    int n, maxi = 0;
    cin >> prev >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        v.pb(s);
        s[0] = s[0] + 32;
        string temp = s + prev;
        vector<int> p = prefix_function(temp);
        int k = p[p.size() - 1];
        if (k == s.size())
            k--;
        if (k > maxi) {
            maxi = k;
        }
        occ.pb(k);
    }
    if (maxi == 0) {
        cout << "0";
        return 0;
    }
    vector<string> res;
    int cnt = 0;
    for (int i = 0; i < occ.size(); i++) {
        if (occ[i] == maxi) {
            res.pb(v[i]);
            cnt++;
        }
    }
    cout << cnt << endl;
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << endl;
    }
}