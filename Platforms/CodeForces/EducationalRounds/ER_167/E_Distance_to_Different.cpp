#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int P = 1000000007;

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
    friend constexpr bool operator == (Z a, Z b) { return a() == b(); }
    friend constexpr bool operator != (Z a, Z b) { return a() != b(); }

    friend std::ostream& operator << (std::ostream &os, Z a) {
        return os << a();
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, K;
    cin >> n >> K;

    vector<Z> dp(n + 1), sm(n + 1);
    dp[n] = 1; sm[n] = 1;
    for (int k = 1; k <= K; ++k) {
        for (int i = n - k + 2; i <= n; ++i) {
            dp[i] = 0;
        }
        for (int i = n - 1; i >= 0; --i) {
            dp[i] = sm[i + 1];
            if (i + 2 < n) {
                dp[i] -= dp[i + 2];
            }
            sm[i] = dp[i] + sm[i + 1];
        }
        if (n >= 3) {
            dp[0] += dp[2];
        }
        if (k == 2) {
            dp[0] -= 1;
        }
        sm[n] = dp[n];
        for (int i = n - 1; i >= 0; --i) {
            sm[i] = dp[i] + sm[i + 1];
        }
        for (int i = 0; i <= n; ++i) {
            cerr << dp[i] << ' ';
        }
        cerr << '\n';
    }

    cout << dp[0];

    return 0;
}
