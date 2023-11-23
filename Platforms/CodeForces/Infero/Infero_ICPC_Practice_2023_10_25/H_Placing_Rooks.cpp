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


constexpr int N = 1000000;
array<Z, N + 1> fact, invFact;

void preCompute() {
    fact[0] = 1;
    for (int i = 1; i <= N; ++i) {
        fact[i] = fact[i-1] * i;
    }
    invFact[N] = fact[N].inv();
    for (int i = N; i >= 1; --i) {
        invFact[i-1] = invFact[i] * i;
    }
}

Z comb(int n, int k) {
    if (k < 0 || k > n) return 0;
    return fact[n] * invFact[k] * invFact[n-k];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    preCompute();

    int n;
    ll k;
    cin >> n >> k;

    if (k >= n) {
        cout << 0 << '\n';
        return 0;
    } else if (k == 0) {
        cout << fact[n] << '\n';
        return 0;
    }

    Z ans = 0;

    for (int i = 0, j = 1; i <= n - k; ++i, j *= -1) {
        ans += Z(j) * Z(n - k - i).pow(n) * comb(n - k, i);
    }

    // Choosing the n - k columns
    ans *= comb(n, n - k) * 2;

    cout << ans;

    return 0;
}
