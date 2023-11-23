#include <bits/stdc++.h>
using namespace std;
using ll = long long;


constexpr int P = 1000000007;

class Z {
    int val = 0;
    void normalize() { if (val < 0) val += P; if (val >= P) val -= P; }
public:
    Z() = default;
    template<class T> Z(const T &v): val((P + v%P) % P) {}
    Z(const Z &z) = default;
    Z operator - () const { return Z(0) -= val; }
    constexpr int operator ()() const { return val; }
    Z pow(unsigned long long b) const {
        Z ans = 1;
        for (Z a = *this; b; b /= 2, a *= a) if (b % 2) ans *= a;
        return ans;
    }
    Z inv() const { return pow(P - 2); }
    Z& operator += (Z a) { val += a.val; normalize(); return *this; }
    Z& operator -= (Z a) { val -= a.val; normalize(); return *this; }
    Z& operator *= (Z a) { val = 1LL * val * a.val % P; return *this; }
    Z& operator /= (Z a) { return *this *= a.inv(); }
    Z& operator ++ (int) { return operator+=(1); }
    Z& operator -- (int) { return operator-=(1); }
    Z operator + (Z a) { return Z(*this) += a; }
    Z operator - (Z a) { return Z(*this) -= a; }
    Z operator * (Z a) { return Z(*this) *= a; }
    Z operator / (Z a) { return Z(*this) /= a; }
    constexpr bool operator == (Z a) const { return val == a.val; }
    constexpr bool operator != (Z a) const { return val != a.val; }
    friend ostream& operator << (ostream &os, Z a) { return os << a(); }
};


constexpr int N = 100;
array<Z, N + 1> fact, invFact;

void preCompute() {
    fact[0] = 1;
    for (int i = 1; i <= N; ++i) {
        fact[i] = fact[i - 1] * i;
    }
    invFact[N] = fact[N].inv();
    for (int i = N; i >= 1; --i) {
        invFact[i - 1] = invFact[i] * i;
    }
}


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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    preCompute();

    int n;
    cin >> n;

    vector<array<ll, 2>> points(n);
    for (auto &[x, y]: points) {
        cin >> x >> y;
    }

    auto dist = [&](int u, int v) {
        ll dx = points[u][0] - points[v][0];
        ll dy = points[u][1] - points[v][1];
        return abs(dx) + abs(dy);
    };

    // Every pair has a color
    vector<tuple<ll, int, int>> edges;
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            edges.emplace_back(dist(i, j), i, j);
        }
    }
    sort(edges.begin(), edges.end());

    DSU dsu(n);
    std::vector<ll> dC(n);  // Distance associated with the component

    for (auto &[d, u, v]: edges) {
        if (dsu.size(u) != 1 and dC[dsu.find(u)] != d) {
            continue;
        }
        if (dsu.size(v) != 1 and dC[dsu.find(v)] != d) {
            continue;
        }
        dsu.merge(u, v);
        dC[dsu.find(u)] = d;
    }

    vector<vector<int>> nodes(n);
    for (int i = 0; i < n; ++i) {
        nodes[dsu.find(i)].push_back(i);
    }

    // 1 color each
    Z ans = fact[n];

    for (const auto &comp: nodes) {
        if (comp.empty()) continue;
        int p = dsu.find(comp[0]);

        cerr << "Parent = " << p << '\n';
        cerr << "dC = " << dC[p] << '\n';
        for (int u: comp) {
            cerr << u << ' ';
        }
        cerr << '\n';

        // Check if all pairwise distances are the same
        for (int u: comp) {
            for (int v: comp) {
                if (u == v) continue;
                // Otherwise, their distances are the same
                if (dist(u, v) != dC[p]) {
                    cout << ans << '\n';
                    return 0;
                }
            }
        }
    }

    // Now, we have a few components
    ans += fact[n] * invFact[n - dsu.numComp()];
    cout << ans << '\n';

    return 0;
}
