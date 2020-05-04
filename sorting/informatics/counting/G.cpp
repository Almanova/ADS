#include <bits/stdc++.h>

#define vincit_omnia_veritas ios_base::sync_with_stdio(0)

using namespace std;

const int MAXCHAR = 26;

int main() {
    vincit_omnia_veritas;
    int n;
    string s;
    cin >> n >> s;
    int a[MAXCHAR] = {0};
    for (int i = 0; i < n; i++) {
        a[s[i] - 'A']++;
    }
    int oddmaxi = 0, index = 0;
    for (int i = 0; i < MAXCHAR; i++) {
        if (a[i] % 2 != 0 && a[i] != 0) {
            oddmaxi = a[i];
            index = i;
            break;
        }
    }
    string ans = "";
    for (int i = 0; i < MAXCHAR; i++) {
        if (a[i] != 0 && a[i] % 2 == 0) {
            for (int j = 0; j < (a[i] / 2); j++) {
                ans += ((char)('A' + i));
            }
        }
    }
    if (oddmaxi != 0) {
        for (int i = 0; i < oddmaxi; i++) {
            ans += ((char)('A' + index));
        }
    }
    for (int i = MAXCHAR - 1; i >= 0; i--) {
        if (a[i] != 0 && a[i] % 2 == 0) {
            for (int j = 0; j < (a[i] / 2); j++) {
                ans += ((char)('A' + i));
            }
        }
    }
    cout << ans;
    return 0;
}