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
    int n, maxi = 0;
    string s, l;
    vector<string> pat;
    vector<int> occ;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        pat.pb(s);
    }
    cin >> l;
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        int sz = pat[i].size();
        string temp = pat[i] + "#" + l;
        vector<int> p = prefix_function(temp);
        for (int i = sz + 1; i < temp.size(); i++) {
            if (p[i] == sz)
                cnt++;
        }
        if (cnt > maxi)
            maxi = cnt;
        occ.pb(cnt);
    }
    cout << maxi << endl;
    for (int i = 0; i < occ.size(); i++) {
        if (occ[i] == maxi) {
            cout << pat[i] << endl;
        }
    }
}