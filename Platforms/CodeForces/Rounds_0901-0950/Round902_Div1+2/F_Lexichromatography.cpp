#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int P = 998'244'353;

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

    int n; cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    map<int, int> m;
    for (int x: a) {
        m[x]++;
    }

    Z ans = Z(2).pow(m.size() - 1);

    for (auto [x, f]: m) {
        if (f % 2) {
            cout << ans;
            return 0;
        }
    }

    map<int, int> rev;
    int sz = 0;
    for (auto [x, f]: m) {
        rev[x] = sz++;
    }

    DSU dsu(sz);

    map<int, int> unEq;
    int bad = 0;
    queue<int> q;
    for (int i = 0; i + 1 < n; ++i) {
        if (unEq[a[i]] == 0) {
            bad++;
            q.push(a[i]);
        } else {
            bad--;
            if (q.front() != a[i]) {
                bad = -1;
                break;
            }
            q.pop();
        }
        unEq[a[i]] ^= 1;
        if (bad != 0) {
            dsu.merge(rev[a[i]], rev[a[i+1]]);
        }
    }

    if (bad != -1) {
        ans -= Z(2).pow(dsu.numComp() - 1);
    }

    cout << ans;

    return 0;
}
