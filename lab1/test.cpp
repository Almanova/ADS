#include <iostream>

using namespace std;

struct node{
    int val;
    node * next;
};

int main(){

    node n1;
    n1.val = 5;

    node n2;
    n2.val = 6;

    n1.next = &n2;

    cout << n1.next->val << endl;

    return 0; 
}

/*long long sumOfFactors(int n) {
    long long sum = 1, temp = n, ans = 0;
    for (long long i = 2; i * i < n; i++) {
        long long cursum = 1;
        long long curterm = 1;
        while (n % i == 0) {
            n /= i;
            curterm *= i;
            cursum += curterm;
        }
        sum *= cursum;
    }
    if (n > 1)
        sum *= (1 + n);

    ans = sum - temp;

    return ans;
}*/