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

const map<char, int> mp = {
    {'U', 0}, {'D', 1},
    {'L', 2}, {'R', 3},
};

void solve() {
    int n;
    cin >> n;

    vector<array<int, 4>> a(n);
    for (int i = 0; i < n; ++i) {
        auto &[x, y, val, idx] = a[i];
        cin >> x >> y;
        char c;
        cin >> c;
        val = mp.at(c);
        idx = i;
    }

    DSU dsu(n);
    sort(a.begin(), a.end(), [](auto &a, auto &b) {
        if (a[0] == b[0]) return a[1] < b[1];
        return a[0] < b[0];
    });
    for (int i = 1; i < n; ++i) {
        if (a[i][0] == a[i-1][0] and (a[i][2] ^ a[i-1][2]) <= 1) {
            dsu.merge(a[i][3], a[i-1][3]);
        }
    }
    sort(a.begin(), a.end(), [](auto &a, auto &b) {
        if (a[1] == b[1]) return a[0] < b[0];
        return a[1] < b[1];
    });
    for (int i = 1; i < n; ++i) {
        if (a[i][1] == a[i-1][1] and (a[i][2] ^ a[i-1][2]) <= 1) {
            dsu.merge(a[i][3], a[i-1][3]);
        }
    }

    vector<int> sm(n);
    for (auto [x, y, val, idx]: a) {
        sm[dsu.find(idx)] += val & 1;
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (dsu.isLeader(i)) {
            ans += min(sm[i], dsu.size(i) - sm[i]);
        }
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
