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
    string a, b;
    cin >> a >> b;
    if (a.size() < b.size()) 
        swap(a, b);

    int asize = a.size(), bsize = b.size();

    if (a == b) {
        cout << a;
        return 0;
    }

    int start = bsize - 1;
    for (int i = 0; i < asize; i++) {
        int k = i;
        int l = start;
        while(l < )
    }
}