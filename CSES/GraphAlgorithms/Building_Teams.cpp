#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

vector<vector<int>> e;
vector<int> p;
vector<int> c;
bool possible;

void dfs(int u) {
    if (not possible) return;
    for (auto &v: e[u]) {
        if (c[u] == c[v]) { possible = false; return; }
        if (v == p[u]) continue;
        c[v] = (c[u] == 1) ? 2 : 1;
        if (p[v] == 0) p[v] = u, dfs(v);
    }
}

void solve() {
    int n, m; cin >> n >> m;
    e.resize(n+1);
    p.resize(n+1);
    c.resize(n+1);
    possible = true;

    int u, v; for (int _ = 0; _ < m; _++) {
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    for (int i=1; i<=n and possible; i++) {
        if (p[i] != 0) continue;
        c[i] = 1; p[i] = 1;
        dfs(i);
    }

    if (possible) {
        for (int i = 1; i <= n; i++) cout << c[i] << ' ';
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

