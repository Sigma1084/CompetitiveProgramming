#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n);
    vector<int> p(n, -1);
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        --x, --y;
        p[y] = x;
        g[x].push_back(y);
    }

    vector<int> a(n);
    for (auto &x: a) {
        cin >> x;
        --x;
    }

    vector<int> d(n);
    vector<bool> vis(n);
    function<void(int)> dfs = [&](int u) {
        vis[u] = true;
        for (auto v: g[u]) {
            d[v] = d[u] + 1;
            dfs(v);
        }
    };
    for (int u = 0; u < n; ++u) {
        if (vis[u]) continue;
        int v = u;
        while (p[v] != -1) {
            v = p[v];
        }
        d[v] = 0;
        dfs(v);
    }

    vis.assign(n, false);
    vector<int> ans;

    // Check from the leaves
    vector<int> ord(n);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int i, int j) {
        return d[i] > d[j];
    });

    for (auto u: ord) {
        if (vis[u]) {
            continue;
        }
        int v = u;
        while (v != a[u]) {
            if (a[v] != a[u]) {
                cout << -1 << '\n';
                return 0;
            }
            if (vis[v]) {
                break;
            }
            vis[v] = true;
            v = p[v];
        }
        if (not vis[v]) {
            vis[v] = true;
            ans.push_back(a[v]);
        }
    }

    cout << ans.size() << '\n';
    for (auto x: ans) {
        cout << x + 1 << '\n';
    }

    return 0;
}
