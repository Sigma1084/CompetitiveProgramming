#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;

    vector<vector<int>> e(n);
    for (int i = 0; i < n-1; ++i) {
        int u, v; cin >> u >> v;
        --u; --v;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    vector<int> p(n, -1);
    vector<int> d(n, 0);

    function<void(int)> dfs;
    dfs = [&] (int u) {
        for (int v: e[u]) {
            if (v == p[u]) continue;
            p[v] = u;
            d[v] = d[u] + 1;
            dfs(v);
        }
    };

    dfs(0);

    // DFS from a
    int a = 0;
    for (int u = 0; u < n; ++u) {
        if (d[u] > d[a]) a = u;
    }
    p = vector(n, -1);
    d = vector(n, 0);
    dfs(a);
    auto da = d;

    // DFS from b
    int b = 0;
    for (int u = 0; u < n; ++u) {
        if (d[u] > d[b]) b = u;
    }
    p = vector(n, -1);
    d = vector(n, 0);
    dfs(b);
    auto db = d;

    // Find c
    int c = -1;
    int diam = db[a];  // Diameter
    int ans = -1, cur;
    for (int u = 0; u < n; ++u) {
        if (u == a or u == b) continue;
        cur = (da[u] + db[u] - diam) / 2;
        if (cur > ans) {
            ans = cur;
            c = u;
        }
    }

    cout << ans + diam << '\n';
    cout << a+1 << ' ' << b+1 << ' ' << c+1 << '\n';

    return 0;
}
