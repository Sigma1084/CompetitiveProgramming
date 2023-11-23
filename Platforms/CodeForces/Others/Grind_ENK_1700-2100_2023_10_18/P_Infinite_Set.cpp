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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, p;
    cin >> n >> p;

    vector<int> a(n);
    for (int &x: a) {
        cin >> x;
    }
    sort(a.begin(), a.end());

    set<int> s;
    vector<Z> dp(max(p + 2, 32));
    for (int y: a) {
        int x = y;
        while (y > 0) {
            if (s.find(y) != s.end()) {
                break;
            }
            if (y > 1 and y % 2 == 1) {
                y /= 2;
            } else if (y % 4 == 0) {
                y /= 4;
            } else {
                dp[__lg(x) + 1] += 1;
                s.insert(x);
                break;
            }
        }
    }

    for (int i = 1; i < p; ++i) {
        dp[i+1] += dp[i];
        dp[i+2] += dp[i];
    }

    cout << accumulate(dp.begin() + 1, dp.begin() + p + 1, Z(0));


    return 0;
}
