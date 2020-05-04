#include <bits/stdc++.h>

using namespace std;

int gcd (int a, int b) {
	if (b == 0)
		return a;
	else
		return gcd (b, a % b);
}

int main() {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int difx = abs(x2 - x1);
    int dify = abs(y2 - y1);
    cout << gcd(difx, dify) + 1;
}