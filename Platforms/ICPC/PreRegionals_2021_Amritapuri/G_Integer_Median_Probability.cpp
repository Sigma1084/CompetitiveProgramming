#include <bits/stdc++.h>
using namespace std;

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

constexpr int N = 500000;
array<Z, N + 1> fact, invFact;

void preCompute() {
    fact[0] = 1;
    for (int i = 1; i <= N; ++i) {
        fact[i] = fact[i - 1] * i;
    }
    invFact[N] = fact[N].inv();
    for (int i = N - 1; i >= 0; --i) {
        invFact[i] = invFact[i + 1] * (i + 1);
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    preCompute();

    int n, m;
    cin >> n >> m;

    if (n % 2 == 1) {
        cout << 1;
        return 0;
    }

    vector<Z> pow(m + 1);
    for (int i = 1; i <= m; ++i) {
        pow[i] = Z(i).pow(n / 2);
    }

    auto dp = pow;
    dp.resize(m + 3);
    for (int i = m; i >= 1; --i) {
        // rights
        dp[i] = pow[m - i + 1] - pow[m - i];
        dp[i] += dp[i + 2];
    }

    Z ans = 0;
    for (int a = 1; a <= m; ++a) {
        ans += (pow[a] - pow[a-1]) * dp[a + 1];
    }

    ans *= fact[n] * invFact[n / 2] * invFact[n / 2];
    ans /= Z(m).pow(n);
    ans = Z(1) - ans;

    cout << ans;
}
