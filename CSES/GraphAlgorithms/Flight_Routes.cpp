#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MOD = 1e9 + 7;

int n, m, k;
vector<vector<pair<int, int>>> e;
vector<vector<pair<int, int>>> er;
vector<ll> d1, d2;

void solve() {
    cin >> n >> m >> k;
    int u, v, w;
    e.resize(n + 1);
    d1.resize(n + 1);
    d2.resize(n + 1);
    for (int _ = 0; _ < m; _++) {
        cin >> u >> v >> w;
        e[u].push_back({v, w});
        er[v].push_back({u, w});
    }

    using pli = pair<ll, int>;
    priority_queue<pli, vector<pli>, greater<pli>> heap;

    heap.push({0, 1});
    while (!heap.empty()) {
        auto [d, u] = heap.top(); heap.pop();
        if (d1[u] < d) continue;
        d1[u] = d;
        for (auto &[v, w]: e[u]) {
            heap.push({d + w, v});
        }
    }

    heap.push({0, n});
    while (!heap.empty()) {
        auto [d, u] = heap.top(); heap.pop();
        if (d2[u] < d) continue;
        d2[u] = d;
        for (auto &[v, w]: e[u]) {
            heap.push({d + w, v});
        }
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

