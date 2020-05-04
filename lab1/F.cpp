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
    long long arr[1000001];
    for (long long n = 1; n <= 1000000; n++) {
        arr[n] = divSum(n);
    }

    long long k;
    cin >> k;
    bool d[1000001];
    for (long long i = 1; i <= k; i++) {
        if (i == arr[arr[i]] && (!d[i] && !d[arr[i]]) && i != arr[i]) {
            cout << i << " " << arr[i] << endl;
        }
        d[i] = true;
    }
}