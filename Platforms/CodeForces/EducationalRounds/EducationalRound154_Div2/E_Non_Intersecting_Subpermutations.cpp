#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int P = 998'244'353;

class Z {
    int val = 0;
    void normalize() { if (val < 0) val += P; if (val > P) val -= P; }
public:
    Z() = default;
    template<class T> Z(const T &v): val((P + v%P) % P) {}
    Z(const Z &z) = default;
    Z operator - () const { return Z(0) -= val; }
    int operator ()() const { return val; }
    Z pow(int64_t b) const {
        assert(b >= 0); Z ans = 1;
        for (Z a = *this; b; b /= 2, a *= a) if (b % 2) ans *= a;
        return ans;
    }
    Z inv() const { return pow(P - 2); }
    Z& operator += (Z a) { val += a.val; normalize(); return *this; }
    Z& operator -= (Z a) { val -= a.val; normalize(); return *this; }
    Z& operator *= (Z a) { val = (int64_t) val * a.val % P; return *this; }
    Z& operator /= (Z a) { return *this *= a.inv(); }
    Z& operator ++ (int) { return operator+=(1); }
    Z& operator -- (int) { return operator-=(1); }
    Z operator + (Z a) { return Z(*this) += a; }
    Z operator - (Z a) { return Z(*this) -= a; }
    Z operator * (Z a) { return Z(*this) *= a; }
    Z operator / (Z a) { return Z(*this) /= a; }
    bool operator == (Z a) const { return val == a.val; }
    bool operator != (Z a) const { return val != a.val; }
    bool operator < (Z a) const { return val < a.val; }
    bool operator > (Z a) const { return val > a.val; }
    friend std::ostream& operator << (std::ostream &o, Z m) { return o << m.val; }
    friend std::istream& operator >> (std::istream &i, Z m) { return i >> m.val; }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    Z ans = 0;
    for (int i = 0, j = n - k + 1; i < k and j > 0; i++, j--) {
        if (i % 2 == 0){
            ans += Z(k).pow(j - 1) * j;
        } else {
            ans -= Z(k).pow(j - 1) * j;
        }
    }

    for (int i = 1; i <= k; i++) {
        ans *= i;
    }

    cout << ans();

    return 0;
}
