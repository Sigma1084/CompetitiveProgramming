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

namespace combinatorics {
    constexpr int N = 1e6;

    constexpr auto getArrays() {
        std::array<Z, N + 1> fact, invFact;
        fact[0] = 1;
        for (unsigned int i = 1; i <= N; ++i) {
            fact[i] = fact[i - 1] * i;
        }
        invFact[N] = Z(1) / fact[N];
        for (unsigned int i = N; i >= 1; --i) {
            invFact[i - 1] = invFact[i] * i;
        }
        return std::make_pair(fact, invFact);
    }
    const auto [fact, invFact] = getArrays();

    [[nodiscard]] constexpr Z nCr(unsigned int n, unsigned int r) {
        return fact[n] * invFact[r] * invFact[n - r];
    }

    [[nodiscard]] constexpr Z nPr(unsigned int n, unsigned int r) {
        return fact[n] * invFact[n - r];
    }
}
using combinatorics::fact, combinatorics::invFact;
using combinatorics::nCr, combinatorics::nPr;

struct Info {
    int sz, l, r;
    Z ans;

    friend Info operator+(const Info &a, const Info &b) {
        Info res;
        res.sz = a.sz + b.sz;
        res.l = a.l == a.sz ? a.l + b.l : a.l;
        res.r = b.r == b.sz ? b.r + a.r : b.r;
        res.ans = a.ans + b.ans + Z(a.r) * b.l;
    }
};

constexpr int K = 60;
constexpr array<array<Z, K + 1>, K + 1> prec() {
    array<array<Z, K + 1>, K + 1> res;
    for (int l = 0; l <= K; ++l) {
        for (int k = 0; k <= K; ++k) {
            // Answer for [0, 2^l) with maxBit = k
            
        }
    }
}


void solve() {
    ll n;
    int k;
    cin >> n >> k;
    --n;

    Z res = 0;
    while (n >= 0) {
        if (k == 1) {
            for (int i = 0; i <= min(n, 2LL); ++i) {
                res += i + 1;
            }
            if (n <= 2) {
                break;
            }
            for (ll cur = 4; cur <= n; cur *= 2) {
                if (cur <= n) {
                    res += 1;
                }
            }
            break;
        }
        if (n < 1LL << (k + 1)) {
            if (n + 1 == 1LL << (k + 1)) {
                n--;
            }
            res += comb(n + 1);
            break;
        }
        res += comb((1LL << (k + 1)) - 1);
        int l = k + 1;
        while (1LL << (l+1) <= n) {
            res += f(l++, k);
        }
        n -= 1LL << l;
        --k;
    }

    cout << res;
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
