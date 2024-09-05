#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int exgcd(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int g = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return g;
}

void solve() {
    int n, m, H;
    cin >> n >> m >> H;

    vector<int> l(n), s(n);
    for (auto &x: l) cin >> x;
    for (auto &x: s) cin >> x;

    vector<vector<int>> g(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<bool> vis(n);

    using T = pair<ll, int>;  // {time, index}
    priority_queue<T, vector<T>, greater<>> pq;
    pq.emplace(0LL, 0);

    while (!pq.empty()) {
        auto [t, u] = pq.top();
        pq.pop();

        if (vis[u]) continue;
        vis[u] = true;

        if (u == n - 1) {
            cout << t;
            return;
        }

        // We are at u, and can go to any child v
        for (auto v: g[u]) {
            int a = (l[v] - l[u] + (t % H) * (s[v] - s[u])) % H;
            a = (a + H) % H;
            int b = s[u] - s[v];
            b = (b % H + H) % H;

            int x, y;
            int g = exgcd(b, H, x, y);

            // We have ax = b
            if (a % g) {
                continue;
            }
            int h = H / g;
            x = (1LL * x * (a / g) % h + h) % h;

            pq.emplace(t + x + 1, v);
        }
    }

    cout << -1;
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
