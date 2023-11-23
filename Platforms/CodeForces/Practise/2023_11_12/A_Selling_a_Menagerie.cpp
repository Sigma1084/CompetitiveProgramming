#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n), c(n), in(n);
    for (auto &x: a) {
        cin >> x;
        --x;
        in[x]++;
    }
    for (auto &x: c) {
        cin >> x;
    }

    multiset<pair<int, int>> ms;
    for (int i = 0; i < n; ++i) {
        ms.insert({in[i], i});
    }

    vector<int> ans;
    ans.reserve(n);
    while (!ms.empty()) {
        auto [d, u] = *ms.begin();

        if (d == 0) {
            ms.erase(ms.begin());
            ans.push_back(u);
            auto v = a[u];
            ms.erase(ms.find({in[v], v}));
            in[v]--;
            ms.insert({in[v], v});
            continue;
        }

        assert(d == 1);
        int mn = u, v = a[u];
        while (v != u) {
            if (c[v] < c[mn]) {
                mn = v;
            }
            v = a[v];
        }

        // We need to take this minimum in the end

        u = a[mn], v = u;
        do {
            ans.push_back(v);
            ms.erase(ms.find({in[v], v}));
            v = a[v];
        } while (v != u);
    }

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
