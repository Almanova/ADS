#include <bits/stdc++.h>

#define vincit_omnia_veritas ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(a) (a).begin(), (a).end()
#define sz(a) ((int)(a).size())

using namespace std;

const int inf = (int)1e9;
const double eps = (int)1e-9;

vector<int> odd_Manacher(string &s) {
    int n = sz(s);
    vector<int> d1(n);
    for (int i = 0, l = 0, r = -1; i < n; i++) {
        int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
        while (0 <= i - k && i + k < n && s[i - k] == s[i + k]) {
            k++;
        }
        d1[i] = k--;
        if (i + k > r) {
            l = i - k;
            r = i + k;
        }
    }
    return d1;
}

vector<int> even_Manacher(string &s) {
    int n = sz(s);
    vector<int> d2(n);
    for (int i = 0, l = 0, r = -1; i < n; i++) {
        int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);
        while (0 <= i - k - 1 && i + k < n && s[i - k - 1] == s[i + k]) {
            k++;
        }
        d2[i] = k--;
        if (i + k > r) {
            l = i - k - 1;
            r = i + k ;
        }
    }
    return d2;
}

int main() {
    vincit_omnia_veritas;
    int t;
    cin >> t;
    string s;
    while(t--) {
        cin >> s;
        int l = 0, r = sz(s) - 1, cnt = 0;
        while (s[l] == s[r] && l < r) {
            cnt++;
            l++;
            r--;
        }
        string str = s.substr(cnt, sz(s) - 2 * cnt);
        vector<int> odd = odd_Manacher(str);
        vector<int> even = even_Manacher(str);
        int maxi = 0;
        bool left = false;
        for (int i = 0; i < sz(odd); i++) {
            if (odd[i] * 2 - 1 > maxi) {
                if (i - odd[i] + 1 == 0) {
                    left = true;
                    maxi = odd[i] * 2 - 1;
                }
                else if (i + odd[i] == sz(str)) {
                    left = false;
                    maxi = odd[i] * 2 - 1;
                }
            }
            if (even[i] * 2 > maxi) {
                if (i - even[i] == 0) {
                    left = true;
                    maxi = even[i] * 2;
                }
                else if (i + even[i] == sz(str)) {
                    left = false;
                    maxi = even[i] * 2;
                }
            }
        }
        string ans = "";
        if (left) 
            ans = s.substr(0, cnt) + str.substr(0, maxi) + s.substr(sz(s) - cnt, cnt);
        else 
            ans = s.substr(0, cnt) + str.substr(sz(str) - maxi, maxi) + s.substr(sz(s) - cnt, cnt);
        cout << ans << endl;
    }
    return 0;
}