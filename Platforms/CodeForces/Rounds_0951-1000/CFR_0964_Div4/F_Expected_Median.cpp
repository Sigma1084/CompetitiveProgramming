#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int P = 1000000007;

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

    friend constexpr Z operator - (Z a, Z b) { return a -= b; }
    friend constexpr Z operator * (Z a, Z b) { return a *= b; }
    friend constexpr Z operator / (Z a, Z b) { return a /= b; }
    friend constexpr Z operator + (Z a, Z b) { return a += b; }

    friend std::ostream& operator << (std::ostream &os, Z a) {
        return os << a();
    }
};

template<typename T, unsigned N>
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

    [[nodiscard]] constexpr T fact(unsigned n) const {
        return _fact[n];
    }

    [[nodiscard]] constexpr T invFact(unsigned n) const {
        return _invFact[n];
    }

    [[nodiscard]] constexpr T inv(unsigned n) const {
        return _inv[n];
    }

    [[nodiscard]] constexpr T perm(unsigned n, unsigned k) const {
        if (k > n) return T(0);
        return _fact[n] * _invFact[n - k];
    }

    [[nodiscard]] constexpr T comb(unsigned n, unsigned k) const {
        if (k > n) return T(0);
        return _fact[n] * _invFact[k] * _invFact[n - k];
    }
};

constexpr int N = 1e6;
const Comb<Z, N> C;

void solve() {
    int n, k;
    cin >> n >> k;

    int o = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        o += x == 1;
    }

    Z ans = 0;
    for (int i = (k + 1) / 2; i <= min(n, o); ++i) {
        ans += C.comb(o, i) * C.comb(n - o, k - i);
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
