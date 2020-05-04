#include <bits/stdc++.h>

using namespace std;

double func(double x) {
    double l = 1;
    double r = x;
    double eps = 0.0000000001;
    while (r - l > eps) {
        double m = l + (r - l) / 2.0;
        if (m * m + sqrt(m) > x)
            r = m;
        else 
            l = m;
    }
    return l;
}

int main() {
    double x;
    cin >> x;
    printf("%.10f", func(x));
}