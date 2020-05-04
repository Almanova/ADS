#include <bits/stdc++.h>

using namespace std;

double func(double x, int n) {
    double l;
    double r;
    if (x >= 0 && x <= 1) { 
        l = x;
        r = 1;
    }
    else  {
        l = 1;
        r = x;
    }

    double eps = 0.000000000001;
    while (r - l > eps) {
        double m = l + (r - l) / 2.0;
        if (pow(m, n) > x)
            r = m;
        else 
            l = m;
    }
    return l;
}

int main() {
    double x;
    int n;
    cin >> x >> n;
    printf("%.10f", func(x, n));
    return 0;
}