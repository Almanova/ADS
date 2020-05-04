#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i * i <= n; i++)
        for (int j = 0; j * j <= n; j++)
            for (int k = 0; k * k <= n; k++)
                for (int m = 0; m * m <= n; m++) {
                    if (i * i + j * j + k * k + m * m == n) {
                        cout << i << " " << j << " " << k << " " << m;
                        return 0;
                    }
                }
}