#include <bits/stdc++.h>

using namespace std;

int check[20001];

int main() {
    ios_base::sync_with_stdio(0);
    int n, x;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        check[x + 10000]++;
    }
    for (int i = 0; i < 20001; i++) {
        for (int j = 0; j < check[i]; j++) 
            cout << i - 10000 << " ";
    }
}