#include <bits/stdc++.h>

#define vincit_omnia_veritas ios_base::sync_with_stdio(0)

using namespace std;

int main() {
    vincit_omnia_veritas;
    long long a = 0, b = 0, j = 0, x, ans;
    cin >> x;
    while (j <= x) {
        long long aa = a * a, bb = b * b * b;
        if (aa < bb) {
            ans = aa;
            a++;
        }
        else if (aa > bb) {
            ans = bb;
            b++;
        }
        else {
            ans = aa;
            a++;
            b++;
        }
        j++;
    }
    cout << ans;
}