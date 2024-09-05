#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<vector<int>> e(n);
    for (int i = 0; i + 1 < n; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    vector<int> p(n, -1);
    function<void(int)> dfs = [&](int u) {
        for (int &v: e[u]) {
            if (v == p[u]) {
                swap(e[u].back(), v);
                e[u].pop_back();
                break;
            }
        }
        for (int v: e[u]) {
            p[v] = u;
            dfs(v);

        }
    };
    dfs(0);

    /**
     * Finding the maximum independent set in a tree
     * f: Including the root of the subtree
     * g: Excluding the root of the subtree
     */
    vector<int> f(n, 1), g(n);
    dfs = [&](int u) {
        for (int v: e[u]) {
            dfs(v);
            f[u] += g[v];
            g[u] += max(f[v], g[v]);
        }
    };
    dfs(0);

    // Do we have 2 consecutive
    function<bool(int, int, int)> hasConsec = [&](int u, int req, bool dont) {
        cerr << "u = " << u << " req = " << req << " dont = " << dont << '\n';
        if (g[u] >= req) {
            for (auto v: e[u]) {
                if (g[u] - max(f[v], g[v]) + g[v] >= req) {
                    cerr << "v = " << v << '\n';
                    return true;
                }
            }
        }
        if (f[u] >= req and not dont) {
            if (req == 1 and e[u].size()) {
                return true;
            }
            for (auto v: e[u]) {
                if (hasConsec(v, req - (f[u] - g[v]), true)) {
                    return true;
                }
            }
        } else {
            for (auto v: e[u]) {
                if (hasConsec(v, req - (g[u] - max(f[v], g[v])), false)) {
                    return true;
                }
            }
        }
        return false;
    };

    int ans = max(f[0], g[0]) + hasConsec(0, max(f[0], g[0]), false);
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
