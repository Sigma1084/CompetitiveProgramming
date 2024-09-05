#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<int> c(n);
    for (auto &x: c) {
        cin >> x;
        --x;
    }

    vector<vector<int>> g(n);
    for (int i = 0; i + 1 < n; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<map<int, int>> mp(n);
    ll ans = 0;

    function<void(int, int)> dfs = [&](int u, int p) {
        for (auto v: g[u]) {
            if (v == p) {
                continue;
            }
            dfs(v, u);
            if (mp[v].count(c[u])) {
                ans += mp[v][c[u]];
                mp[v].erase(c[u]);
            }
            if (mp[u].size() < mp[v].size()) {
                swap(mp[u], mp[v]);
            }
            for (auto [col, fr]: mp[v]) {
                ans += 1LL * fr * mp[u][col];
                mp[u][col] += fr;
            }
            mp[v].clear();
        }
        mp[u][c[u]] = 1;
    };
    dfs(0, -1);

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
