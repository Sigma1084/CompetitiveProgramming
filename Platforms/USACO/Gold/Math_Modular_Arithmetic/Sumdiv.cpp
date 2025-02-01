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

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    freopen("sumdiv.in", "r", stdin);
    freopen("sumdiv.out", "w", stdout);

    ll a, b;
    cin >> a >> b;
    if (a % P == 0) {
        a /= P;
    }

    vector<pair<ll, int>> factors;
    for (ll f = 2; f * f <= a; ++f) {
        if (a % f) continue;
        factors.emplace_back(f, 0);
        while (a % f == 0) {
            a /= f;
            factors.back().second++;
        }
    }
    if (a > 1) {
        factors.emplace_back(a, 1);
    }

    Z ans = 1;
    for (auto [p, e] : factors) {
        if (p % P == 1) {
            ans *= e * Z(b) + 1;
        } else {
            ans *= (Z(p).pow(b % (P - 1) * e + 1) - 1) / (Z(p) - 1);
        }
    }

    cout << ans << '\n';

    return 0;
}
