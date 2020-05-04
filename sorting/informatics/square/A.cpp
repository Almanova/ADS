#include <bits/stdc++.h>

#define vincit_omnia_veritas ios_base::sync_with_stdio(0);

using namespace std;

const int inf = -1e9;

int main() {
    int n, index = 0, maxi = inf;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] > maxi) {
            maxi = a[i];
            index = i;
        }
    }
    swap(a[0], a[index]);
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
}