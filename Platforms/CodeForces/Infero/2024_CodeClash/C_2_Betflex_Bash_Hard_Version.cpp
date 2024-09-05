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
    friend Z operator + (Z a, Z b) { return a += b; }
    friend Z operator - (Z a, Z b) { return a -= b; }
    friend Z operator * (Z a, Z b) { return a *= b; }
    friend Z operator / (Z a, Z b) { return a /= b; }
    constexpr bool operator == (Z a) const { return val == a.val; }
    constexpr bool operator != (Z a) const { return val != a.val; }
    friend ostream& operator << (ostream &os, Z a) { return os << a(); }
};

struct Matrix: array<array<Z, 2>, 2> {
    using Base = array<array<Z, 2>, 2>;
    using Base::Base;
    Matrix() {
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                (*this)[i][j] = 0;
            }
        }
    };
    Matrix(Z a, Z b, Z c, Z d) {
        (*this)[0][0] = a;
        (*this)[0][1] = b;
        (*this)[1][0] = c;
        (*this)[1][1] = d;
    }
    friend Matrix operator * (Z a, const Matrix &b) {
        Matrix c;
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                c[i][j] = a * b[i][j];
            }
        }
        return c;
    }
    friend Matrix operator + (const Matrix &a, const Matrix &b) {
        Matrix c;
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                c[i][j] = a[i][j] + b[i][j];
            }
        }
        return c;
    }
    friend Matrix operator - (const Matrix &a, const Matrix &b) {
        Matrix c;
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                c[i][j] = a[i][j] - b[i][j];
            }
        }
        return c;
    }
    friend Matrix operator * (const Matrix &a, const Matrix &b) {
        Matrix c;
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                for (int k = 0; k < 2; ++k) {
                    c[i][j] += a[i][k] * b[k][j];
                }
            }
        }
        return c;
    }
    Matrix pow(ll b) const {
        Matrix ans = Matrix(1, 0, 0, 1);
        for (Matrix a = *this; b; b /= 2, a = a * a) {
            if (b % 2) {
                ans = ans * a;
            }
        }
        return ans;
    }
};

const Matrix I(1, 0, 0, 1);
const Matrix f(1, 1, 1, 0);
const Matrix fInv(0, 1, 1, -1);

Z ans(ll n) {
    if (n == 0) {
        return 0;
    }
    Matrix res = f.pow(4) * (f.pow(n) - I) - n * f.pow(2);
    return res[1][0];
}

void solve() {
    ll l, r;
    cin >> l >> r;

    cout << ans(r) - ans(l-1);
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
