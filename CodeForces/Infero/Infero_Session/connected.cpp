#include <bits/stdc++.h>
using namespace std;

vector<bool> visited;
vector<vector<int>> adj;

void dfs(int u) {
    visited[u] = true;
    for (auto &v: adj[u]) {
        if (visited[v] == false) {
            dfs(v);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;  // Number of nodes, edges

    adj.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        adj[i].clear();
    }
    
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int ans = 0;

    visited.resize(n+1, false);
    for (int i = 1; i <= n; i++) {
        if (visited[i] == false) {
            dfs(i);
            ans++;  // Our answer is the number of times we run dfs
        } else {
            // Do nothing
        }
    }

    cout << ans << '\n';
    return 0;
}
