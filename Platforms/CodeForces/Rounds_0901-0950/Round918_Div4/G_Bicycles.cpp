#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<array<int, 2>>> g(n);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;

        --u, --v;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    vector<int> s(n);
    for (auto &x: s) {
        cin >> x;
    }

    // dp[i] := min cost to reach i
    vector<ll> dp(n, LLONG_MAX);

    // least[i] := least cost cycle encountered at i
    vector<int> least(n, INT_MAX);

    using T = tuple<ll, int, int>;  // {dist, node, leastCostCycle}
    priority_queue<T, vector<T>, greater<>> pq;
    pq.emplace(0LL, 0, s[0]);

    while (not pq.empty()) {
        auto [d, u, l] = pq.top();
        pq.pop();
        if (l >= least[u]) {
            continue;
        }
        least[u] = l;
        dp[u] = min(dp[u], d);
        l = min(l, s[u]);
        for (auto [v, w]: g[u]) {
            pq.emplace(d + 1LL*w*l, v, min(l, s[v]));
        }
    }

    cout << dp[n - 1];
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
