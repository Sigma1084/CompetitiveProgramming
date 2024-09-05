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

    friend constexpr Z operator + (Z a, Z b) { return a += b; }
    friend constexpr Z operator - (Z a, Z b) { return a -= b; }
    friend constexpr Z operator * (Z a, Z b) { return a *= b; }
    friend constexpr Z operator / (Z a, Z b) { return a /= b; }
    friend constexpr bool operator == (Z a, Z b) { return a() == b(); }
    friend constexpr bool operator != (Z a, Z b) { return a() != b(); }

    friend std::ostream& operator << (std::ostream &os, Z a) {
        return os << a();
    }
};

template<typename T, unsigned N>
class Comb {
    std::array<T, N + 1> _fact, _invFact;

public:
    constexpr Comb() {
        _fact[0] = 1;
        for (int i = 1; i <= N; ++i) {
            _fact[i] = _fact[i - 1] * i;
        }
        _invFact[N] = _fact[N].inv();
        for (int i = N; i >= 1; --i) {
            _invFact[i - 1] = _invFact[i] * i;
        }
    }

    const std::array<T, N + 1> &fact = _fact;
    const std::array<T, N + 1> &invFact = _invFact;

    constexpr T perm(unsigned n, unsigned k) const {
        if (k > n) return T(0);
        return _fact[n] * _invFact[n - k];
    }

    constexpr T comb(unsigned n, unsigned k) const {
        if (k > n) return T(0);
        return _fact[n] * _invFact[k] * _invFact[n - k];
    }
};

constexpr int N = 1e6;
const Comb<Z, N> C;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    int num, den;
    cin >> num >> den;

    Z p = Z(num) / Z(den);
    Z ans = 0, o = 0, e = 1;
    for (int s = 1; s <= min(k, n); ++s) {
        e = o * p + e * (1 - p);
        o = 1 - e;
        ans += C.comb(n, s) * e.pow(m);
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