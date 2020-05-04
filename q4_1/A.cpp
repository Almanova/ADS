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

vector<int> get_hash(string s) {
    int n = s.size();
    vector<int> h(n);
    h[0] = s[0];
    int p = 31;
    int p_pow = 1;
    for (int i = 1; i < n; i++) {
        p_pow *= p;
        h[i] = h[i - 1] + s[i] * p_pow;
    }
    return h;
}

int get_h(string s) {
    int h_s = 0;
    int p = 31, p_pow = 1;
    for (int i = 0; i < s.size(); i++) {
        h_s += s[i] * p_pow;
        p_pow *= p;
    }
    return h_s;
}

int main() {
    vincit_omnia_veritas;
    string x, s;
    int n;
    cin >> x >> n >> s;
    vector<int> h_s = get_hash(s);
    vector<int> pows;
    pows.pb(1);
    for (int i = 1; i < s.size(); i++) {
        pows.pb(pows[i - 1] * 31);
    }
        int temp = 0;
        int sz = x.size();
        int x_h = get_h(x);
        for (int j = 0; j < h_s.size() - sz + 1; j++) {
            int k = j + sz - 1;
            int h_i_j = h_s[k];
            if (j > 0)
                h_i_j -= h_s[j - 1];
            if (x_h * pows[j] == h_i_j)
                temp++;
        }
        if (temp >= n)
            cout << "YES" << endl;
        else 
            cout << "NO" << endl;
}