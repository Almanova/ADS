#include <bits/stdc++.h>

using namespace std;

long long divSum(long long n) 
{ 
    long long result = 0; 
    for (long long i = 2; i <= sqrt(n); i++) 
    {  
        if (n % i == 0) 
        { 
            if (i == (n / i)) 
                result += i; 
            else
                result += (i + n/i); 
        } 
    } 
    return (result + 1); 
} 

int main() {
    ios_base::sync_with_stdio(0);
    long long k;
    cin >> k;
    for (long long i = 1; i <= k; i++) {
        long long s = divSum(i);
        if (i < s && s < k && divSum(s) == i) {
            cout << i << " " << s << endl;
        }
    }
}