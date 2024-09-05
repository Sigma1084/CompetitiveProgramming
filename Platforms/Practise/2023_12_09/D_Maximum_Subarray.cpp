#include <bits/stdc++.h>
using namespace std;
using ll = long long;


template<typename T, typename U = T>
struct PrefixSum {
    std::vector<T> pref;
public:
    PrefixSum() = default;

    PrefixSum(const vector<U> &a) {
        assign(a);
    }

    void assign(const vector<U> &a) {
        pref.resize(a.size());
        pref[0] = a[0];
        for (std::size_t i = 1; i < a.size(); ++i) {
            pref[i] = pref[i - 1] + a[i];
        }
    }

    T query(int l, int r) {
        if (l > r) {
            return 0;
        } else if (l == 0) {
            return pref[r];
        } else {
            return pref[r] - pref[l - 1];
        }
    }

    constexpr const T &operator[](int i) const {
        return pref[i];
    }

    constexpr const std::vector<T> &operator()() const {
        return pref;
    }

    void debug() {
        for (auto x: pref) {
            cerr << x << ' ';
        }
        cerr << '\n';
    }
};


void solve() {
    int n, k, v;
    cin >> n >> k >> v;

    vector<int> a(n);
    for (auto &x: a) {
        cin >> x;
        x -= v;
    }
    v += v;

    PrefixSum<ll, int> pref(a);

    if (v <= 0) {
        // For every i, find
        // Special cases when the length is more than k
        ll ans = 0;

        for (int i = 0; i < k; ++i) {
            for (int j = i + n - k - 1; j < n; ++j) {
                cerr << i << ' ' << j << '\n';
                ll cur = pref.query(i, j);
                cur += (k - (i + n - 1 - j)) * v;
                ans = max(ans, cur);
            }
        }

        ll mx = 0;
        for (int i = 0; i + k < n; ++i) {
            mx = max(mx, pref[i]);
        }
        for (int i = 0; i < n; ++i) {
            ans = max(ans, mx - pref.query(0, i));
            if (i + k < n) {
                mx = max(mx, pref[i + k]);
            }
        }

        cout << ans;
    } else {

        ll ans = 0;
        for (int i = 0; i < n; ++i) {
            ll cur = 0;
            for (int j = i; j < min(n, i + k); ++j) {
                cur += a[j] + v;
                ans = max(ans, cur);
            }
        }

        ll mn = 0;
        for (int i = 0; i + k <= n; ++i) {
            ans = max(ans, pref.query(0, i + k - 1) - mn + k * v);
            mn = min(mn, pref.query(0, i));
        }

        cout << ans;
    }
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
