#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k, x;
    cin >> n;
    int capacity[n], work[n] = {0};
    for (int i = 0; i < n; i++) {
        cin >> capacity[i];
    }
    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> x;
        work[x - 1]++;
    }
    for (int i = 0; i < n; i++) {
        if (work[i] <= capacity[i])
            cout << "no" << endl;
        else 
            cout << "yes" << endl;
    }
}