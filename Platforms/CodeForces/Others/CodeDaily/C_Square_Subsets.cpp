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
    friend Z operator * (Z a, Z b) { return Z(a) *= b; }
    Z operator / (Z a) { return Z(*this) /= a; }
    constexpr bool operator == (Z a) const { return val == a.val; }
    constexpr bool operator != (Z a) const { return val != a.val; }
    friend ostream& operator << (ostream &os, Z a) { return os << a(); }
};



constexpr int N = 1'000'000;
std::array<int, N + 1> lPF;
std::vector<int> primes;

constexpr bool isPrime(int n) {
    return lPF[n] == n;
}

void sieve() noexcept {
    std::iota(lPF.begin(), lPF.end(), 0);
    lPF[0] = lPF[1] = -1;
    for (int i = 2; i * i <= N; ++i) {
        if (lPF[i] != i) continue;
        for (int j = i * i; j <= N; j += i) {
            if (lPF[j] == j) lPF[j] = i;
        }
    }
    for (int i = 2; i <= N; ++i) {
        if (isPrime(i)) {
            primes.push_back(i);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    sieve();

    int n;
    cin >> n;

    vector<int> a(n);
    for (int &x: a) {
        cin >> x;
    }

    const int LIM = std::sqrt(70);
    map<int, vector<int>> classes;

    for (int x: a) {
        int y = x;
        while (x > 1 and lPF[x] <= LIM) {
            x /= lPF[x];
        }
        classes[x].push_back(y / x);
    }

    constexpr int nP = 4;
    array<int, nP> ps = {2, 3, 5, 7};

    map<int, vector<Z>> dps;

    for (auto &[c, vec]: classes) {
        // Solve for the class
        vector<Z> dp(1 << (1 + nP));
        dp[0] = 1;  // 0 factors

        for (int x: vec) {
            int mask = 1 << nP;
            for (int i = 0; i < nP; ++i) {
                while (x % ps[i] == 0) {
                    mask ^= 1 << i;
                    x /= ps[i];
                }
            }
            vector<Z> ndp = dp;
            for (int i = 0; i < dp.size(); ++i) {
                ndp[i ^ mask] += dp[i];
            }
            dp = ndp;
        }

        if (c == 1) {
            for (int i = 0; i < (1 << nP); ++i) {
                dp[i] += dp[i ^ (1 << nP)];
            }
        }
        dp.resize(1 << nP);

        dps[c] = dp;
    }

    vector<Z> ansDp(1 << nP);
    ansDp[0] = 1;
    for (const auto &[c, dp]: dps) {
        vector<Z> ndp(1 << nP);
        for (int m1 = 0; m1 < (1 << nP); ++m1) {
            for (int m2 = 0; m2 < (1 << nP); ++m2) {
                ndp[m1 ^ m2] += dp[m1] * ansDp[m2];
            }
        }
        ansDp = ndp;
    }

    cout << ansDp[0] - 1 << '\n';

    return 0;
}
