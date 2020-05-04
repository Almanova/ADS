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
    string s1, s2, t;
    cin >> s1 >> s2 >> t;
    string temp1 = t + "#" + s1;
    string temp2 = t + "#" + s2;
    int sz = t.size();
    bool check[s1.length()] = {false};
    vector<int> p1 = prefix_function(temp1);
    vector<int> p2 = prefix_function(temp2);
    for (int i = sz + 1; i < temp1.size(); i++) {
        if (p1[i] == sz)
            check[i - sz - sz]= true;
    } 
    int cnt = 0;
    for (int i = sz + 1; i < temp2.size(); i++) {
        if (p2[i] == sz && check[i - sz - sz])
            cnt++;
    } 
    cout << cnt;
}