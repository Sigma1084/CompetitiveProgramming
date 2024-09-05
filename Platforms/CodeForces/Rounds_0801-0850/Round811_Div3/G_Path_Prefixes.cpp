#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

const int N = 2 * 10e5 + 3;
vector<int> p;
vector<vector<int>> e;
vector<int> a, b;
vector<ll> pre;
vector<ll> ans;
ll cur;

void dfs(int u) {
    cur += a[u];
    if (pre.size() == 0) pre.push_back(b[u]);
    else pre.push_back(pre.back() + b[u]);

    ans[u] = upper_bound(pre.begin(), pre.end(), cur) - pre.begin();
    ans[u]--;

    for (auto &v: e[u]) if (v != p[u]) dfs(v);

    pre.pop_back();
    cur -= a[u];
}

void solve() {
    int n; cin >> n;

    p = vector<int>(n+1);
    a = vector<int>(n+1);
    b = vector<int>(n+1);
    e = vector<vector<int>>(n+1);

    for (int i=2; i<=n; i++) {
        cin >> p[i] >> a[i] >> b[i];
        e[i].push_back(p[i]);
        e[p[i]].push_back(i);
    }

    ans = vector<ll>(n+1, 0);
    pre = vector<ll>();
    cur = 0;

    dfs(1);

    for (int i=2; i<=n; i++) cout << ans[i] << ' ';
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

