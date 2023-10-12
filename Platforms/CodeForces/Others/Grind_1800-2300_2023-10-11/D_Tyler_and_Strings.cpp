#include <bits/stdc++.h>
using namespace std;
using ll = long long;


#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

template <typename T>
using OSet = __gnu_pbds::tree<T,
    __gnu_pbds::null_type,
    std::less<>,
    __gnu_pbds::rb_tree_tag,
    __gnu_pbds::tree_order_statistics_node_update
>;


constexpr int P = 998244353;

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


constexpr int N = 200000;
std::array<Z, N + 1> inv, fact, invFact;

void preCompute() {
    fact[0] = 1;
    for (int i = 1; i <= N; ++i) {
        fact[i] = fact[i-1] * i;
    }
    invFact[N] = fact[N].inv();
    for (int i = N-1; i >= 0; --i) {
        invFact[i] = invFact[i+1] * (i+1);
        inv[i+1] = fact[i] * invFact[i+1];
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    preCompute();

    int n, m;
    cin >> n >> m;

    vector<int> s(n), t(m);
    for (auto &x: s) cin >> x;
    for (auto &x: t) cin >> x;

    OSet<pair<int, int>> prevPairs;
    map<int, int> cnt;
    for (int i = 0; i < n; ++i) {
        prevPairs.insert({s[i], i+1});
        cnt[s[i]]++;
    }

    Z total = fact[n];
    for (auto [x, f]: cnt) {
        total *= invFact[f];
    }

    Z ans = 0;
    int i = 0;
    for (i = 0; i < min(m, n); ++i) {
        // Number of characters less than t[i]
        int sumLess = prevPairs.order_of_key({t[i], 0});
        ans += total * sumLess * inv[n - i];
        if (cnt[t[i]] == 0) break;
        total = total * cnt[t[i]] * inv[n - i];
        cnt[t[i]]--;
        prevPairs.erase(prevPairs.lower_bound({t[i], 0}));
        s[i] = t[i];
    }

    if (n < m and i == n) {
        ans += 1;
    }

    cout << ans;

    return 0;
}
