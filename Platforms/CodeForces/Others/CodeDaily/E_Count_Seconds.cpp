#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int P = 998244353;

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

/**
 * Suppose we have d levels after the current node
 * then it takes a[j] + d moves to propagate to the jth node
 * 
 * Where dp[j] = a[j] + 
 */

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int &x: a) {
        cin >> x;
    }

    vector<vector<int>> g(n);
    vector<int> inDeg(n);
    for (int i = 0, u, v; i < m; ++i) {
        cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        inDeg[v] += 1;
    }

    // Topological ordering
    vector<int> ord;
    ord.reserve(n);
    for (int i = 0; i < n; ++i) {
        if (inDeg[i] == 0) {
            ord.push_back(i);
        }
    }
    for (int i = 0, x; i < n; ++i) {
        x = ord[i];
        for (int y: g[x]) {
            if (--inDeg[y] == 0) {
                ord.push_back(y);
            }
        }
    }
    assert(ord.size() == n);

    // Simulate the first n moves to propagate at least once
    int ans = 0;
    while (ans < n and a != vector(n, 0)) {
        for (int i = n-1, u; i >= 0; --i) {
            u = ord[i];
            if (a[u] > 0) {
                a[u] -= 1;
                for (int v: g[u]) {
                    a[v] += 1;
                }
            }
        }
        ans += 1;
    }

    if (a == vector(n, 0)) {
        cout << ans << '\n';
        return;
    }

    // Now store how long it takes for the last elements
    vector<Z> dp(a.begin(), a.end());
    for (int u: ord) {
        for (int v: g[u]) {
            dp[v] += dp[u];
        }
    }

    cout << dp[ord.back()] + ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
