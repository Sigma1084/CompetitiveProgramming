#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MOD = 1e9 + 7;

vector<vector<pair<int, int>>> e;
vector<vector<ll>> dp;

void solve() {
    int n, m, q; cin >> n >> m >> q;
    e.resize(n + 1);
    dp.resize(n + 1, vector<ll>(n + 1, MOD));
    // for (int i = 1; i < n; i++) dp[i][i] = 0;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        e[u].push_back({v, w});
        e[v].push_back({u, w});
    }

    typedef pair<ll, int> p;
    priority_queue<p, vector<p>, greater<p>> pq;

    for (int i = 1; i <= n; i++) {
        // Greedily Choose Vertices
        pq.push({0, i});
        while (not pq.empty()) {
            ll d = pq.top().first; int u = pq.top().second; pq.pop();
            if (dp[i][u] != MOD) continue;
            dp[i][u] = d;
            for (auto &v: e[u]) {
                if (dp[i][v.first] == MOD) 
                    pq.push({d + v.second, v.first});
            }
        }
    }

    for (int i = 0; i < q; i++) {
        int u, v; cin >> u >> v;
        cout << (dp[u][v] != MOD ? dp[u][v] : -1) << '\n';
    }
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

