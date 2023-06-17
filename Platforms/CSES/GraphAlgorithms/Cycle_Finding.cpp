#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MOD = 1e9 + 7;

const ll INF = 1e18 + 7;
int n, m;
vector<vector<pair<int, int>>> e;
vector<int> p;
vector<ll> d;
vector<bool> vis;


void solve() {
    cin >> n >> m;
    e.resize(n + 1);
    d.resize(n + 1, INF);
    p.resize(n + 1);

    int u, v, w;
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        if (u == v and w >= 0) continue;
        e[u].push_back({v, w});
    }

    // Main Bellman Ford
    int change = 1;
    for (int i = 1; i <= n and change; i++) {
        change = 0;
        for (u = 1; u <= n; u++) {
            for (auto &[v, w] : e[u]) {
                if (d[u] + w < d[v]) {
                    change = v;
                    d[v] = d[u] + w;
                    p[v] = u;
                }
            }
        }
    }

    // No Change => No Negative Cycle
    if (not change) { cout << "NO"; return; }
    cout << "YES\n";

    vis.resize(n + 1);
    int cur = change;
    while (!vis[cur]) {
        vis[cur] = true;
        cur = p[cur];
    }

    change = cur;
    vector<int> cycle;

    do {
        cycle.push_back(cur);
        cur = p[cur];
    } while (cur != change);
    cycle.push_back(cur);

    reverse(cycle.begin(), cycle.end());

    for (auto &x: cycle) cout << x << ' ';
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
