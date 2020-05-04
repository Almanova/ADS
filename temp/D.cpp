#include <bits/stdc++.h>

using namespace std;

/*bool isPrime(int k) {
    int p = 0;
    for (int i = 1; i <=k; i++)
        if (k % i == 0)
            p++;
    if (p == 2)
        return true;
    return false;
}*/

int isPrime(int num)
{
    if(num <= 1) return 0;
    for (int i = 2; i * i <= num; i++) 
        if (num % i == 0) return 0;
    return 1;
}



int main () {
    int k;
    cin >> k;
    int i = 1;
    int j = 0;
    int m = 0;
    vector<int> v;
    while (m!=k) {
        if (isPrime(i)==true) {
        j++;
        if(isPrime(j)==true) {
        v.push_back(i);
        m++;
        }
        }
        i++;
    }

    cout << v[k-1];
}