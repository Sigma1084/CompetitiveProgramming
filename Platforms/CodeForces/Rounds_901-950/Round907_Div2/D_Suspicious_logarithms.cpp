#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/**
 * n -> f -> g
 * 
 * (3, 9, 27, 81)
 * 8 -> 3 -> 1
 * 9 -> 3 -> 2
 * ...
 * 15 -> 3 -> 2
 * 
 * (9, 81, 729, 6561)
 * 512 -> 9 -> 2
 * ...
 * 728 -> 9 -> 2
 * 729 -> 9 -> 3
 * 1023 -> 9 -> 3
 */

constexpr int P = 1000000007;

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

template<typename T>
T intersection(T l1, T r1, T l2, T r2) {
    if (l1 > r2 or l2 > r1) return 0;
    return min(r1, r2) - max(l1, l2) + 1;
}

vector<Z> dp(60);

void preComp() {
    for (int i = 2; i < 60; ++i) {
        // We need to compute powers of i
        __int128_t l = 1LL << i, r = (1LL << (i + 1)) - 1;

        // The [l, r] is the required range

        __int128_t l1 = 1, r1 = i, e = 0;
        while (l1 <= r) {
            dp[i] += Z(intersection(l, r, l1, r1 - 1)) * e;
            l1 *= i;
            r1 *= i;
            e++;
        }
    }
}

Z f(__int128_t k) {
    Z res = 0;
    for (int i = 2; i < 60; ++i) {
        // We need to compute powers of i
        __int128_t l = 1LL << i, r = (1LL << (i + 1)) - 1;
        if (k < l) {
            break;
        }
        if (r <= k) {
            res += dp[i];
            continue;
        }
        r = min(r, k);

        // The [l, r] is the required range

        __int128_t l1 = 1, r1 = i, e = 0;
        while (l1 <= r) {
            res += Z(intersection(l, r, l1, r1 - 1)) * e;
            l1 *= i;
            r1 *= i;
            e++;
        }
    }
    return res;
}

void solve() {
    ll l, r;
    cin >> l >> r;

    cout << f(r) - f(l - 1);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;

    preComp();

    for (int i = 1; i <= t; ++i) {
        solve();
        std::cout << '\n';
    }

    return 0;
}
