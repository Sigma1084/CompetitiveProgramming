#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MOD = 1e9 + 7;


void solve() {
    int n, a, b; cin >> n >> a >> b;
    vector<vector<pair<int, int>>> e(n+1);

    for (int i = 1; i < n; i++) {
        int u, v, w; cin >> u >> v >> w;
        e[u].push_back({v, w});
        e[v].push_back({u, w});
    }

    bool ans = false;
    set<int> reachableToB;

    auto dfsB = [&](int u, int p, int wt, auto &&dfsB) -> void {
        for (auto [v, w]: e[u]) {
            if (v == p) continue;
            reachableToB.insert(wt ^ w);
            dfsB(v, u, wt^w, dfsB);
        }
    };
    dfsB(b, b, 0, dfsB);

    auto dfsA = [&](int u, int p, int wt, auto &&dfsA) -> void {
        if (reachableToB.count(wt))
            ans = true;
        for (auto [v, w]: e[u]) {
            if (v == p or v == b) continue;
            dfsA(v, u, wt^w, dfsA);
        }
    };
    dfsA(a, a, 0, dfsA);

    if (ans) {
        cout << "YES";
    } else {
        cout << "NO";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int t = 1;
    cin >> t;

    for (int i=1; i<=t; i++) {
        // cout << "Case #" << i << ": ";
        solve(); cout << '\n';
    }
    return 0;
}

