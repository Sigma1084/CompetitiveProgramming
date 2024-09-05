#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<vector<int>> g(n);
    for (int i = 0; i + 1 < n; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    function<void(int)> dfs;

    vector<int> d(n, -1), p(n);
    dfs = [&](int u) {
        for (int v: g[u]) {
            if (v == p[u]) continue;
            d[v] = d[u] + 1;
            p[v] = u;
            dfs(v);
        }
    };
    d[0] = 0;
    p[0] = -1;
    dfs(0);

    vector<int> ord(n);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int u, int v) {
        return d[u] > d[v];
    });

    vector<int> f(n, -1);
    for (int u: ord) {
        if (f[u] != -1) continue;
        f[u] = 1;
        int v = p[u];
        while (v != -1 and f[v] == -1) {
            f[v] = 0;
            f[u] += 1;
            v = p[v];
        }
    }

    sort(ord.begin(), ord.end(), [&](int u, int v) {
        return f[u] > f[v];
    });

    ll ans = -1LL * (n / 2) * (n - n / 2);
    for (int r = 1, b = n; r <= k; ++r) {
        b -= f[ord[r-1]];
        ll cur = 1LL * r * (n - r);
        cur -= 1LL * min(b, n/2) * (n - min(b, n/2));
        ans = max(ans, cur);
    }

    cout << ans;

    return 0;
}
