#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    int a, b;
    cin >> a >> b;
    --a, --b;

    vector<vector<int>> g(n);
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    if (n == 1) {
        cout << 0;
        return;
    }

    vector<int> p(n, -1), d(n), w(n, 1);
    function<void(int)> dfs = [&](int u) {
        for (auto v: g[u]) {
            if (v != p[u]) {
                p[v] = u;
                d[v] = d[u] + 1;
                dfs(v);
                w[u] += w[v];
            }
        }
    };
    dfs(a);

    int dy = d[b] / 2;
    int ans = 0;
    while (d[b] > dy) {
        b = p[b];
        ++ans;
    }

    p.assign(n, -1);
    d.assign(n, 0);
    w.assign(n, 1);
    dfs(b);

    // From b, we need to find the least time to touch all the nodes
    vector<int> dp(n);
    dfs = [&](int u) {
        for (auto v: g[u]) {
            if (v != p[u]) {
                dfs(v);
            }
        }
        if (g[u].size() == 1 and u != b) {
            dp[u] = 0;
            return;
        }
        int vv = -1;
        for (auto v: g[u]) {
            if (v != p[u] and (vv == -1 or dp[v] - 2*w[v] < dp[vv] - 2*w[vv])) {
                vv = v;
            }
        }
        for (auto v: g[u]) {
            if (v != p[u]) {
                dp[u] += 2 * w[v];
            }
        }
        dp[u] -= 2 * w[vv];
        dp[u] += dp[vv] + 1;
    };
    dfs(b);
    ans += dp[b];

    cout << ans;
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
