#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, x, y;
    cin >> n;
    pair<int, int> a[n];
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        pair<int, int> p = make_pair(x, y);
        a[i] = p;
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i].second < a[j].second)
                swap(a[i], a[j]);
            else if (a[i].second == a[j].second) {
                if (a[i].first > a[j].first) 
                    swap(a[i], a[j]);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << a[i].first << " " << a[i].second << endl;
    }
}