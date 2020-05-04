#include <bits/stdc++.h>

#define si set<int>
#define MaddieKan ios_base::sync_with_stdio(0)

using namespace std;

int main() {
    MaddieKan;
    si s;
    int n, x;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        s.insert(x);
    }
    cout << s.size();
}