#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    string s, s1;
    cin >> s >> s1;
    sort(s.begin(), s.end());
    sort(s1.begin(), s1.end());
    if (s == s1)
        cout << "YES";
    else 
        cout << "NO";
}