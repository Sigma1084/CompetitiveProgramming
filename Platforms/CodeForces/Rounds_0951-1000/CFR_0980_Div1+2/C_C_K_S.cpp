#include <bits/stdc++.h>
using namespace std;
using ll = long long;

std::vector<std::size_t> zFunc(const std::vector<int> &a, const std::vector<int> &p) {
    std::vector<std::size_t> z(a.size());
    z[0] = a.size();
    for (std::size_t i = 0, l = 0, r = 0; i < a.size(); ++i) {
        if (i <= r) {
            z[i] = std::min(r - i + 1, z[i - l]);
        }
        while (i + z[i] < a.size() and z[i] < p.size() and p[z[i]] == a[i + z[i]]) {
            ++z[i];
        }
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
    return z;
}

/**
 * @brief Returns the instances where the pattern p is found in the array a
 */
std::vector<std::size_t> findSuitable(const std::vector<int> &a, const std::vector<int> &p) {
    auto z = zFunc(a, p);
    std::vector<std::size_t> res;
    for (std::size_t i = 0; i < a.size(); ++i) {
        if (z[i] == p.size()) {
            res.push_back(i);
        }
    }
    return res;
}

void solve() {
    int n, k;
    cin >> n >> k;

    array<vector<int>, 2> a;
    array<vector<vector<int>>, 2> g;

    for (int i = 0; i < 2; ++i) {
        a[i].resize(n);
        g[i].resize(n);
        for (auto &x : a[i]) {
            cin >> x;
        }
        int m;
        cin >> m;
        for (int j = 0; j < m; ++j) {
            int u, v;
            cin >> u >> v;
            --u, --v;
            g[i][u].push_back(v);
        }
    }

    auto s1 = accumulate(a[0].begin(), a[0].end(), 0), s2 = accumulate(a[1].begin(), a[1].end(), 0);
    if (s1 + s2 != n) {
        cout << "NO";
        return;
    }
    if (s1 == 0 or s1 == n) {
        cout << "YES";
        return;
    }

    array<vector<int>, 2> d;
    array<array<vector<int>, 2>, 2> f;
    for (int i = 0; i < 2; ++i) {
        d[i].resize(n, INT_MAX);
        d[i][0] = 0;
        queue<int> q;
        q.push(0);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : g[i][u]) {
                if (d[i][v] == INT_MAX) {
                    d[i][v] = d[i][u] + 1;
                    q.push(v);
                }
            }
        }
        for (auto &v : f[i]) {
            v.resize(k);
        }
        for (int j = 0; j < n; ++j) {
            ++f[i][a[i][j]][d[i][j] % k];
        }
    }

    // We need to check for what values can f[0][1] can be a substring of f[1][0]
    for (int i = 0; i + 1 < k; ++i) {
        f[0][0].push_back(f[0][0][i]);
        f[1][0].push_back(f[1][0][i]);
    }

    auto r1 = findSuitable(f[1][0], f[0][1]);
    auto r2 = findSuitable(f[0][0], f[1][1]);

    // Check if there's an intersection between r1 and r2
    for (int i = 0, j = 0; i < r1.size() && j < r2.size(); ) {
        if (r1[i] == r2[j]) {
            cout << "YES";
            return;
        }
        if (r1[i] < r2[j]) {
            ++i;
        } else {
            ++j;
        }
    }

    cout << "NO";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;

    while (t--) {
        solve();
        std::cout << '\n';
    }

    return 0;
}
