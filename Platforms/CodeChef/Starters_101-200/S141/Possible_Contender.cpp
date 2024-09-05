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
    int n;
    cin >> n;

    vector<int> a(n);
    for (auto &x: a) {
        cin >> x;
    }
    vector<int> o(n);
    iota(o.begin(), o.end(), 0);
    sort(o.begin(), o.end(), [&](int i, int j) {
        return a[i] < a[j];
    });

    DSU dsu(n);
    int mx = 0;
    for (int i = 0, j; i < n; i = j) {
        if (2 * (n - i) - 1 >= dsu.numComp()) {
            mx = a[o[i]];
        }
        for (j = i; j < n and a[o[j]] == a[o[i]]; ++j) {
            int p = o[j];
            if (p > 0 and a[p-1] <= a[p]) {
                dsu.merge(p-1, p);
            }
            if (p + 1 < n and a[p+1] <= a[p]) {
                dsu.merge(p, p+1);
            }
        }
    }

    for (auto x: a) {
        cout << (x <= mx);
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
