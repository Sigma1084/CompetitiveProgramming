#include <bits/stdc++.h>
using namespace std;
using ll = long long;


template <typename T>
class SegTree {
    int n;
    std::vector<T> s;

public:
    static constexpr T ID = -1e18;
    static T f(T a, T b) { return std::max(a, b); }

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

    void print(int lim = -1) {
        if (lim == -1) lim = n;
        for (int i = 0; i < lim; ++i) {
            cerr << s[i + n] << ' ';
        }
        cerr << '\n';
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, c, m;
    cin >> n >> c >> m;

    vector<pair<int, ll>> a(m);
    for (auto &[t, p]: a) {
        cin >> t >> p;
        --t;
    }

    // For lsg, let us add costs from rightmost
    // For rsg, let us add costs from leftmost
    SegTree<ll> lsg(n), rsg(n);
    for (int i = 0; i < n; ++i) {
        lsg.update(i, -ll(n - 1 - i) * c);
        rsg.update(i, -ll(i) * c);
    }

    // cerr << "lsg and rsg initialized\n";
    // lsg.print(n);
    // rsg.print(n);
    // cerr << '\n';

    auto bestL = [&](int t) {
        return lsg.query(0, t) + ll(n - 1 - t) * c;
    };

    auto bestR = [&](int t) {
        return rsg.query(t, n-1) + ll(t) * c;
    };

    vector<ll> ans(n);
    for (int i = m - 1; i >= 0; --i) {
        auto [t, p] = a[i];
        // Happens in town t with price p
        auto old = ans[t];
        auto pos = max(bestL(t), bestR(t)) + p;
        if (pos > old) {
            ans[t] = pos;
            lsg.update(t, ans[t] - ll(n - 1 - t) * c);
            rsg.update(t, ans[t] - ll(t) * c);
        }

        // cerr << "After " << i << "th query: ";
        // for (auto x: ans) {
        //     cerr << x << ' ';
        // }
        // cerr << '\n';
    }

    for (int i = 0; i < n; ++i) {
        ans[i] -= ll(c) * i;
    }

    // cerr << "Final answer: ";
    // for (auto x: ans) {
    //     cerr << x << ' ';
    // }
    // cerr << '\n';

    cout << *max_element(ans.begin(), ans.end()) << '\n';

    return 0;
}
