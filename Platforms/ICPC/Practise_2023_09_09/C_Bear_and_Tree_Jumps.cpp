#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<vector<int>> e(n);
    vector<vector<ll>> f(n, vector<ll>(k));
    vector<vector<ll>> ans(n, vector<ll>(k));

    for (int u, v, i = 0; i + 1 < n; ++i) {
        cin >> u >> v;
        --u, --v;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    vector<int> sz(n);
    function<void(int, int)> dfs = [&] (int u, int p) -> void {
        sz[u] = 1;
        for (int v : e[u]) {
            if (v == p) continue;
            dfs(v, u);
            sz[u] += sz[v];
            for (int i = 0; i + 1 < k; ++i) {
                f[u][i] += 1 + f[v][i + 1];
            }
            f[u][k - 1] += f[v][0] + sz[v];
        }
    };
    dfs(0, -1);

    ans[0] = f[0];
    dfs = [&] (int u, int p) -> void {
        for (int i = 0; i < k and u; ++i) {
            ll c = ans[p][(i + 1) % k] - f[u][(i + 2) % k];
            if ((i + 2) % k) {
                c -= 1;
            } else {
                c -= sz[u];
            }

            ans[u][i] = f[u][i] + c;
            if (i == k - 1) {
                ans[u][i] += n - sz[u];
            } else {
                ans[u][i] += 1;
            }
        }
        for (int v: e[u]) {
            if (v == p) continue;
            dfs(v, u);
        }
    };
    dfs(0, -1);

    cout << accumulate(ans.begin(), ans.end(), 0LL,
        [&] (ll s, vector<ll> &v) -> ll { return s + v[0]; }) / 2 << '\n';

    return 0;
}
