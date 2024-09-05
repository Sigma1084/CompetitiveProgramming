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

constexpr int N = 150, B = 60, W = 10, V = 150;
bool vis[N + 1][B + 1][W + 1][V + 1];
Z dp[N + 10][B + 1][W + 1][V + 10][3];

const Z inv6 = Z(6).inv();
constexpr array<int, 5> pos = {1, 2, 3, 4, 6};

// [0] -> Virat is out
// [1] -> Virat is not out and on strike
// [2] -> Virat is not out and not on strike

Z f(int n, int b, int w, int v, int s) {
    // n runs remaining
    // b balls remaining
    // w wickets remaining
    // v Virat score rn
    // If virat is out

    if (n <= 0) {
        return v >= 100;
    }

    if (b <= 0 or w <= 0) {
        return 0;
    }

    if (vis[n][b][w][v]) {
        return dp[n][b][w][v][s];
    }

    auto &cur = dp[n][b][w][v];
    vis[n][b][w][v] = true;

    // s = 0
    if (v >= 100) {
        // Then we can talk about cur[0]
        cur[0] += f(n, b - 1, w + 1, v, 0);
        for (int r: pos) {
            cur[0] += f(n - r, b - 1, w, v, 0);
        }
    } else {
        cur[0] = 0;
    }

    // Suppose a wicket falls in the current ball

    // If s = 1
    cur[1] += f(n, b - 1, w - 1, v, 0);  // Virat gets out
    if (b % 6 == 1) {
        // Opposite batsman is out and next turn Virat is on strike
        cur[2] += f(n, b - 1, w - 1, v, 1);
    }

    for (int r: pos) {
        int ch = (b % 6 == 1) ^ (r % 2);
        ch *= (1 ^ 2);
        cur[1] += f(n - r, b - 1, w, v + r, 1 ^ ch);
        cur[2] += f(n - r, b - 1, w, v, 2 ^ ch);
    }

    cur[0] *= inv6;
    cur[1] *= inv6;
    cur[2] *= inv6;

    cerr << "dp[" << n << "][" << b << "][" << w << "][" << v << "][" << 0 << "] = " << cur[0] << '\n';
    cerr << "dp[" << n << "][" << b << "][" << w << "][" << v << "][" << 1 << "] = " << cur[1] << '\n';
    cerr << "dp[" << n << "][" << b << "][" << w << "][" << v << "][" << 2 << "] = " << cur[2] << '\n';

    return cur[s];
}

void solve() {
    int n, b, w, v;
    cin >> n >> b >> w >> v;
    cout << f(n, b, 10 - w, v, 1);
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
