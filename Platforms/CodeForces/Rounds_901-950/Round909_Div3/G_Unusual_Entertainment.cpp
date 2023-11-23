#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, q;
    cin >> n >> q;

    vector<vector<int>> e(n);
    for (int i = 0; i + 1 < n; ++i) {
        int x, y;
        cin >> x >> y;
        --x, --y;
        e[x].push_back(y);
        e[y].push_back(x);
    }

    vector<int> p(n);
    for (auto &x: p) {
        cin >> x;
        --x;
    }

    vector<int> ip(n);
    for (int i = 0; i < n; ++i) {
        ip[p[i]] = i;
    }

    // [l, r, idx]
    vector<vector<array<int, 3>>> queries(n);
    vector<bool> ans(q);

    for (int i = 0; i < q; ++i) {
        int l, r, x;
        cin >> l >> r >> x;
        --l, --r, --x;
        queries[x].push_back({l, r, i});
    }

    // At every level, we maintain a set ?
    vector<int> sz(n);

    function<void(int)> dfsSz = [&](int u) {
        sz[u] = 1;
        for (int v: e[u]) {
            if (sz[v] == 0) {
                dfsSz(v);
                sz[u] += sz[v];
                // Remove u from e[v]
                e[v].erase(ranges::find(e[v], u));
            }
        }
    };
    dfsSz(0);

    for (auto &v: e) {
        sort(v.begin(), v.end(), [&](int v1, int v2) {
            return sz[v1] > sz[v2];
        });
    }

    // For every node, we will have queries
    function<set<int>(int)> dfs = [&](int u) -> set<int> {
        set<int> res;
        if (e[u].size() == 0) {
            res.insert(ip[u]);
        } else {
            res = dfs(e[u][0]);
            for (auto v: e[u] | views::drop(1)) {
                auto s = dfs(v);
                res.insert(s.begin(), s.end());
            }
            res.insert(ip[u]);
        }

        // Process for u
        for (auto [l, r, idx]: queries[u]) {
            // Compute for l, r, idx
            auto lb = res.lower_bound(l);
            if (lb == res.end() or *lb > r) {
                ans[idx] = false;
            } else {
                ans[idx] = true;
            }
        }

        return res;
    };
    dfs(0);

    for (auto ok: ans) {
        cout << (ok ? "YES" : "NO") << '\n';
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
