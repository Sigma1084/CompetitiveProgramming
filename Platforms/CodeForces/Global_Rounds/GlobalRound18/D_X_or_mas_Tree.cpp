#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<array<int, 3>> edges(n - 1);
    vector<vector<array<int, 2>>> e(n);
    for (auto &[u, v, w]: edges) {
        cin >> u >> v >> w;
        --u, --v;
        // Number of bits in w
        int ww = (w >= 0) ? __builtin_popcount(w) : w;
        e[u].push_back({v, ww & 1});
        e[v].push_back({u, ww & 1});
    }

    vector<vector<array<int, 2>>> g(n);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        w = __builtin_popcount(w) & 1;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    for (auto [u, v, w]: edges) {
        if (w == -1) {
            continue;
        }
        w = __builtin_popcount(w) & 1;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    vector<int> r(n, -1);
    bool ok = true;
    function<void(int)> dfs = [&](int u) {
        for (auto [v, w]: g[u]) {
            if (r[v] != -1) {
                if (r[v] != (r[u] ^ w)) {
                    ok = false;
                    return;
                }
            } else {
                r[v] = r[u] ^ w;
                dfs(v);
                if (not ok) {
                    return;
                }
            }
        }
    };

    for (int u = 0; u < n; ++u) {
        if (r[u] == -1) {
            r[u] = 0;
            dfs(u);
            if (not ok) {
                break;
            }
        }
    }

    if (not ok) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    for (auto &[u, v, w]: edges) {
        if (w == -1) {
            w = r[u] ^ r[v];
        }
        cout << u + 1 << ' ' << v + 1 << ' ' << w << '\n';
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
