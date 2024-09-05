#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<bool> marked(n);
    int markedNode = -1;
    for (int i = 0, m; i < k; ++i) {
        cin >> m; m--;
        markedNode = m;
        marked[m] = true;
    }

    vector<vector<int>> e(n);
    for (int i = 0, u, v; i + 1 < n; ++i) {
        cin >> u >> v;
        --u, --v;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    /**
     * f[u] := Distance of the farthest marked node from u IN THE SUBTREE OF u
     * g[u] := Distance of the farthest marked node from u AWAY FROM THE SUBTREE OF u
     */
    vector<int> f(n, -1), g(n), par(n, -1);

    function<void(int)> dfs;
    dfs = [&](int u) {
        if (marked[u]) {
            f[u] = 0;
        }
        for (auto v: e[u]) {
            if (v == par[u]) continue;
            par[v] = u;
            dfs(v);
            if (f[v] == -1) continue;
            f[u] = max(f[u], f[v] + 1);
        }
    };
    dfs(markedNode);

    g[markedNode] = 0;
    dfs = [&](int u) {
        e[u].erase(std::find(e[u].begin(), e[u].end(), par[u]));
        sort(e[u].begin(), e[u].end(), [&](int x, int y) {
            return f[x] > f[y];
        });
        if (e[u].empty()) return;
        
        for (int i = 1; i < e[u].size(); ++i) {
            int v = e[u][i];
            g[v] = max(g[u] + 1, f[e[u][0]] + 2);
            dfs(v);
        }
        int v = e[u][0];
        g[v] = g[u] + 1;
        if (e[u].size() > 1) {
            g[v] = max(g[v], f[e[u][1]] + 2);
        }
        dfs(v);
    };
    e[markedNode].push_back(par[markedNode]);
    dfs(markedNode);

    int ans = n + 1;
    for (int u = 0; u < n; ++u) {
        ans = min(ans, max(f[u], g[u]));
    }

    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    while (t--) {
        solve();
        cout << '\n';
    }

    return 0;
}
