#include <bits/stdc++.h>
using namespace std;

constexpr int N = 2e5 + 2;

int n, k;
int P[N];
int H[N];
vector<int> E[N];
int need, h;

void dfs(const int &u) {
    H[u] = 0;
    for (const int &v: E[u]) {
        if (v == P[u]) continue;
        dfs(v);
        if (need > k) return;
        H[u] = max(H[u], H[v]);
    }
    H[u]++;
    if (u == 1 or P[u] == 1) return;
    if (H[u] == h) {
        need++;
        H[u] = 0;
    }
}

void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) E[i].clear();

    for (int i = 2; i <= n; i++) {
        cin >> P[i];
        E[P[i]].push_back(i);
    }

    // Number of nodes being let down excluding root
    int l = 1, r = n-1;
    while (l <= r) {
        h = (l + r) / 2;
        need = 0;
        dfs(1);
        if (need <= k) r = h - 1;
        else l = h + 1;
    }

    cout << l;
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
