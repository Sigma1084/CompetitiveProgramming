#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MOD = 1e9 + 7;

void solve() {
    int n, m; cin >> n >> m;

    vector<vector<pair<int, int>>> e(n + 1);
    vector<int> maxPossible(n + 1, -1);
    for (int i = 1; i <= m; i++) {
        int u, v, w; cin >> u >> v >> w;
        if (v < u) swap(u, v);  // So that u <= v holds
        e[u].push_back({v, w});
        if (maxPossible[u] == -1) maxPossible[u] = w;
        else maxPossible[u] &= w;
        if (maxPossible[v] == -1) maxPossible[v] = w;
        else maxPossible[v] &= w;
    }

    vector<int> ans(n + 1);
    for (int u = 1; u <= n; u++) {
        int minReq = -1;
        for (auto &[v, w]: e[u]) {
            w -= (w & ans[u]);
            if (minReq == -1) minReq = w & (w ^ maxPossible[v]);
            else minReq |= w & (w ^ maxPossible[v]);
        }
        if (minReq == -1) minReq = 0;

        ans[u] |= minReq;

        for (auto &[v, w]: e[u]) {
            ans[v] |= (w ^ ans[u]);
        }
    }

    for (int u = 1; u <= n; u++) cout << ans[u] << ' ';
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

