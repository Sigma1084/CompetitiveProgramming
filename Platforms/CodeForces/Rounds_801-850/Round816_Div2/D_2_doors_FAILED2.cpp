#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MOD = 1e9 + 7;

void solve() {
    int n, m; cin >> n >> m;

    vector<vector<int>> edges;

    vector<vector<pair<int, int>>> e(n + 1);
    for (int i = 1; i <= m; i++) {
        int u, v, w; cin >> u >> v >> w;
        edges.push_back( {min(u, v), max(u, v), w} );
        e[u].push_back({v, w});
        e[v].push_back({u, w});
    }
    for (auto &eu: e) sort(eu.begin(), eu.end());

    vector<int> maxPossible(n + 1);
    for (int u = 1; u <= n; u++) {
        if (e[u].size() == 0) maxPossible[u] = 0;
        else maxPossible[u] = e[u][0].second;
        for (auto [v, w]: e[u]) maxPossible[u] &= w;
    }

    int cur = 1;
    vector<int> ans(n + 1, 0);
    vector<bool> sm(n + 1);

    int u, v, w;

    // auto rec = [&] (auto &&rec, int u) -> void {
    //     sm[u] = false;
    //     for (auto [v, w]: e[u]) {
    //         if (sm[v] == false) continue;
    //         if (w & cur == 0) rec(rec, v);
    //         else ans[v] += cur, sm[v] = false;
    //     }
    // };

    for (auto &x: edges) {
        u = x[0], v = x[1], w = x[2];
        ans[u] |= (w ^ maxPossible[u]) & maxPossible[v];
        ans[v] |= (w ^ maxPossible[v]) & maxPossible[u];
        x[2] -= x[2] & ans[u];
        x[2] -= x[2] & ans[v];
    }

    for (auto &x: edges) {
        cout << x[0] << ' ' << x[1] << ' ' << x[2] << '\n';
    }

    for (u = 1; u <= n; u++) cout << maxPossible[u] << ' ';
    cout << '\n';

    for (u = 1; u <= n; u++) {
        int maxPromise = -1;

        // for (auto [v, w]: e[u]) {
        //     w -= (w & ans[u]);
        //     w -= (w & ans[v]);
        // }

        auto it = e[u].begin();

        // Promises from before
        // for (; it->first <= u and it != e[u].end(); it++) {
        //     v = it->first, w = it->second;
        //     ans[u] |= (ans[v] ^ w);
        // }

        // Calculate maxFuturePromise
        for (; it != e[u].end(); it++) {
            v = it->first, w = it->second;
            if (maxPromise == -1) maxPromise = maxPossible[v];
            else maxPromise &= maxPossible[v];
        }

        ans[u] = maxPossible[u] ^ maxPromise;

        for (auto [v, w]: e[u]) {
            w -= (w & maxPromise);
            ans[v] |= (w & maxPromise);
        }
    }

    for (int u = 1; u <= n; u++) cout << ans[u] << ' ';

    // for (int b = 0; b < 30; b++) {
    //     sm.clear();
    //     sm.resize(n + 1, true);  // Means do it

    //     auto rec = [&] (auto &&rec, int u) -> void {
    //         sm[u] = false;
    //         for (auto [v, w]: e[u]) {
    //             if (sm[v] == false) continue;
    //             if (w & cur == 0) rec(rec, v);
    //             else ans[v] += cur, sm[v] = false;
    //         }
    //     };

    //     for (auto &x: edges) {
    //         int u = x[0], v = x[1], w = x[2];
    //         if (w & cur == 0) rec(rec, u);
    //     }

    //     for (int u = 1; u <= n; u++) {
    //         if (sm[u] == false) continue;
    //         sm[u] = false;
    //         for (auto [v, w]: e[u]) {
    //             // w & cur will be 1 for all w
    //             ans[v] += cur;
    //             sm[v] = false;
    //         }
    //     }
    // }
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

