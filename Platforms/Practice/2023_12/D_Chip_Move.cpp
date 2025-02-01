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


int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    // From 0, we can reach k, 2k, 3k, ...
    // Number of ways to reach 0 with a k is 1
    // If we can not reach i with k, we can not reach i with k + 1

    int mx = k;
    for (int i = 0; i + mx <= n; ) {
        // We have mx at i
        i += mx;
        mx += 1;
    }

    vector<Z> ans(n + 1);
    vector<Z> dp(n + 1);
    dp[0] = 1;
    for (int j = k; j <= mx; ++j) {
        vector<Z> dp2(n + 1);
        for (int i = 0; i + j <= n; ++i) {
            dp[i + j] += dp[i];
            dp2[i + j] += dp[i];
        }
        for (int i = 0; i <= n; ++i) {
            ans[i] += dp[i];
        }
        swap(dp, dp2);
    }

    Z b2 = Z(1) / 2;
    for (int i = 1; i <= n; ++i) {
        cout << ans[i] * b2 << ' ';
    }

    return 0;
}
