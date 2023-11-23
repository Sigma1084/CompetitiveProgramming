#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, s;
    cin >> n >> m >> s;
    --s;

    vector<vector<int>> g(n), gR(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        gR[v].push_back(u);
    }

    // SCC
    function<void(int)> dfs;

    // DFS 1
    vector<bool> vis(n, false);
    stack<int> st;  // dfs1
    dfs = [&] (int u) {
        vis[u] = true;
        for (int v: g[u]) {
            if (vis[v]) continue;
            dfs(v);
        }
        st.push(u);
    };
    for (int u = 0; u < n; ++u) {
        if (not vis[u]) {
            dfs(u);
        }
    }

    // DFS 2
    vector<int> rep(n);
    iota(rep.begin(), rep.end(), 0);
    vis.assign(n, false);
    dfs = [&] (int u) {
        vis[u] = true;
        for (int v: gR[u]) {
            if (vis[v]) continue;
            rep[v] = rep[u];
            dfs(v);
        }
    };
    while (!st.empty()) {
        int u = st.top(); st.pop();
        if (not vis[u]) {
            dfs(u);
        }
    }

    vector<bool> isSource(n, true);
    for (int u = 0; u < n; ++u) {
        for (int v: g[u]) {
            if (rep[u] != rep[v]) {
                isSource[rep[v]] = false;
            }
        }
    }

    int ans = 0;
    isSource[rep[s]] = false;  // Do not count the capital
    for (int u = 0; u < n; ++u) {
        if (u == rep[u] and isSource[u]) {
            ans += 1;
        }
    }

    cout << ans << '\n';
}
