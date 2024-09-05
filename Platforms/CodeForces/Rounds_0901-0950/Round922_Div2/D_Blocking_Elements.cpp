#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template <typename T>
class SegTree {
    int n;
    std::vector<T> s;

public:
    static constexpr T ID = 1e18;
    static T f(T a, T b) { return std::min(a, b); }

    SegTree(unsigned _n): n(2*_n - 1), s(2*n, ID) {}

    template <typename U>
    SegTree(const std::vector<U> &a): SegTree(a.size()) {
        std::copy(a.begin(), a.end(), s.begin() + n);
        for (auto i = n - 1; i > 0; --i)
            s[i] = f(s[i*2], s[i*2 + 1]);
    }

    void update(unsigned idx, T val) {
        for (s[idx += n] = val; idx /= 2; )
            s[idx] = f(s[idx*2], s[idx*2 + 1]);
    }

    T query(unsigned l, unsigned r) {
        assert(l <= r);
        T rL = ID, rR = ID;
        for (l += n, r += n; l <= r; l /= 2, r /= 2) {
            if (l % 2 == 1) rL = f(rL, s[l++]);
            if (r % 2 == 0) rR = f(s[r--], rR);
        }
        return f(rL, rR);
    }

    T operator[](unsigned idx) {
        assert(idx < n);
        return s[idx + n];
    }
};

/**
 * Assuming all subarrays are maxed at k
 * dp[i] := min cost to make a[0..i] valid
 *          such that a[i] is a pivot
 */
bool isPossible(int n, const vector<int> &a, ll k) {    
    SegTree<ll> dp(n + 1);
    ll sm = 0;
    for (int i = 0, l = 0; i <= n; ++i) {
        // k <= sum[l...i-1]
        // l-1 is the first valid pivot
        while (sm > k) sm -= a[l++];
        if (l == 0) {
            dp.update(i, a[i]);
        } else {
            dp.update(i, dp.query(l - 1, i - 1) + a[i]);
        }
        sm += a[i];
    }
    return dp[n] <= k;
}

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (auto &x: a) {
        cin >> x;
    }
    a.push_back(0);

    ll m = *max_element(a.begin(), a.end());
    ll M = accumulate(a.begin(), a.end(), 0LL);
    while (m <= M) {
        ll mid = (m + M) / 2;
        if (isPossible(n, a, mid)) {
            M = mid - 1;
        } else {
            m = mid + 1;
        }
    }

    cout << m;
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
