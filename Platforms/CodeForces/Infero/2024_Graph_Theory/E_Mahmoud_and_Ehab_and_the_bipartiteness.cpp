#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> g(n);
    for (int i = 0; i < n-1; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> d(n, -1);
    function<void(int)> dfs = [&](int u) {
        for (auto v: g[u]) {
            if (d[v] != -1) continue;
            d[v] = 1 + d[u];
            dfs(v);
        }
    };
    dfs(0);

    array<int, 2> sc{};
    for (int i = 0; i < n; ++i) {
        sc[d[i] % 2]++;
    }

    cout << 1LL * sc[0] * sc[1] - (n-1);

    return 0;
}
