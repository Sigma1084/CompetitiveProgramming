#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, a, b, c;
    cin >> n >> a >> b >> c;

    vector<vector<int>> d(n, vector<int>(n));
    for (auto &row: d) {
        for (auto &x: row) {
            cin >> x;
        }
    }


    // Find the minimum cost to reach i from a
    using Node = pair<ll, int>;  // {cost, node}
    priority_queue<Node, vector<Node>, greater<>> pq;

    vector<ll> da(n, -1);
    for (int i = 0; i < n; ++i) {
        pq.push({1LL * d[0][i] * a, i});
    }

    while (!pq.empty()) {
        auto [cost, u] = pq.top();
        pq.pop();
        if (da[u] != -1) continue;  // Already visited
        da[u] = cost;
        for (int v = 1; v < n; ++v) {
            if (da[v] == -1) {
                pq.push({cost + 1LL * d[u][v] * a, v});
            }
        }
    }

    vector<ll> db(n, -1);
    for (int i = 0; i < n; ++i) {
        pq.push({1LL * d[i][n - 1] * b + c, i});
    }
    pq.push({0, n - 1});

    while (!pq.empty()) {
        auto [cost, u] = pq.top();
        pq.pop();
        if (db[u] != -1) continue;  // Already visited
        db[u] = cost;
        for (int v = 0; v + 1 < n; ++v) {
            if (db[v] == -1) {
                pq.push({cost + 1LL * d[u][v] * b + c, v});
            }
        }
    }

    ll ans = LONG_LONG_MAX;
    for (int i = 0; i < n; ++i) {
        if (da[i] == -1 or db[i] == -1) continue;
        ans = min(ans, da[i] + db[i]);
    }

    cout << ans;

    return 0;
}
