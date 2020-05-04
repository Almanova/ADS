#include <bits/stdc++.h>

using namespace std;

int x, y;

int gcd (int a, int b, int & x, int & y) {
	if (a == 0) {
		x = 0; y = 1;
		return b;
	}
	int x1, y1;
	int d = gcd (b%a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	return d;
}

/*int gcdExtended(int a, int b, int *x, int *y) 
{ 
    // Base Case 
    if (a == 0) 
    { 
        *x = 0; 
        *y = 1; 
        return b; 
    } 
  
    int x1, y1; // To store results of recursive call 
    int gcd = gcdExtended(b%a, a, &x1, &y1); 
  
    // Update x and y using results of recursive 
    // call 
    *x = y1 - (b/a) * x1; 
    *y = x1; 
  
    return gcd; 
} */

int main() {
    ios_base::sync_with_stdio(0);
    int a, b, c;
    cin >> a >> b >> c;
    int g = gcd(a, b, x, y);
    if (c % g == 0) {
        c /= g;
        cout << g << " " << x * c << " " << y * c; 
    }
    else 
        cout << "Impossible";
}