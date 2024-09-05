#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<vector<int>> g(n);
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    auto isPossible = [&](int x) -> bool {
        int cnt = 0;
        function<int(int, int)> dfs = [&](int u, int p) -> int {
            int sz = 1;
            for (auto v: g[u]) {
                if (v != p) {
                    sz += dfs(v, u);
                }
            }
            if (sz >= x) {
                ++cnt;
                sz = 0;
            }
            return sz;
        };
        dfs(0, -1);
        return cnt >= k + 1;
    };

    // Can we have at least k + 1 components with at least x
    int l = 1, r = n / (k + 1);

    while (l <= r) {
        int m = (l + r) / 2;
        if (isPossible(m)) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }

    cout << r;
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
