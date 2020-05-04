#include <bits/stdc++.h>

#define vincit_omnia_veritas ios_base::sync_with_stdio(0)

using namespace std;

int main() {
    vincit_omnia_veritas;
    int n, m, x;
    cin >> n;
    set<int> s1, s2;
    for (int i = 0; i < n; i++) {
        cin >> x;
        s1.insert(x);
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> x;
        s2.insert(x);
    }
    if (s1 == s2)
        cout << "YES";
    else 
        cout << "NO";
}