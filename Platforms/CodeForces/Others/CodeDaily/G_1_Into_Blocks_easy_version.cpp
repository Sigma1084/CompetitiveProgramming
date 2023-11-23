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

constexpr int A = 2e5;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    // [first, last, freq]
    map<int, array<int, 3>> mp;
    for (int i = 0, x; i < n; ++i) {
        cin >> x;
        if (mp.find(x) == mp.end()) {
            mp[x] = {i, i, 1};
        } else {
            mp[x][1] = i;
            ++mp[x][2];
        }
    }

    set<array<int, 4>> st;
    for (const auto &[x, lrf]: mp) {
        auto [l, r, f] = lrf;
        st.insert({l, r, f, x});
    }

    DSU dsu(A + 1);

    int prevX, prevR = -1;
    for (auto [l, r, f, x]: st) {
        if (l <= prevR) {
            dsu.merge(prevX, x);
        }
        prevX = x;
        prevR = max(prevR, r);
    }

    vector<int> maxSz(A + 1), totSz(A + 1);
    for (auto [l, r, f, x]: st) {
        int u = dsu.find(x);
        maxSz[u] = max(maxSz[u], f);
        totSz[u] += f;
    }

    int ans = 0;
    for (auto [l, r, f, x]: st) {
        if (dsu.isLeader(x)) {
            ans += totSz[x] - maxSz[x];
        }
    }

    cout << ans;

    return 0;
}
