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

constexpr int N = 500;
using Grid = array<array<Z, N + 1>, N + 1>;

/**
 * Get the grid in such a way that
 * grid[i][j] := Number of ways of going from (0, 0) to (i, j) such that
 * the path does not cross over the line y = x
 */
constexpr Grid getGrid() {
    Grid grid{};
    grid[0][0] = 1;
    for (int i = 1; i <= N; ++i) {
        grid[0][i] = grid[0][i - 1];
    }
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            grid[i][j] = grid[i - 1][j] + grid[i][j - 1];
            if (i > j) {
                grid[i][j] = 0;
            }
        }
    }
    return grid;
};

const auto grid = getGrid();

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    /**
     * f[i] := We have i cards of a non-1 suite lesser
     * g[i] := We have i cards of the suite 1 greater
     * It can be proved that f[i] = g[i] and so we will be using f[i] only
     */
    vector<Z> f(m + 1);
    for (int i = 0, j = m; i <= j; ++i, --j) {
        f[j - i] = grid[i][j];
    }

    // Need to compute a dp such that dp[i] = Number of ways of selecting i less cards
    vector<Z> dp(m + 1);
    dp[0] = 1;
    for (int suite = 2; suite <= n; ++suite) {
        vector<Z> ndp(m + 1);
        for (int i = 0; i <= m; ++i) {
            for (int j = 0; j <= i; ++j) {
                ndp[i] += dp[j] * f[i - j];
            }
        }
        dp = move(ndp);
    }

    Z ans = 0;
    for (int i = 0; i <= m; ++i) {
        ans += dp[i] * f[i];
    }

    cout << ans;

    return 0;
}
