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

    [[nodiscard]] constexpr T fact(unsigned n) const {
        return _fact[n];
    }

    [[nodiscard]] constexpr T invFact(unsigned n) const {
        return _invFact[n];
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

constexpr int N = 1e1;
const Comb<Z, N> C;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (auto &x: a) {
        cin >> x;
    }

    const Z S = accumulate(a.begin(), a.end(), Z(0));

    if (k == n) {
        cout << S << ' ' << 0;
        return;
    }

    /**
     * ## Probability that ALice takes a specific special ball
     * There are n - k normal balls and n - k + 1 spaces between them.
     * This happens only when the special ball is in one of the even spaces
     * 
     * Ignore this for now.
     * If we have s special balls in the even gaps, we will have k - s in the odd gaps.
     * This gives rise to s + 1 spaces between the special balls.
     * 
     * s in ev is comb(s + ev - 1, s)
     */

    int ev = (n - k + 1 + 1) / 2, od = (n - k + 1) / 2;

    // When the selected ball is special
    Z p = 0;
    for (int s = 0; s < k; ++s) {
        // Number of even spots is limit, we need to place s special balls in them
        p += C.comb(s + ev - 1, s) * (ev + s) * C.comb((k - s - 1) + od - 1, k - s - 1);
    }
    p /= C.comb(n, k) * k;
    Z ans = p * accumulate(a.begin(), a.begin() + k, Z(0));

    // When the selected ball is not special, it has to be in an odd place
    p = ((n - k + 1) / 2) * C.fact(n - k - 1);
    p *= C.invFact(n - k);
    ans += p * accumulate(a.begin() + k, a.end(), Z(0));

    cout << ans << ' ' << S - ans;
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
