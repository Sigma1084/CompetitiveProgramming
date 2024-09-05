#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#include <ext/pb_ds/assoc_container.hpp>
template <typename T, class Compare = std::less<>>
using OSet = __gnu_pbds::tree<T,
    __gnu_pbds::null_type,
    Compare,
    __gnu_pbds::rb_tree_tag,
    __gnu_pbds::tree_order_statistics_node_update
>;

void solve() {
    int n;
    cin >> n;

    // 1-indexed
    vector<vector<int>> g(2 * n);
    for (int i = 2; i < 2 * n; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    // Perform a dfs and find who wins in each subtree
    vector<int> w(2 * n);
    function<void(int)> dfs = [&](int u) {
        if (1 <= u and u <= n) {
            w[u] = u;
            return;
        }
        for (int v: g[u]) {
            // Remove u from g[v]
            g[v].erase(find(g[v].begin(), g[v].end(), u));
            dfs(v);
        }
        w[u] = min(w[g[u][0]], w[g[u][1]]);
    };
    dfs(2*n - 1);

    OSet<int> path;
    vector<int> ans(n + 1);

    dfs = [&](int u) {
        if (1 <= u and u <= n) {
            // Number of nodes in the path greater than u
            ans[u] = path.order_of_key(u);
            return;
        }

        path.insert(w[g[u][0]]);
        dfs(g[u][1]);
        path.erase(w[g[u][0]]);

        path.insert(w[g[u][1]]);
        dfs(g[u][0]);
        path.erase(w[g[u][1]]);
    };
    dfs(2*n - 1);

    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << ' ';
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
