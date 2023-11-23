#include <bits/stdc++.h>
using namespace std;
using ll = long long;

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

/**
 * n = 5
 * k = 2 => (1, 1, 3) 3
 * k = 3 => (1, 2, 2) and (2, 1, 2) 2 + 2 = 4
 * k = 4 => (1, 3, 1) and (2, 2, 1) and (3, 1, 1) = 1 + 2 + 1 = 4
 */
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    // Precompute phi(n)
    vector<int> phi(n + 1);
    iota(phi.begin(), phi.end(), 0);
    for (int i = 2; i <= n; ++i) {
        if (phi[i] != i) continue;
        for (int j = i; j <= n; j += i) {
            phi[j] = phi[j] / i * (i - 1);
        }
    }

    Z ans = 0;
    for (int c = 1; c <= n - 2; ++c) {
        // a + b = n - c
        // Over all divisors of n - c
        for (int i = 1; i * i <= n - c; ++i) {
            if ((n - c) % i != 0) continue;
            // i is a divisor of n - c
            for (int d: set{i, (n - c) / i}) {
                if (d == n - c) continue;
                ans += 1LL * lcm(c, d) * phi[(n - c) / d];
            }
        }
    }

    cout << ans << '\n';

    return 0;
}
