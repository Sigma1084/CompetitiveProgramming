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

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int k, n;
    cin >> k;
    n = 1 << k;

    vector<Z> fact(n + 1);
    fact[0] = 1;
    for (int i = 1; i <= n; ++i) {
        fact[i] = fact[i - 1] * i;
    }

    vector<int> a(n);
    vector<int> cnt(k + 1);

    for (auto &x: a) {
        cin >> x;
        if (x != -1) {
            --x;
            ++cnt[__lg(2*x + 1)];
        }
    }

    function<Z(int, int)> f = [&](int l, int r) -> Z {
        if (r == l) {
            return 1;
        }

        int c0 = 0, c1 = 0;
        for (int i = l; i <= r; ++i) {
            c0 += a[i] == 0;
            c1 += a[i] == 1;
        }

        if (c0 > 1 or c1 > 1) {
            return 0;
        }

        for (int i = l; i <= r; ++i) {
            if (a[i] != -1) {
                a[i] /= 2;
            }
        }

        int m = (l + r) / 2;
        return f(l, m) * f(m + 1, r) * (c0 == 0 and c1 == 0 ? 2 : 1);
    };

    Z ans = f(0, n - 1);
    for (int i = 1; i <= k; ++i) {
        ans *= fact[(1 << (i-1)) - cnt[i]];
    }

    cout << ans << '\n';

    return 0;
}
