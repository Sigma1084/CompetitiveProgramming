#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> g(3 * n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].emplace_back(v, i);
        g[v].emplace_back(u, i);
    }

    vector<bool> vis(3 * n);
    vector<int> mat;

    for (int u = 0; u < 3 * n; ++u) {
        if (vis[u]) continue;
        for (auto [v, i]: g[u]) {
            if (vis[v]) continue;
            vis[u] = vis[v] = true;
            mat.push_back(i);
            break;
        }
    }

    if (int(mat.size()) >= n) {
        cout << "Matching\n";
        for (int i = 0; i < n; ++i) {
            cout << mat[i] + 1 << ' ';
        }
    } else {
        cout << "IndSet\n";
        int idx = 0;
        for (int i = 0; idx < n; ++i) {
            if (vis[i]) continue;
            cout << i + 1 << ' ';
            ++idx;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    for (int i = 1; i <= t; ++i) {
        solve();
        cout << '\n';
    }

    return 0;
}
