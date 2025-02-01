#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int P = 998244353;

class Z {
    int val = 0;

public:
    constexpr Z() = default;
    template<class T> constexpr Z(const T &v): val((P + v%P) % P) {}
    constexpr Z(const Z &z) = default;

    constexpr int operator ()() const { return val; }
    constexpr Z pow(unsigned long long b) const {
        Z ans = 1;
        for (Z a = *this; b; b /= 2, a *= a) if (b % 2) ans *= a;
        return ans;
    }
    constexpr Z inv() const { return pow(P - 2); }

    constexpr Z& operator += (Z a) {
        val += a.val; if (val >= P) val -= P; return *this; }
    constexpr Z& operator -= (Z a) {
        val -= a.val; if (val < 0) val += P; return *this; }
    constexpr Z& operator *= (Z a) {
        val = 1LL * val * a.val % P; return *this; }
    constexpr Z& operator /= (Z a) { return *this *= a.inv(); }

    friend constexpr Z operator + (Z a, Z b) { return a += b; }
    friend constexpr Z operator - (Z a, Z b) { return a -= b; }
    friend constexpr Z operator * (Z a, Z b) { return a *= b; }
    friend constexpr Z operator / (Z a, Z b) { return a /= b; }

    friend std::ostream& operator << (std::ostream &os, Z a) {
        return os << a();
    }
};

constexpr int A = 5000;
constexpr Z inv2 = Z(2).inv();

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    for (auto &x: a) {
        cin >> x;
    }
    sort(a.begin(), a.end());

    array<Z, A + 1> c{};
    c[0] = 1;

    Z ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= a[i]; ++j) {
            ans += a[i] * c[j];
        }
        for (int j = a[i] + 1; j <= A; ++j) {
            ans += (j + a[i] + ((j^a[i]) & 1)) * c[j] * inv2;
        }
        for (int j = A - a[i]; j >= 0; --j) {
            c[j + a[i]] += c[j];
        }
    }

    cout << ans;

    return 0;
}
