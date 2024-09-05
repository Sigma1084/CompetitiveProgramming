#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class DSU {
    const int n; // Number of nodes
    int nC; // Number of components
    std::vector<int> p;  // Parent
    std::vector<int> sz;  // Size of the component
public:
    DSU(int n): n(n), nC(n) { p.resize(n, -1); sz.resize(n, 1); }
    bool isLeader(int u) const { return p[u] < 0; }
    int size(int u) { return sz[find(u)]; }
    int numComp() const { return nC; }

    int find(int u) { 
        if (isLeader(u)) return u;
        return p[u] = find(p[u]);
    }

    bool merge(int u, int v) {
        u = find(u); v = find(v);
        if (u == v) return false;
        if (sz[u] < sz[v]) std::swap(u, v);
        p[v] = u; nC--;
        sz[u] += sz[v]; sz[v] = 0;
        return true;
    }
};

void solve() {
    int n, m;
    cin >> n >> m;

    vector<string> a(n);
    for (auto &x: a) {
        cin >> x;
    }

    DSU dsu(n * m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] == '.') continue;
            if (i + 1 < n and a[i+1][j] == '#') {
                dsu.merge(i * m + j, (i + 1) * m + j);
            }
            if (j + 1 < m and a[i][j+1] == '#') {
                dsu.merge(i * m + j, i * m + j + 1);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        // i-th row
        int cur = 0;
        set<int> s;
        for (int j = 0; j < m; ++j) {
            if (a[i][j] == '#') {
                s.insert(dsu.find(i * m + j));
            } else {
                cur++;
                if (i - 1 >= 0 and a[i-1][j] == '#') {
                    s.insert(dsu.find((i - 1) * m + j));
                }
                if (i + 1 < n and a[i+1][j] == '#') {
                    s.insert(dsu.find((i + 1) * m + j));
                }
            }
        }
        int val = cur;
        for (auto x: s) {
            val += dsu.size(x);
        }
        ans = max(ans, val);
    }

    for (int j = 0; j < m; ++j) {
        // j-th column
        int cur = 0;
        set<int> s;
        for (int i = 0; i < n; ++i) {
            if (a[i][j] == '#') {
                s.insert(dsu.find(i * m + j));
            } else {
                cur++;
                if (j - 1 >= 0 and a[i][j-1] == '#') {
                    s.insert(dsu.find(i * m + j - 1));
                }
                if (j + 1 < m and a[i][j+1] == '#') {
                    s.insert(dsu.find(i * m + j + 1));
                }
            }
        }
        int val = cur;
        for (auto x: s) {
            val += dsu.size(x);
        }
        ans = max(ans, val);
    }

    cout << ans;
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
