#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

vector<vector<int>> e;
vector<int> p;
int cycle;

void dfs(int u) {
    if (cycle) return;
    for (auto &v: e[u]) {
        if (v == p[u]) continue;
        if (p[v]) {
            // Cycle found
            p[v] = u;
            cycle = v;
            return;
        } else {
            p[v] = u;
            dfs(v);
        }
        if (cycle) return;
    }
}

void solve() {
    int n, m; cin >> n >> m;
    e.resize(n+1); p.resize(n+1); cycle = 0;

    int u, v; for (int i=0; i<m; i++) {
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    for (int i = 1; i <= n and not cycle; i++) {
        if (p[i]) continue;
        p[i] = i; dfs(i);
    }

    if (cycle) {
        int cur = p[cycle];
        vector<int> ans = { cycle };
        while (cur != cycle) ans.push_back(cur), cur = p[cur];
        ans.push_back(cycle);

        cout << ans.size() << '\n';
        for (auto &x: ans) cout << x << ' ';
    } else {
        cout << "IMPOSSIBLE";
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

