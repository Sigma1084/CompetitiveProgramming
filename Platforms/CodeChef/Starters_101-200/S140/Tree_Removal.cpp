#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (auto &x: a) {
        cin >> x;
    }

    vector<vector<int>> e(n);
    for (int i = 0; i + 1 < n; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    vector<int> d(n);
    int root = min_element(a.begin(), a.end()) - a.begin();
    set<pair<int, int>> s;  // [deg, u]
    for (int u = 0; u < n; ++u) {
        d[u] = e[u].size();
        s.emplace(d[u], u);
    }
    s.erase({d[root], root});
    d[root] = 0;

    vector<int> ans;
    ans.reserve(n - 1);
    while (not s.empty()) {
        auto [deg, u] = *s.begin();
        assert(deg == 1);
        s.erase(s.begin());

        d[u] = 0;
        ans.push_back(u);

        for (auto v: e[u]) {
            if (d[v] == 0) {
                continue;
            }
            s.erase({d[v], v});
            --d[v];
            s.emplace(d[v], v);
        }
    }

    cout << ans.size() << '\n';
    for (auto x: ans) {
        cout << x + 1 << ' ';
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;

    for (int i = 1; i <= t; ++i) {
        solve();
        std::cout << '\n';
    }

    return 0;
}
