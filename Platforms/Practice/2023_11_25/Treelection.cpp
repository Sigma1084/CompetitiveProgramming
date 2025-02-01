#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<int> p(n);
    vector<vector<int>> e(n);
    for (int i = 1; i < n; ++i) {
        cin >> p[i];
        --p[i];
        e[p[i]].push_back(i);
    }

    vector<int> sz(n);
    function<void(int)> dfs = [&](int u) {
        sz[u] = 1;
        for (auto v: e[u]) {
            dfs(v);
            sz[u] += sz[v];
        }
    };
    dfs(0);

    /**
     * Maximum a node can get is sz(u) - 1
     * 
     */

    string ans(n, '0');
    for (int u = 0; u < n; ++u) {
        if (sz[u] - 1 > n - sz[u] + 1) {
            ans[u] = '1';
        }
    }

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
