#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MOD = 1e9 + 7;

void solve() {
    int n, nQ; cin >> n >> nQ;

    /**
     * @brief e[u] = [(v, w)]
     */
    vector<vector<pair<int, int>>> e(n + 1);


    for (int i = 0; i < nQ; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        e[v].push_back({u, w});
        e[u].push_back({v, w});
    }

    vector<int> anded(n + 1);
    for (int u = 1; u <= n; u++) {
        if (e[u].size() == 0) anded[u] = 0;
        else anded[u] = e[u][0].second;
        for (auto [v, w]: e[u]) anded[u] &= w;
    }

    vector<int> ans(n + 1, 0);

    for (int u = 1; u <= n; u++) {
        // Fulfill Promises
        bool eq = false;
        for (auto [v, w]: e[u]) {
            if (v == u) { ans[u] = w; eq = true; break; }
            if (v < u and ans[v] != w) {
                // The promise
                ans[u] |= (w ^ ans[v]);
            }
        }
        if (eq) continue;

        int maxPos = -1;
        for (auto [v, w]: e[u]) {
            if (v < u) continue;
            // v > u
            if (maxPos == -1) maxPos = anded[v];
            else maxPos &= anded[v];
        }

        if (maxPos == -1) maxPos = 0;
        // That much of a promise is possible
        ans[u] |= (anded[u] ^ maxPos);
    }

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << ' ';
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

