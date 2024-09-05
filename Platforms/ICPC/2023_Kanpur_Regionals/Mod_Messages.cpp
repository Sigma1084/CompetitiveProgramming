#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
vector<vector<int>> g;
vector<int> f;

// p[k][u] = par^(2^k)[u]
// m[k][u] = min(fs of (u to par^(2^k)[u]))
constexpr int K = 19;
array<vector<int>, K> p, m;
vector<int> dep;  // depth
auto &par = p[0];  // parent

void dfs(int u) {
    for (auto v: g[u]) {
        if (v == par[u]) continue;
        par[v] = u;
        dep[v] = dep[u] + 1;
        dfs(v);
    }
}

void preCompute() {
    par[0] = 0;
    dep[0] = 0;
    dfs(0);

    for (int u = 0; u < n; ++u) {
        m[0][u] = f[par[u]];
    }

    for (int k = 1; k < K; ++k) {
        for (int u = 0; u < n; ++u) {
            p[k][u] = p[k-1][p[k-1][u]];
            m[k][u] = min(m[k-1][u], m[k-1][p[k-1][u]]);
        }
    }
}

int lca(int u, int v) {
    if (dep[u] > dep[v]) {
        swap(u, v);
    }

    for (int k = K - 1; dep[u] < dep[v]; --k) {
        if ((1 << k) <= dep[v] - dep[u]) {
            v = p[k][v];
        }
    }

    if (u == v) {
        return u;
    }

    for (int k = K - 1; k >= 0; --k) {
        if (p[k][u] != p[k][v]) {
            u = p[k][u];
            v = p[k][v];
        }
    }

    return par[u];
}

int asc(int val, int u, int d) {
    // cerr << "Performing asc, val = " << val;
    // cerr << ", u = " << u + 1;
    // cerr << ", d = " << d << '\n';

    if (d == 0) {
        return val;
    } else if (d == 1) {
        return val % f[par[u]];
    }

    int mxK = __lg(2*d - 1);  // ceil(log)
    if (val < m[mxK][u]) {
        return val;
    }

    // Take u to the point where f[u] < min
    for (int k = mxK; k >= 0; --k) {
        if (val < m[k][u]) {
            d -= 1 << k;
            u = p[k][u];
        }
    }

    if (d == 0) {
        return val;
    }

    return asc(val % f[par[u]], par[u], d - 1);
}

// cL := ceil(log(dep))
int desc(int val, int u, int d, int cL) {
    // cerr << "Performing desc, val = " << val;
    // cerr << ", u = " << u + 1;
    // cerr << ", d = " << d;
    // cerr << ", cL = " << cL << '\n';

    if (d == 0) {
        return val;
    } else if (d == 1) {
        return val % f[u];
    }

    if (cL == -1) {
        cL = __lg(2*d - 1);
    }

    if (val < m[cL][u]) {
        return val % f[u];
    }

    int valMid = desc(val, p[cL-1][u], d - (1 << (cL-1)), 
        (d == 1 << cL) ? cL - 1 : -1);

    cL -= 1;
    if (val < m[cL][u]) {
        return val % f[u];
    }

    return desc(valMid, u, 1 << cL, cL);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    cin >> n;
    g.resize(n);
    f.resize(n);
    dep.resize(n);

    for (int k = 0; k < K; ++k) {
        p[k] = vector<int>(n);
        m[k] = vector<int>(n, INT_MAX);
    }

    for (auto &x: f) {
        cin >> x;
    }

    for (int i = 0; i + 1 < n; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    preCompute();

    int nQ;
    cin >> nQ;

    while (nQ--) {
        int x, y;
        cin >> x >> y;
        --x; --y;

        int a = lca(x, y);
        int val = asc(f[x], x, dep[x] - dep[a]);

        // cerr << "a = " << a + 1 << ' ';
        // cerr << "bef = " << f[x] << ' ';
        // cerr << "asc = " << val << ' ';
        // cerr << '\n';

        if (y != a) {
            val = desc(val, y, dep[y] - dep[a], -1);
        }

        cout << val << '\n';
    }

    return 0;
}
