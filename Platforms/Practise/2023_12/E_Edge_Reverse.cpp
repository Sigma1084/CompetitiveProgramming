#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> kosaraju(const vector<vector<int>> &g) {
    int n = static_cast<int>(g.size());

    vector<bool> vis(n, false);
    vector<int> ord;

    function<void(int)> dfs = [&](int u) {
        if (vis[u]) return;
        vis[u] = true;
        for (auto v: g[u]) {
            dfs(v);
        }
        ord.push_back(u);
    };

    for (int i = 0; i < n; ++i) {
        dfs(i);
    }
    reverse(ord.begin(), ord.end());

    vector<int> comp(n, -1);
    vis.assign(n, false);

    vector<vector<int>> gT(n);
    for (int u = 0; u < n; ++u) {
        for (auto v: g[u]) {
            gT[v].push_back(u);
        }
    }

    function<void(int, int)> dfs2 = [&](int u, int c) {
        if (vis[u]) return;
        vis[u] = true;
        comp[u] = c;
        for (auto v: gT[u]) {
            dfs2(v, c);
        }
    };

    for (auto u: ord) {
        dfs2(u, u);
    }

    return comp;
}

void solve() {
    int n, m;
    cin >> n >> m;

    vector<array<int, 3>> edges(m);
    vector<vector<int>> g0(n);
    for (auto &[u, v, w] : edges) {
        cin >> u >> v >> w;
        --u, --v;
        g0[u].push_back(v);
    }
    sort(edges.begin(), edges.end(), [](auto &a, auto &b) {
        return a[2] < b[2];
    });

    function<bool(int)> isPossible = [&](int idx) -> bool {
        vector<vector<int>> g = g0;
        for (int i = 0; i < idx; ++i) {
            auto &[u, v, w] = edges[i];
            g[v].push_back(u);
        }

        auto comp = kosaraju(g);

        vector<int> p(n, -1);
        vector<int> inDeg;
        for (int i = 0; i < n; ++i) {
            int u = comp[i];
            if (p[u] == -1) {
                p[u] = inDeg.size();
                inDeg.push_back(0);
            }
            for (auto v: g[i]) {
                v = comp[v];                
                if (p[v] == -1) {
                    p[v] = inDeg.size();
                    inDeg.push_back(0);
                }
                if (u != v) {
                    inDeg[p[v]]++;
                }
            }
        }

        return std::ranges::count(inDeg, 0) == 1;
    };

    isPossible(m);

    int l = 0, r = m;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (isPossible(mid)) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    if (l == m + 1) {
        cout << -1;
    } else if (l == 0) {
        cout << 0;
    } else {
        cout << edges[l-1][2];
    }
}   

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;

    for (int i = 1; i <= t; ++i) {
        solve();
        std::cout << '\n';
    }

    return 0;
}
