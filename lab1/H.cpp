#include <bits/stdc++.h>

using namespace std;

int main() {
    long long n;
    cin >> n;
    bool isComposite = false;
    for (long long l = 2; l * l <= n; l++) {
        if (n % l == 0) {
            isComposite = true;
            break;
        }
    }
    if (isComposite)
        cout << "composite";
    else 
        cout << "prime";
}