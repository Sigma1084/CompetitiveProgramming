#include <bits/stdc++.h>
using namespace std;
constexpr int INF = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> e(n), rE(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        e[u].push_back(v);
        rE[v].push_back(u);
    }

    int k;
    cin >> k;

    vector<int> path(k);
    for (int &x: path) {
        cin >> x;
        --x;
    }

    int t = path.back();

    // BFS on u

    vector<int> d(n, INF);    
    queue<int> q;
    q.push(t);
    d[t] = 0;

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (auto v: rE[u]) {
            if (d[v] == INF) {
                d[v] = d[u] + 1;
                q.push(v);
            }
        }
    }

    int mn = 0, mx = 0;
    for (int i = 0; i + 1 < k; ++i) {
        int u = path[i];

        int good = 0;
        for (int v: e[u]) {
            if (d[v] == d[u] - 1) {
                ++good;
            }
        }
        assert(good > 0);

        int v = path[i + 1];
        if (d[v] != d[u] - 1) {
            ++mn; ++mx;
        } else if (good > 1) {
            ++mx;
        }
    }

    cout << mn << ' ' << mx << '\n';

    return 0;
}
