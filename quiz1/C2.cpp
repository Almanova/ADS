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
    stack<int> main, reccuring;
    int n, x;
    string s;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        if (s == "add") {
            cin >> x;
            main.push(x);
            if (reccuring.empty() || reccuring.top() <= x) 
                reccuring.push(x);
        }
        else if (s == "delete") {
            if (!main.empty()) {
                if (main.top() == reccuring.top()) {
                    main.pop();
                    reccuring.pop();
                }
                else {
                    main.pop();
                }
            }
        }
        else if (s == "getmax") {
            cout << reccuring.top() << endl;
        }
        else {
            cout << main.top() << endl;
        }
    }
}