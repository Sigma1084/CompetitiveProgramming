#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<ll> a(n);
    for (auto &x: a) {
        cin >> x;
    }

    vector<vector<int>> g(n);
    for (int i = 0; i + 1 < n; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    const int K = __lg(n);
    vector dpL(n, vector(K + 3, 0LL)), dpR(n, vector(K + 3, 0LL));

    function<void(int, int)> dfs = [&](int u, int p) {
        dpL[u].front() = LLONG_MAX, dpL[u].back() = LLONG_MAX;
        for (auto v: g[u]) {
            if (v == p) continue;
            dfs(v, u);
            for (int i = 1; i <= K + 1; ++i) {
                dpL[u][i] += min(dpL[v][i-1], dpR[v][i+1]);
            }
        }
        for (int i = 1; i <= K + 1; ++i) {
            dpL[u][i] += a[u] * i;
        }

        dpR[u] = dpL[u];
        for (int i = 1; i <= K + 1; ++i) {
            dpL[u][i] = min(dpL[u][i], dpL[u][i-1]);
        }
        for (int i = K + 1; i >= 1; --i) {
            dpR[u][i] = min(dpR[u][i], dpR[u][i+1]);
        }
    };
    dfs(0, n);

    cout << dpR[0][1];
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
