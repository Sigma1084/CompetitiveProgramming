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

void solve() {
    int n;
    cin >> n;

    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    /**
     * dp[u] := Number of selections of good intersections in
     *         the subtree rooted at u with at least 1 colored
     * 
     * If we take the current node, then we can take at most 1 more node
     * If we do not take the current node, answer is the product of all
     * children's dp
     */
    vector<Z> dp(n);
    Z ans = 0;
    function<void(int, int)> dfs = [&](int u, int p) {
        // Not coloring the current node
        dp[u] = 1; 
        for (auto v: g[u]) {
            if (v == p) continue;
            dfs(v, u);
            dp[u] *= dp[v] + 1;
        }
        // We subtract the case where we take 0
        //    from all the children
        dp[u] -= 1;

        // Coloring the current node
        dp[u] += 1;  // Color only this

        // We terminate the cases where 
        // we'll color this and one more from it's subtree
        for (auto v: g[u]) {
            if (v == p) continue;
            ans += dp[v];
        }
    };
    dfs(0, -1);

    ans += dp[0] + 1;
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
