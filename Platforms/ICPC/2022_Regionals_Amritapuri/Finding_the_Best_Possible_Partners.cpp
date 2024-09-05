#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> p(n, vector<int>(n));
    for (auto &row: p) {
        for (auto &x: row) {
            cin >> x;
            --x;
        }
    }

    vector<vector<int>> g(n), gR(n);
    for (int u = 0; u < n; ++u) {
        for (int v: p[u]) {
            if (v == u) break;
            g[u].push_back(v);
            gR[v].push_back(u);
        }
    }

    // SCC on g

    // Topological ordering
    vector<int> topo; topo.reserve(n);
    vector<bool> vis(n);
    function<void(int)> dfs = [&](int u) {
        if (vis[u]) return;
        vis[u] = true;
        for (int v: g[u]) {
            dfs(v);
        }
        topo.push_back(u);
    };
    for (int u = 0; u < n; ++u) {
        dfs(u);
    }
    reverse(topo.begin(), topo.end());

    // SCC
    vector<int> scc(n, -1);
    int sccCnt = 0;
    function<void(int)> dfs2 = [&](int u) {
        if (scc[u] != -1) return;
        scc[u] = sccCnt;
        for (int v: gR[u]) {
            dfs2(v);
        }
    };
    for (int u: topo) {
        if (scc[u] == -1) {
            dfs2(u);
            ++sccCnt;
        }
    }

    for (int i = 0; i < n; ++i) {
        for (auto j: p[i]) {
            if (scc[i] == scc[j]) {
                cout << j + 1 << '\n';
                break;
            }
        }
    }

    return 0;
}
