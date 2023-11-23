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

constexpr int P = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    /**
     * e[j]: What all indices have 1 in j-th bit
     */
    DSU dsu(m);
    vector<bool> isOne(m);
    vector<int> ans;
    int tot = 1;  // Total possible

    for (int i = 0; i < n; ++i) {
        int t; cin >> t;
        bool ok = true;

        if (t == 1) {
            int a;
            cin >> a;
            --a;
            int k = dsu.find(a);
            if (isOne[k]) {
                // Component already has a 1
                ok = false;
            } else {
                // No single 1 in the component
                isOne[k] = true;
            }
        } else {
            int a, b;
            cin >> a >> b;
            --a; --b;
            if (dsu.find(a) == dsu.find(b)) {
                // Already in the same component forms cycle
                ok = false;
            } else if (isOne[dsu.find(a)] and isOne[dsu.find(b)]) {
                // Both components have a 1
                ok = false;
            } else {
                // Merge the components
                int resIsOne = isOne[dsu.find(a)] or isOne[dsu.find(b)];
                dsu.merge(a, b);
                isOne[dsu.find(a)] = resIsOne;
            }
        }

        if (ok) {
            // Ok to take
            tot = tot * 2 % P;
            ans.push_back(i + 1);
        }
    }

    cout << tot << ' ' << ans.size() << '\n';
    for (int x: ans) {
        cout << x << ' ';
    }
    cout << '\n';

    return 0;
}