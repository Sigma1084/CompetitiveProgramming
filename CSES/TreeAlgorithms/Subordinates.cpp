#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

vector<int> p;
vector<int> w;
vector<vector<int>> e;

void dfs(int u) {
    for (auto &v: e[u]) {
        dfs(v);
        w[u] += w[v];
    }
}

void solve() {
    int n; cin >> n;
    p.resize(n+1);
    w.resize(n+1, 1);
    e.resize(n+1);
    for (int i=2; i<=n; i++) {
        cin >> p[i];
        e[p[i]].push_back(i);
    }
    dfs(1);

    for (int i=1; i<=n; i++) cout << w[i] - 1 << ' ';
    cout << '\n';
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

