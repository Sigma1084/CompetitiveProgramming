#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

vector<vector<int>> e;
vector<int> p;

void solve() {
    int n, m; cin >> n >> m;
    e.resize(n+1);
    p.resize(n+1);

    int a, b;
    for (int _ = 0; _ < m; _++) {
        cin >> a >> b;
        e[a].push_back(b);
        e[b].push_back(a);
    }

    queue<int> q; q.push(1);
    bool start = true;
    while (not q.empty()) {
        int u = q.front(); q.pop();
        if (start) { p[u] = u; start = false; }
        for (auto &v: e[u]) if (p[v] == 0) {
            p[v] = u;
            q.push(v);
        }
    }

    vector<int> path;
    int c = n;
    while (c != 1 and c != p[c]) {
        path.push_back(c);
        c = p[c];
    }
    if (c != 1) {
        cout << "IMPOSSIBLE";
        return;
    }
    
    path.push_back(1);
    reverse(path.begin(), path.end());

    cout << path.size() << '\n';
    for (auto &u: path) cout << u << ' ';
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

