#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i * i * i <= n; i++)
        for (int j = 0; j * j * j <= n; j++)
            if (i * i * i + j * j * j == n) {
                cout << i << " " << j;
                return 0;
            }
    cout << "impossible";
}