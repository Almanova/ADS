#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    long long sum = 0;
    for (int i = 0; i < s.length(); i++) {
        sum += (s[i] - '0');
    }
    if (sum % 3 == 0)
        cout << "YES";
    else 
        cout << "NO";
}