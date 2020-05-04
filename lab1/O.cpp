#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    int a, b, cnt = 0;
    cin >> a >> b;
    while (a > 0 && b > 0) {
        if (a < b) {
            int temp = a;
            a = b;
            b = temp;
        }
        a -= b;
        cnt++;
    }
    cout << cnt;
}