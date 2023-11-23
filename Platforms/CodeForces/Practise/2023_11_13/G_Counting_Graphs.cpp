#include <bits/stdc++.h>
using namespace std;

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

/**
 * @tparam BaseType Must have +, -, * defined
 * @tparam MOD Constant modulo
 * @tparam LongType (optional: default = BaseType)
 */
template<class BaseType, BaseType MOD, class LongType = BaseType>
    requires std::is_integral_v<BaseType> && std::is_integral_v<LongType> &&
             (MOD > 0)
class Modular {
    using ModType = Modular<BaseType, MOD, LongType>;
    BaseType val;

    void normalize() {
        if (val < 0) val += MOD;
        if (val >= MOD) val -= MOD;
    }

public:
    constexpr Modular() = default;

    template<class U>
    constexpr explicit(false) Modular(const U &v) {
        val = (MOD + v % MOD) % MOD;
    }

    constexpr Modular(const Modular &m) = default;

    constexpr ModType operator-() const {
        return ModType(MOD - val);
    }

    constexpr BaseType operator()() const {
        return val;
    }

    constexpr explicit operator BaseType() const {
        return val;
    }

    template<class U>
    ModType pow(U b) const {
        ModType ans = 1;
        for (ModType a = *this; b > 0; b /= 2, a *= a) {
            if (b % 2) { ans *= a; }
        }
        return ans;
    }

    constexpr ModType inv() const {
        static_assert(val != 0, "Modular::inv(): division by zero");
        return pow(MOD - 2);
    }

    constexpr ModType &operator+=(ModType a) {
        val += a.val;
        normalize();
        return *this;
    }

    constexpr ModType &operator-=(ModType a) {
        val -= a.val;
        normalize();
        return *this;
    }

    constexpr ModType &operator*=(ModType a) {
        val = LongType(1) * val * a.val % MOD;
        return *this;
    }

    constexpr ModType &operator/=(ModType a) {
        return *this *= a.inv();
    }

    constexpr friend ModType operator+(ModType a, ModType b) {
        return a += b;
    }

    constexpr friend ModType operator-(ModType a, ModType b) {
        return a -= b;
    }

    constexpr friend ModType operator*(ModType a, ModType b) {
        return a *= b;
    }

    constexpr friend ModType operator/(ModType a, ModType b) {
        return a /= b;
    }

    friend ostream& operator<<(ostream &os, const ModType &a) {
        return os << a.val;
    }
};

constexpr int P = 998'244'353;
using Z = Modular<int, P, long long>;

void solve() {
    int n, s;
    cin >> n >> s;

    vector<array<int, 3>> e(n - 1);
    for (auto &[w, u, v]: e) {
        cin >> u >> v >> w;
        u--; v--;
    }
    ranges::sort(e);

    DSU dsu(n);
    Z ans = 1;
    for (auto [w, u, v]: e) {
        // Obviously, they are in different components
        ans *= Z(s - w + 1).pow(1LL * dsu.size(u) * dsu.size(v) - 1);
        dsu.merge(u, v);
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
