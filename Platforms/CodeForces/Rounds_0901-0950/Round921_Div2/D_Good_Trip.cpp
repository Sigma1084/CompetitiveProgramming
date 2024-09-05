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

constexpr int N = 2e5;
array<Z, N + 1> fact, invFact, inv;
int preCompute() {
    fact[0] = 1;
    for (int i = 1; i <= N; ++i) {
        fact[i] = fact[i - 1] * i;
    }
    invFact[N] = fact[N].inv();
    for (int i = N; i >= 1; --i) {
        invFact[i - 1] = invFact[i] * i;
    }
    for (int i = 1; i <= N; ++i) {
        inv[i] = fact[i - 1] * invFact[i];
    }
    return 0;
}
auto prec = preCompute();

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    if (n == 2) {
        if (m == 0) {
            cout << 0;
            return;
        }
        int x, y, f;
        cin >> x >> y >> f;
        Z ans = Z(f) * k;
        ans += Z(k) * (k - 1) / 2;
        cout << ans;
        return;
    }

    Z ans = 0;

    Z nC2 = 1LL * n * (n - 1) / 2;

    Z nC2M1Pow = (nC2 - 1).pow(k);
    Z nC2M1Inv = (nC2 - 1).inv();

    Z comb  = 1;
    Z pSum = 0, twoInv = Z(2).inv();

    for (int i = 1; i <= k; ++i) {
        comb *= k - i + 1;
        comb *= inv[i];
        nC2M1Pow *= nC2M1Inv;
        Z p = comb * nC2M1Pow;
        ans += p * Z(1LL * i * (i - 1) / 2);
        pSum += p * i;
    }
    ans *= m;

    ll fs = 0;
    for (int i = 0; i < m; ++i) {
        int x, y, z;
        cin >> x >> y >> z;
        fs += z;
    }
    ans += pSum * fs;

    ans /= nC2.pow(k);

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
