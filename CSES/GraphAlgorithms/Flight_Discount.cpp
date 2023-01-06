#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MOD = 1e9 + 7;

int n, m;
vector<vector<pair<int, int>>> e;
vector<vector<pair<int, int>>> er;
vector<ll> startDist, endDist;

typedef pair<ll, int> pli;  // (cost, end)
    
void solve() {
    cin >> n >> m;
    e.resize(n + 1);
    er.resize(n + 1);
    startDist.resize(n + 1, MOD);
    endDist.resize(n + 1, MOD);

    int a, b, c;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        e[a].push_back({b, c});
        er[b].push_back({a, c});
    }

    priority_queue<pli, vector<pli>, greater<pli>> pq;
    pq.push({0, 1});

    while (!pq.empty()) {
        auto [cost, u] = pq.top(); pq.pop();
        if (startDist[u] != MOD) continue;
        startDist[u] = cost;
        for (auto &[v, w] : e[u]) {
            if (startDist[v] == MOD) pq.push({cost + w, v});
        }
    }

    pq.push({0, n});
    while (!pq.empty()) {
        auto [cost, u] = pq.top(); pq.pop();
        if (endDist[u] != MOD) continue;
        endDist[u] = cost;
        for (auto &[v, w] : er[u]) {
            if (endDist[v] == MOD) pq.push({cost + w, v});
        }
    }

    ll ans = 1e15;
    for (int u = 1; u <= n; u++) {
        for (auto &[v, w] : e[u]) {
            ans = min(ans, startDist[u] + endDist[v] + w/2);
        }
    }

    cout << ans;
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
