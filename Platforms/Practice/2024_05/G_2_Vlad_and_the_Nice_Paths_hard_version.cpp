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
 
    friend std::ostream& operator << (std::ostream &os, Z a) {
        return os << a();
    }
};

template<typename T, unsigned int N>
class Combinatorics {
    std::array<T, N + 1> _fact, _invFact;
 
private:
    void precompute() {
        _fact[0] = 1;
        for (unsigned int i = 1; i <= N; ++i) {
            _fact[i] = _fact[i - 1] * i;
        }
        _invFact[N] = T(1) / _fact[N];
        for (unsigned int i = N; i >= 1; --i) {
            _invFact[i - 1] = _invFact[i] * i;
        }
    }
 
public:
    constexpr Combinatorics() {
        precompute();
    }
 
    constexpr T fact(int n) const {
        return _fact[n];
    }
 
    constexpr T invFact(int n) const {
        return _invFact[n];
    }
 
    constexpr T comb(unsigned int n, unsigned int r) const {
        if (r > n) return T(0);
        return _fact[n] * _invFact[r] * _invFact[n - r];
    }
 
    constexpr T perm(unsigned int n, unsigned int r) const {
        if (r > n) return T(0);
        return _fact[n] * _invFact[n - r];
    }
};
 
constexpr unsigned N = 1e6;
Combinatorics<Z, N> C;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (auto &x: a) {
        cin >> x;
    }

    if (k == 1) {
        cout << 1;
        return;
    }

    map<int, vector<int>> mp;
    vector<pair<int, Z>> dp(n + 1);  // [num, val]
    dp[0] = {0, Z(1)};
    for (int i = 0; i < n; ++i) {
        mp[a[i]].push_back(i);
        dp[i + 1] = dp[i];
        if (mp[a[i]].size() < k) continue;

        const auto &v = mp[a[i]];
        int j = v.size() - k;
        // v[j] is the index where it starts

        if (dp[v[j]].first == dp[i+1].first) {
            // Here, we will be adding one extra
            dp[i + 1].first += 1;
            dp[i + 1].second = 0;
        }

        for (; j >= 0; --j) {
            if (dp[v[j]].first == dp[i+1].first - 1) {
                // We are currently at j.
                // We need to select k-1 out of the v.size() - j
                dp[i+1].second += dp[v[j]].second * C.comb(v.size() - j - 2, k - 2);
            } else {
                break;
            }
        }
    }

    cout << dp[n].second;
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