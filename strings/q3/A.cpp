#include <bits/stdc++.h>

using namespace std;

int main() {
    long long n, h;
    vector<long long> hashes;
    string ans = "";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> h;
        hashes.push_back(h);
    }
    long long temp = hashes[0] + 97;
    char c = temp;
    ans += c;
    for (int i = 1; i < n; i++) {
        temp = hashes[i] - hashes[i - 1];
        c = temp / pow(2, i) + 97;
        ans += c;
    }
    cout << ans;
    return 0;
}