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
    Z operator + (Z a) { return Z(*this) += a; }
    Z operator - (Z a) { return Z(*this) -= a; }
    Z operator * (Z a) { return Z(*this) *= a; }
    Z operator / (Z a) { return Z(*this) /= a; }
    constexpr bool operator == (Z a) const { return val == a.val; }
    constexpr bool operator != (Z a) const { return val != a.val; }
    friend ostream& operator << (ostream &os, Z a) { return os << a(); }
};

constexpr int N = 2e5;
array<Z, N + 1> fact, ifact;
void prec() {
    fact[0] = 1;
    for (int i = 1; i <= N; ++i) {
        fact[i] = fact[i - 1] * i;
    }
    ifact[N] = fact[N].inv();
    for (int i = N; i >= 1; --i) {
        ifact[i - 1] = ifact[i] * i;
    }
}

Z perm(int n, int k) {
    return fact[n] * ifact[n - k];
}

Z comb(int n, int k) {
    return fact[n] * ifact[k] * ifact[n - k];
}


void solve() {
    int n, m1, m2;
    cin >> n >> m1 >> m2;

    vector<int> p1(m1), p2(m2);
    for (auto &x: p1) {
        cin >> x;
    }
    for (auto &x: p2) {
        cin >> x;
    }

    if (p1.front() != 1 or p2.back() != n 
            or p1.back() != p2.front()) {
        cout << 0;
        return;
    }

    // First divide into 2 blocks
    Z ans = comb(n - 1, p1.back() - 1);

    reverse(p1.begin(), p1.end());
    for (int &x: p2) {
        x = n - x + 1;
    }

    for (auto &p: {p1, p2}) {
        for (int i = 0; i + 1 < p.size(); ++i) {
            ans *= perm(p[i] - 2, p[i] - p[i+1] - 1);
        }
    }

    cout << ans;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    prec();

    int t = 1;
    std::cin >> t;

    for (int i = 1; i <= t; ++i) {
        solve();
        std::cout << '\n';
    }

    return 0;
}
