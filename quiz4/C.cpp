#include <bits/stdc++.h>

#define vincit_omnia_veritas ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
#define pb push_back
#define mp make_pair
#define F first
#define S second

using namespace std;

const int inf = (int)1e9;
const double eps = (int)1e-9;
const int maxchar = 26;

int main() {
    vincit_omnia_veritas;
    int n, x;
    cin >> n;
    deque<int> order;
    stack<int> side;
    order.push_back(0);
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x == 1 || x - 1 == order.back())
            order.push_back(x);
        else 
            side.push(x);
    }
    int temp = order.back();
        while(!side.empty()) {
            if (side.top() != temp + 1) {
                cout << "no" << endl;
                return 0;
            }
            temp = side.top();
            side.pop();
        }
    cout << "yes" << endl;
    return 0;
}