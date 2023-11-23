#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<vector<int>> e(n);
    for (int i = 0; i + 1 < n; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    vector<int> d(n), p(n, -1), sz(n);
    function<void(int)> dfs = [&](int u) {
        sz[u] = 1;
        for (auto v: e[u]) {
            if (v == p[u]) continue;
            p[v] = u;
            d[v] = d[u] + 1;
            dfs(v);
            sz[u] += sz[v];
        }
    };
    dfs(0);

    map<tuple<int, int, int>, int> mp;
    for (int i = 0; i < n; ++i) {
        mp[{d[i], sz[i], e[i].size()}]++;
    }

    vector<bool> isUnique(n, false);
    for (const auto &[dz, cnt]: mp) {
        if (cnt % 2 == 0) {
            continue;
        } else {
            auto [dep, size, deg] = dz;
            if (isUnique[dep]) {
                cout << "NO";
                return;
            }
            isUnique[dep] = true;
        }
    }

    // We need a series of isUniques
    for (int i = n - 1; i >= 0; --i) {
        if (not isUnique[i]) continue;
        for (int j = i - 1; j >= 0; --j) {
            if (not isUnique[j]) {
                cout << "NO";
                return;
            }
        }
        break;
    }

    if (isUnique[0]) {
        cout << "YES";
    } else {
        cout << "NO";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    for (int i = 1; i <= t; ++i) {
        solve();
        cout << '\n';
    }

    return 0;
}
