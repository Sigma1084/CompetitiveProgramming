#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> e(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    vector<int> d(n, -1);
    queue<int> q;
    q.push(0);
    d[0] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v: e[u]) {
            if (d[v] != -1) continue;
            d[v] = d[u] + 1;
            q.push(v);
        }
    }

    int k = ceil(sqrt(n)) + 1;
    vector<vector<int>> g(k);
    for (int i = 0; i < n; ++i) {
        g[d[i] % k].push_back(i);
    }

    for (int i = 0; i < k; ++i) {
        if (g[i].size() > 0 and g[i].size() < k) {
            cout << g[i].size() << '\n';
            for (int u: g[i]) {
                cout << u + 1 << ' ';
            }
            return;
        }
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

// 01:26:49