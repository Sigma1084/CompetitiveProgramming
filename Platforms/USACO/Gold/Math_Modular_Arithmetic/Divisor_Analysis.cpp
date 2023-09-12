#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template<int P>
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

constexpr int P = 1000000007;

/**
 * Consider the number n = p^a q^b r^c
 * where p, q, r are prime factors of n
 * 
 * factors of n are of the form
 * p^x q^y r^z 
 * where 0 <= x <= a, 0 <= y <= b, 0 <= z <= c
 * 
 * The number of factors of n is
 * sum_{x, y, z} 1 = (a + 1) (b + 1) (c + 1)
 * 
 * The sum of all factors of n is
 * sum_{x, y, z} p^x q^y r^z
 * = sum_{x} p^x sum_{y} q^y sum_{z} r^z
 * = (1 + p + p^2 + ... + p^a) (1 + q + q^2 + ... + q^b) (1 + ... + r^c)
 * We can use the GM formula for each term and evaluate one by one
 * 
 * Suppose we have only p^a
 * Then, the product pF = 1 * p * p^2 * ... * p^a
 * 
 * Suppose we had p^a q^b
 * Then, the product is
 * pF =   1 * p * p^2 * ... * p^a
 *      * q * q p * q p^2 * ... * q p^a
 *      * q^2 * q^2 p * q^2 p^2 * ... * q^2 p^a
 *      * ...
 *      * q^b * q^b p * q^b p^2 * ... * q^b p^a
 * 
 * Now, if we have pF(p) = 1 * p * p^2 * ... * p^a
 * we can compute pF(pq) = pF(p)^(b + 1) * pF(q)^(a + 1)
 * 
 * If we had p^a q^b r^c
 * Then, the product is
 * pF = pF(pq)^(c + 1) * pF(r)^(a + 1)(b + 1)
 * For every element, we can compute the product of all factors
 */

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;

    Z<P> nF = 1, sF = 1, pF = 1, pFp;
    Z<P - 1> exp = 1;  // We want the power to be modulo P - 1

    for (int p, k; n--; ) {
        cin >> p >> k;
        nF *= k + 1;
        sF *= (Z<P>(p).pow(k + 1) - 1) / (p - 1);

        // Now for the product of all factors
        pFp = Z<P>(p).pow(1LL * k * (k + 1) / 2 % (P - 1));
        pF = pF.pow(k + 1) * pFp.pow(exp());
        exp *= k + 1;
    }

    cout << nF << ' ' << sF << ' ' << pF;

    return 0;
}
