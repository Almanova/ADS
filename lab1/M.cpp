#include <bits/stdc++.h>

using namespace std;

int main() {
    long long m = 0, temp = 0;
    long long n;
    cin >> n;
    for (long long i = 1; i < 30000000; i++) {
        m = (m * 10 + 1) % n;
        if (m == 0) {
            temp = i;
            break;
        }
    }
    if (temp != 0) {
        string s(temp, '1');
        cout << s;
    }
    else 
        cout << "NO";
}