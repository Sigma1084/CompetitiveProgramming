#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll INIT = -1e15 - 7;

int n, m;
vector<vector<pair<int, int>>> adj;
vector<ll> mD;

void solve() {
    cin >> n >> m;
    adj.resize(n + 1);
    mD.resize(n + 1, INIT);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    /**
     * @brief Dijkstra's Algorithm. pq => {distance, node}
     */
    priority_queue<pair<ll, int>> pq;
    pq.push({0, 1});
    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d <= mD[u]) continue;
        mD[u] = d;
        for (auto [v, w] : adj[u]) {
            if (mD[v] == INIT) pq.push({d + w, v});
            else if (mD[v] < d + w) { cout << -1; return; }
        }
        for (int i = 1; i <= n; i++) cout << mD[i] << ' '; cout << '\n';
    }

    for (int i = 1; i <= n; i++) cout << mD[i] << ' '; cout << '\n';

    cout << mD[n];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int t = 1;
    // cin >> t;

    for (int i=1; i<=t; i++) {
        // cout << "Case #" << i << ": ";
        solve(); cout << '\n';
    }
    return 0;
}

