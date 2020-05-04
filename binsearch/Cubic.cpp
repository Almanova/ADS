#include <bits/stdc++.h>

using namespace std;

double func(double a, double b, double c, double d) {
    double l = -1001;
    double r = 1001;
    double eps = 0.0000000001;
    while (r - l > eps) {
        double m = l + (r - l) / 2.0;
        if (a * pow(m, 3) + b * pow(m, 2) + c * m + d > 0)
            r = m;
        else 
            l = m;
    }
    return l;
}

int main() {
    double a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << func(a, b, c, d);
}