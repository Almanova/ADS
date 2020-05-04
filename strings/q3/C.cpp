#include <bits/stdc++.h>

using namespace std;

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
    string s1, s2;
    cin >> s1 >> s2;
    string temp = s2 + s1;
    vector<int> p = prefix_function(temp);
    string temp2 = s1.substr(0, s1.size() - p[p.size() - 1]);
    string ans = temp2 + s2;
    cout << ans;
}