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
        --u; --v;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    int nL = 0;
    function<void(int, int)> dfs = [&](int u, int p) {
        if (e[u].size() == 1) ++nL;
        for (int v : e[u]) {
            if (v == p) continue;
            dfs(v, u);
        }
    };
    dfs(0, -1);

    cout << (nL + 1) / 2;
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
