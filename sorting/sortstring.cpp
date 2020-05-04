#include <bits/stdc++.h>

#define vincit_omnia_veritas ios_base::sync_with_stdio(0)

using namespace std;

const int MAXCHAR = 26;

string sortstring(string s) {
    int a[MAXCHAR] = {0};
    for (int i = 0; i < s.length(); i++) {
        a[s[i] - 'a']++;
    }
    string sorted = "";
    for (int i = 0; i < MAXCHAR; i++) 
        for (int j = 0; j < a[i]; j++)
            sorted += (char)('a' + i);
    return sorted;
}

int main() {
    vincit_omnia_veritas;
    string s = "maddiekan";
    cout << sortstring(s);
}