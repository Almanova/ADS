#include <bits/stdc++.h>

using namespace std;

bool isPrime(int n) {
    for (int i = 2; i * i < n; i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    string ans = "";
    for (int i = 2; i * i <= n; i++) {
        int cur = i;
        int cnt = 0;
        while (n % i == 0 && isPrime(i)) {
            cnt++;
            n /= i;
        }
        if (cnt != 0 && cnt > 1) {
            ans += to_string(cur);
            ans += "^";
            ans += to_string(cnt);
            ans += "*";
        }
        else if (cnt != 0 && cnt == 1) {
            ans += to_string(cur);
            ans += "*";
        }
    }
    if (n > 1)
        ans += to_string(n);

    if (ans[ans.size() - 1] == '*')
        ans.pop_back();
    
    cout << ans;
    
    return 0;

}