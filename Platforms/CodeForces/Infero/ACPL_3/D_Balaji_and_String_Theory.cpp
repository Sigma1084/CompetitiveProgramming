#include <bits/stdc++.h>
using namespace std;

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

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    string s, t;
    cin >> s >> t;

    int n, k;
    n = s.size();
    cin >> k;

    vector<Z> dp(n);
    dp[0] = 1;
    for (int i = 1; i <= k; ++i) {
        // We get a newDp
        Z s = accumulate(dp.begin(), dp.end(), Z(0));
        for (auto &x: dp) {
            x = s - x;
        }
    }

    Z ans = 0;
    for (int i = 0; i < n; ++i) {
        if (s == t) {
            ans += dp[i];
        }
        rotate(s.begin(), s.begin() + 1, s.end());
    }

    cout << ans << '\n';

    return 0;
}
