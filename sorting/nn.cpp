#include <bits/stdc++.h>

using namespace std;

int bfs(vector<vector<int> >graph, vector<int> used, int node) {
    cout << node << " ";
    int ans = 1;
    for (int neighbour = 0; neighbour < graph[node].size(); neighbour++) {
        if (used[neighbour] == 0) {
            used[neighbour] = 1;
            ans = max(ans, bfs(graph, used, neighbour) + 1);
            used[neighbour] = 0;
        }
    }
    return ans;
}

int main() {
    vector<vector<int> > v;
    for (int i = 0; i < 8; i++) {
        vector<int> vec;
        v.push_back(vec);
    }
    int n, m, x, y;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        v[x].push_back(y);
    }

    for(int i = 0; i < v.size(); i ++){
        cout << i << " ";
        for(int j = 0; j < v[i].size(); j++){
            cout << v[i][j];
        }
        cout << "\n";
    }

    int ans = 0;
    vector<int> used(7, 0);

    for(int node = 0; node < 8; node ++){
        ans = max(ans, bfs(v, used, node));
    }
    cout << ans;
}
