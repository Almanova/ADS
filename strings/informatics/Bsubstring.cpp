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
    string s, t;
    cin >> s >> t;
    string temp = t + "#" + s;
    int sz = t.size();
    vector<int> p = prefix_function(temp);
    for (int i = sz + 1; i < temp.size(); i++) {
        if (p[i] == sz) {
            cout << i - sz - sz << " ";
        }
    } 
}