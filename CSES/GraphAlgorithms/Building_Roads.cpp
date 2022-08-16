#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

vector<int> p;

int Find(int u) {
    if (p[u] == u) return u;
    return p[u] = Find(p[u]);
}

void Union(int u, int v) {
    if (Find(u) == Find(v)) return;
    if (Find(u) > Find(v)) swap(u, v);
    p[p[v]] = p[u];
}

void solve() {
    int n, m; cin >> n >> m;
    p.resize(n+1); for (int i=1; i<=n; i++) p[i] = i;

    int a, b;
    for (int _ = 0; _ < m; _++) {
        cin >> a >> b;
        Union(a, b);
    }

    set<int> conn;
    for (int i=1; i<=n; i++) {
        conn.insert(Find(i));
    }

    cout << conn.size() - 1 << '\n';
    for (auto it = ++conn.begin(); it != conn.end(); it++) {
        cout << *conn.begin() << ' ' << *it << '\n';
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

