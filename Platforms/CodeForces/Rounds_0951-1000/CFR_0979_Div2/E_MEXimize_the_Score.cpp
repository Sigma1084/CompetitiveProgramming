#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int P = 998244353;

class Z {
    int val = 0;

public:
    constexpr Z() = default;
    template<class T> constexpr Z(const T &v): val((P + v%P) % P) {}
    constexpr Z(const Z &z) = default;

    constexpr int operator ()() const { return val; }
    constexpr Z pow(unsigned long long b) const {
        Z ans = 1;
        for (Z a = *this; b; b /= 2, a *= a) if (b % 2) ans *= a;
        return ans;
    }
    constexpr Z inv() const { return pow(P - 2); }

    constexpr Z& operator += (Z a) {
        val += a.val; if (val >= P) val -= P; return *this; }
    constexpr Z& operator -= (Z a) {
        val -= a.val; if (val < 0) val += P; return *this; }
    constexpr Z& operator *= (Z a) {
        val = 1LL * val * a.val % P; return *this; }
    constexpr Z& operator /= (Z a) { return *this *= a.inv(); }

    friend constexpr Z operator + (Z a, Z b) { return a += b; }
    friend constexpr Z operator - (Z a, Z b) { return a -= b; }
    friend constexpr Z operator * (Z a, Z b) { return a *= b; }
    friend constexpr Z operator / (Z a, Z b) { return a /= b; }

    friend std::ostream& operator << (std::ostream &os, Z a) {
        return os << a();
    }
};

template<typename T, unsigned int N>
class Comb {
    std::array<T, N + 1> _fact, _invFact, _inv;

public:
    constexpr Comb() {
        _fact[0] = 1;
        for (int i = 1; i <= N; ++i) {
            _fact[i] = _fact[i - 1] * i;
        }
        _invFact[N] = _fact[N].inv();
        for (int i = N; i >= 1; --i) {
            _invFact[i - 1] = _invFact[i] * i;
            _inv[i] = _fact[i - 1] * _invFact[i];
        }
        _inv[0] = 1;
    }

    [[nodiscard]] inline constexpr T fact(unsigned n) const {
        return _fact[n];
    }

    [[nodiscard]] inline constexpr T invFact(unsigned n) const {
        return _invFact[n];
    }

    [[nodiscard]] inline constexpr T inv(unsigned n) const {
        return _inv[n];
    }

    [[nodiscard]] inline constexpr T perm(unsigned n, unsigned k) const {
        if (k > n) return T(0);
        return _fact[n] * _invFact[n - k];
    }

    [[nodiscard]] inline constexpr T comb(unsigned n, unsigned k) const {
        if (k > n) return T(0);
        return _fact[n] * _invFact[k] * _invFact[n - k];
    }
};

constexpr unsigned int N = 2e5;
const Comb<Z, N> C;

void solve() {
    size_t n;
    cin >> n;

    vector<size_t> f(n);
    for (size_t i = 0; i < n; ++i) {
        int x;
        cin >> x;
        ++f[x];
    }

    vector<Z> p2(n + 1);
    p2[0] = 1;
    for (size_t i = 1; i <= n; ++i) {
        p2[i] = p2[i-1] * 2;
    }

    Z ans = 0;
    vector<Z> dp(f[0] + 1);

    auto add = [&](int x) {
        n -= f[x];
        for (size_t i = 1; i < dp.size(); ++i) {
            ans += dp[i] * i * p2[n];
        }
    };

    for (size_t i = 0; i <= f[0]; ++i) {
        dp[i] = C.comb(f[0], i);
    }
    add(0);

    for (size_t x = 1; n; ++x) {
        vector<Z> dpS(dp.size());
        partial_sum(dp.crbegin(), dp.crend(), dpS.rbegin());

        vector<Z> tot(f[x] + 1), totS(f[x] + 1);
        for (size_t i = 0; i <= f[x]; ++i) {
            tot[i] = C.comb(f[x], i);
        }
        partial_sum(tot.crbegin(), tot.crend(), totS.rbegin());

        dp.resize(min(dp.size(), f[x] + 1));
        for (size_t j = 0; j < dp.size(); ++j) {
            dp[j] = dpS[j] * tot[j] + dp[j] * (totS[j] - tot[j]);
        }

        add(x);
    }

    cout << ans;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;

    while (t--) {
        solve();
        std::cout << '\n';
    }

    return 0;
}
