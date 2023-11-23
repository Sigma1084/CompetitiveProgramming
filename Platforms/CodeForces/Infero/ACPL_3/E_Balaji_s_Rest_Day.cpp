#include <bits/stdc++.h>
using namespace std;

/**
 * f[u] := Time taken to go through
 *   the subtree rooted at u and come back to u
 * g[u] := Time taken to finish from
 *   the subtree rooted at u
 * 
 * We need g[0] 
 */

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<pair<int, int>>> e(n);
    for (int i = 0; i + 1 < n; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u; --v;

        e[u].emplace_back(v, w);
        e[v].emplace_back(u, w);
    }

    vector<long long> f(n), g(n);

    function<void(int, int)> dfs = [&](int u, int p) -> void {
        // We want to compute f[u] and g[u]
        for (auto [v, w]: e[u]) {
            if (v == p) continue;
            dfs(v, u);
            f[u] += f[v] + 2 * w; 
        }
        // Go to one path g[v_0] where sum f[v] + w_0 + g[v_0] is min
        g[u] = f[u];
        for (auto [v, w]: e[u]) {
            if (v == p) continue;
            g[u] = min(g[u], f[u] - f[v] - w + g[v]);
        }
    };

    dfs(0, -1);

    cout << g[0] << '\n';

    return 0;
}
