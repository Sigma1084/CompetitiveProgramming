#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, nQ;
    cin >> n >> nQ;

    vector<int> a(n), p(n), d(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i < n; ++i) {
        cin >> p[i];
        --p[i];
        d[i] = d[p[i]] + 1;
    }

    // Square root decomposition
    int k = sqrt(n);
    map<pair<int, int>, ll> sqAns;

    // Compute function for a pair (u, v)
    auto compute = [&](int u, int v) {
        // Compute for the pair (u, v)
        assert(d[u] == d[v]);
        ll res = 0;
        while (d[u] % k) {
            res += 1LL * a[u] * a[v];
            u = p[u];
            v = p[v];
        }
        return res + sqAns[minmax(u, v)];
    };

    // Store the pairs whose depth is a multiple of k
    vector<vector<int>> buckets(k + 1);
    for (int i = 0; i < n; ++i) {
        if (d[i] % k == 0) {
            buckets[d[i] / k].push_back(i);
        }
    }

    // Compute the pairs whose depth is a multiple of k
    for (int i = 0; i <= k; ++i) {
        for (int u: buckets[i]) {
            for (int v: buckets[i]) {
                // Compute for the pair (u, v)
                sqAns[minmax(u, v)] = compute(p[u], p[v]) + 1LL * a[u] * a[v];
                if (u == v) continue;
            }
        }
    }

    // Answer the queries
    for (int x, y; nQ--; ) {
        cin >> x >> y;
        --x; --y;

        auto res = compute(x, y);
        cout << res << '\n';
    }

    return 0;
}
