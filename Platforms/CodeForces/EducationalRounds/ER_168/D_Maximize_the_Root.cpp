#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (auto &x: a) {
        cin >> x;
    }

    vector<vector<int>> g(n);
    for (int u = 1; u < n; ++u) {
        int p;
        cin >> p;
        --p;
        g[p].push_back(u);
    }

    function<void(int)> dfs = [&](int u) {
        if (g[u].empty()) return;
        int m = INT_MAX;
        for (auto x: g[u]) {
            dfs(x);
            m = min(m, a[x]);
        }
        if (u != 0) {
            a[u] = min(m, (a[u] + m) / 2);
        } else {
            a[u] += m;
        }
    };
    dfs(0);

    cout << a[0];
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
