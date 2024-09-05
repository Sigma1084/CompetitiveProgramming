#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, m, nS, s, t;
    cin >> n >> m >> nS >> s >> t;

    vector<int> a(nS);
    for (auto &x: a) {
        cin >> x;
    }

    vector<vector<int>> g(n);
    vector<array<int, 2>> e(m);
    for (int i = 0; i < m; ++i) {
        auto &[u, v] = e[i];
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    auto bfs = [&](int u) {
        vector<int> d(n, INT_MAX);
        d[u] = 0;
        queue<int> q;
        q.push(u);
        while (!q.empty()) {
            u = q.front(); q.pop();
            for (int v: g[u]) {
                if (d[v] == INT_MAX) {
                    d[v] = d[u] + 1;
                    q.push(v);
                }
            }
        }
        return d;
    };

    auto ds = bfs(s);
    auto dt = bfs(t);

    ll m1 = 0;
    map<array<int, 2>, int> mp;
    for (int u = 0; u < n; ++u) {
        if (u == s or u == t) continue;
        for (int dds = -1; dds <= 1; ++dds) {
            for (int ddt = -1; ddt <= 1; ++ddt) {
                if (mp.count({ds[u] + dds, ds[t] + ddt})) {
                    m1 += mp.at({ds[u] + dds, ds[t] + ddt});
                }
            }
        }
        mp[{ds[u], ds[t]}]++;       
    }

    m1 -= m;

    if (ds[t] > 1) {
        bool ok = true;
        for (int u = 0; u < n; ++u) {
            if (abs(ds[u] - ds[t]) > 1) {
                ok = false;
            }
        }
        m1 += ok;
    }

    cout << m1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    while(t--) {
        solve();
        cout << '\n';
    }
}