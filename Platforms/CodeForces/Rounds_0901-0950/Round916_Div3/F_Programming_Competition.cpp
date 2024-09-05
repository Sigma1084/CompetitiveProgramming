#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<int> p(n);
    vector<vector<int>> g(n);
    for (int i = 1; i < n; ++i) {
        cin >> p[i];
        --p[i];
        g[p[i]].push_back(i);
    }

    vector<int> sz(n);
    function<int(int, ll)> dfs = [&](int u, ll av) {
        sz[u] = 1;
        for (auto v: g[u]) {
            dfs(v, av);
            sz[u] += sz[v];
        }
        return 0;
    };
    dfs(0, 0);

    dfs = [&](int u, ll av) -> int {
        sort(g[u].begin(), g[u].end(), [&](int i, int j) {
            return sz[i] > sz[j];
        });
        if (sz[u] <= av or g[u].size() == 0) {
            return (av + sz[u]) / 2;
        }

        int v = g[u][0];
        ll extra = 0;
        for (int i = 1; i < g[u].size(); ++i) {
            extra += sz[g[u][i]];
        }
        return bool(av) + dfs(v, max(0LL, av - 1) + extra);
    };

    cout << dfs(0, 0LL);
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
