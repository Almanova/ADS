#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, x;
    cin >> n;
    vector<int> a;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        a.push_back(x);
    }
    cin >> x;
        int l = 0, r = n - 1, m, cnt = 0;
        while (l <= r)
        {
            m = l + (r - l) / 2;
            if (a[m] >= x)
            {
                r = m - 1;
                cnt = m - 1;
            }
            else
                l = m + 1;
        }
        cout << n - cnt - 1;
    return 0;
}