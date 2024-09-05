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
class Combinatorics {
    std::array<T, N + 1> _fact, _invFact;

    void precompute() {
        _fact[0] = 1;
        for (unsigned int i = 1; i <= N; ++i) {
            _fact[i] = _fact[i - 1] * i;
        }
        _invFact[N] = T(1) / _fact[N];
        for (unsigned int i = N; i >= 1; --i) {
            _invFact[i - 1] = _invFact[i] * i;
        }
    }

public:
    constexpr Combinatorics() {
        precompute();
    }

    [[nodiscard]] constexpr T fact(int n) const {
        return _fact[n];
    }

    [[nodiscard]] constexpr T invFact(int n) const {
        return _invFact[n];
    }

    [[nodiscard]] constexpr T nCr(unsigned int n, unsigned int r) const {
        return _fact[n] * _invFact[r] * _invFact[n - r];
    }

    [[nodiscard]] constexpr T nPr(unsigned int n, unsigned int r) const {
        return _fact[n] * _invFact[n - r];
    }
};

constexpr unsigned N = 1e6;
Combinatorics<Z, N> C;

constexpr int L = 26;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int k;
    cin >> k;

    array<int, L> a;
    for (auto &x: a) {
        cin >> x;
    }

    vector<Z> dp(k + 1);
    dp[0] = 1;

    for (int i = 0; i < L; ++i) {
        if (a[i] == 0) continue;
        for (int l = k; l >= 0; --l) {
            for (int j = 1; j <= a[i] and l - j >= 0; ++j) {
                dp[l] += dp[l - j] * C.nCr(l, j);
            }
        }
    }

    Z ans = 0;
    for (int i = 1; i <= k; ++i) {
        ans += dp[i];
    }

    cout << ans << '\n';

    return 0;
}
