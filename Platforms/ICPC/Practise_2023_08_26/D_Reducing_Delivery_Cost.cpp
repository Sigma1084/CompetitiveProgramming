#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k; cin >> n >> m >> k;
    map<pair<int, int>, int> wt;
    vector<vector<array<int, 2>>> e(n);
    for (int i = 0, u, v, w; i < m; i++) {
        cin >> u >> v >> w;
        u--, v--;
        wt[minmax(u, v)] = w;
        e[u].push_back({v, w});
        e[v].push_back({u, w});
    }

    int ans = 0;
    map<pair<int, int>, int> used;
    for (int i = 0, a, b; i < k; i++) {
        cin >> a >> b;
        a--, b--;

        // Find the cost in going from a to b
        using Node = array<int, 3>;
        priority_queue<Node, vector<Node>, greater<>> pq;
        vector<int> dist(n);
        vector<int> par(n, -1);

        pq.push({0, a, a});  // (dist, u)
        while(!pq.empty()) {
            auto [d, u, p] = pq.top();
            pq.pop();
            if (par[u] != -1) continue;
            dist[u] = d;
            par[u] = p;
            if (u == b) break;
            for (auto [v, w] : e[u]) {
                pq.push({d + w, v, u});
            }
        }

        ans += dist[b];

        for (int u = 0; u < n; u++) {
            cerr << dist[u] << ' ';
        }
        cerr << '\n';
        
        for (int u = 0; u < n; u++) {
            cerr << par[u] << ' ';
        }
        cerr << '\n';

        while (b != a) {
            used[minmax(b, par[b])]++;
            b = par[b];
        }
    }

    int old = ans;
    for (auto [edge, cnt] : used) {
        ans = min(ans, old - cnt * wt[edge]);
    }

    cout << ans;

    return 0;
}
