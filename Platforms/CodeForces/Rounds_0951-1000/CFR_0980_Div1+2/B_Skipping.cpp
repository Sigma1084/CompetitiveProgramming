#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<array<int, 2>> a(n);
    for (auto &[x, _] : a) {
        cin >> x;
    }
    for (auto &[_, y] : a) {
        cin >> y;
        --y;
    }

    vector<vector<array<int, 2>>> g(n);
    g[0].push_back({a[0][1], a[0][0]});
    for (int u = 1; u < n; ++u) {
        auto [w, v] = a[u];
        g[u].push_back({v, w});
        g[u].push_back({u - 1, 0});
    }

    constexpr ll INF = 1e18;
    using T = array<ll, 2>;
    priority_queue<T, vector<T>, greater<>> pq;
    vector<ll> d(n, INF);
    pq.push({0, 0});
    while (!pq.empty()) {
        auto [du, u] = pq.top();
        pq.pop();
        if (d[u] != INF) {
            continue;
        }
        d[u] = du;
        for (auto [v, w] : g[u]) {
            pq.push({du + w, v});
        }
    }

    ll sm = 0, ans = 0;
    for (int u = 0; u < n; ++u) {
        sm += a[u][0];
        d[u] = sm - d[u];
        ans = max(ans, d[u]);
    }

    cout << ans;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;

    while (t--) {
        solve();
        std::cout << '\n';
    }

    return 0;
}
