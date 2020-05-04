#include <bits/stdc++.h>

using namespace std;

int gcd (int a, int b) {
	if (b == 0)
		return a;
	else
		return gcd (b, a % b);
}

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int y = (b * d) / gcd(b, d);
    int x = a * (y / b) + c * (y / d);
    int temp = gcd(y, x);
    x /= temp;
    y /= temp;
    cout << x << " " << y;
}