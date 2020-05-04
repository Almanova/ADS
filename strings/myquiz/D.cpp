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
    string s;
    cin >> s;
    string res = "";
    for (int i = 0; i < s.size() / 2; i++) {
        if (s[i] != 'A' && s[i] != 'a' && s[i] != 'E' && s[i] != 'e' && s[i] != 'I' && s[i] != 'i' 
            && s[i] != 'O' && s[i] != 'o' && s[i] != 'U' && s[i] != 'u' && s[i] != 'Y' && s[i] != 'y')
        res += s[i];
    }
    string sub = s.substr(s.size() / 2);
    reverse(sub.begin(), sub.end());
    res += sub;
    if (res[0] >= 'a' && res[0] <= 'z')
    res[0] = res[0] - 32;
    cout << res;
}