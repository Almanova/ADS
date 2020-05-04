#include <bits/stdc++.h>

#define vincit_omnia_veritas ios_base::sync_with_stdio(0)
#define pb push_back

using namespace std;

int main() {
    vincit_omnia_veritas;
    vector<int> topics;
    topics.push_back(0);
    map<int, int> connection;
    int n, x, tcnt = 0, mcnt = 0;
    string topic, message;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x == 0) {
            getline(cin, topic);
            topics.pb(1);
            getline(cin, message);
            tcnt++;
            mcnt++;
            connection[mcnt] = tcnt;
        }
        else {
            getline(cin, message);
            mcnt++;
            topics[connection[x]]++;
            connection[mcnt] = connection[x];
        }
    }
    int maxi = 0;
    for (int i = 0; i < topics.size(); i++) {
        if (topics[i] > maxi)
            maxi = topics[i];
    }
    cout << maxi;
}