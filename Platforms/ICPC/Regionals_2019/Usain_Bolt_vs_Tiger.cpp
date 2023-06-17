#include <bits/stdc++.h>
using namespace std;

template<typename T, typename U> ostream &operator << (ostream &ost, const pair<T, U> &p) {
    ost << "("; ost << p.first << " " << p.second; ost << ")"; return ost; }
template<typename T> ostream &operator << (ostream &ost, const vector<T> &v) {
    ost << "["; for(const auto &x: v) ost << ' ' << x; ost << " ]"; return ost; }

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int _ = 0, u, v; _ < m; _++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> ver(n);
    iota(ver.begin(), ver.end(), 1);
    sort(ver.begin(), ver.end(), [&adj](int u, int v) {
       return adj[u].size() > adj[v].size(); 
    });

    for (int u = 1; u <= n; u++) {
        sort(adj[u].begin(), adj[u].end(), [&adj](int u, int v) {
           return adj[u].size() > adj[v].size(); 
        });
    }

    vector<int> par(n + 1, -1), depth(n + 1);
    int root = ver[0];
    par[root] = 0; depth[root] = 0;

    int uI, vI, u, v, d;
    for (uI = 1; uI < n; uI++) {
        u = ver[uI];
        for (vI = 0; vI < adj[u].size(); vI++) {
            v = adj[u][vI];
            if (par[v] == -1) break;
        }
        vI--;
        if (vI == -1) {
            cout << "NO";
            return;
        }
        v = adj[u][vI];
        par[u] = v;
        depth[u] = vI + 1;
        if (depth[v] + 1 != depth[u]) {
            cout << "NO";
            return;
        }
    }

    cout << "YES\n";
    for (int u = 1; u <= n; u++) {
        cout << par[u] << ' ';
    }
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve(); cout << '\n';
    }
	return 0;
}
