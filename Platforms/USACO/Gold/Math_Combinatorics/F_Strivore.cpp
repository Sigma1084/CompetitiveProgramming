#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int P = 1000000007;

class Z {
    int val = 0;
    void normalize() { if (val < 0) val += P; if (val > P) val -= P; }
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
 * s = s1 s2 s3
 * We can insert
 * t1 initially which can be anything but s1
 * t2 between s1 and s2 can not be s1 or s2
 * t3 between s2 and s3 can not be s2 or s3
 * t4 after s3 can be anything but s3
 * 
 * t1 + t2 + t3 + t4 = n
 * where ti have pi choices => pi^ti
 * Number of ways of choosing these possibilities
 * sum_{t1 + t2 + t3 + t4 = n} p1^t1 * p2^t2 * p3^t3 * p4^t4
 * 
 * The possibilities can only be 24, 25
 * sum_{a + b = n} a^24 b^25
 */

constexpr int N = 1000000;
array<Z, N + 1> fact, invFact;

Z comb(int n, int k) {
    return fact[n] * invFact[k] * invFact[n - k];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    fact[0] = 1;
    for (int i = 1; i <= N; ++i) {
        fact[i] = fact[i - 1] * i;
    }
    invFact[N] = fact[N].inv();
    for (int i = N - 1; i >= 0; --i) {
        invFact[i] = invFact[i + 1] * (i + 1);
    }

    int n; cin >> n;
    string s; cin >> s;

    // Number of ways to choose 24 or 25
    int a = 0, b = 2;
    for (int i = 1; i < static_cast<int>(s.size()); ++i) {
        if (s[i] == s[i - 1]) {
            b++;
        } else {
            a++;
        }
    }

    // We need 24^a 25^b taken over all a + b = n
    // We have a positions and b positions
    // t1 + t2 + t3 + ... + ta = i   (i + a - 1) choose (a - 1)
    // tb + tb + tb + ... + tb = n - i
    Z ans = 0;
    for (int i = 0; i <= n; ++i) {
        ans += Z(24).pow(i) * Z(25).pow(n - i)
                * comb(i + a - 1, a - 1) * comb(n - i + b - 1, b - 1);
    }

    cout << ans() << '\n';

    return 0;
}

