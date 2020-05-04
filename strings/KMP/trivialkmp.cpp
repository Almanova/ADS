#include <bits/stdc++.h>

using namespace std;

vector<int> prefix_function(string s) {
    int n = s.size();
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            if (s.substr(0, j) == s.substr(i - j + 1, j))
                p[i] = j;
        }
    }
    return p;
}

int main() {
    string s;
    cin >> s;
    vector<int> p = prefix_function(s);
    for (int i = 0; i < p.size(); i++) {
        cout << p[i] << " ";
    }
}