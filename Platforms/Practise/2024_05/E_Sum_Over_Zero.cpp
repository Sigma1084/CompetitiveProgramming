#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template <typename T>
class SegTree {
    int n;
    std::vector<T> s;

public:
    static constexpr T ID = -1e9;
    static T f(T a, T b) { return max(a, b); }

    SegTree(unsigned _n): n(1 << __lg(2*_n - 1)), s(2*n, ID) {}

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

    void print(int n) {
        for (int i = 0; i < n; ++i) {
            cerr << s[i + this->n] << ' ';
        }
        cerr << '\n';
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n = 1;
    std::cin >> n;

    vector<int> a(n);
    for (auto &x: a) {
        cin >> x;
    }

    vector<ll> p(n + 1);
    for (int i = 0; i < n; ++i) {
        p[i + 1] = p[i] + a[i];
    }

    // Co-ordinate compression
    auto v = p;
    sort(v.begin(), v.end());

    /**
     * dp[i + 1] := Answer for [0, i]
     */
    vector<int> dp(n + 1);
    SegTree<int> st(n + 1);
    for (int i = 0; i <= n; ++i) {
        int idx = std::lower_bound(v.begin(), v.end(), p[i]) - v.begin();
        if (i == 0) {
            dp[i] = 0;
        } else {
            dp[i] = max(dp[i - 1], i + st.query(0, idx));
        }
        st.update(idx, dp[i] - i);
    }

    cout << dp[n] << '\n';

    return 0;
}
