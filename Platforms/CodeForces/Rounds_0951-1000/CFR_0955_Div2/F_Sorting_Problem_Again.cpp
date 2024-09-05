#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template<typename T>
class SegTree {
    unsigned int n;
    std::vector<T> s;

    using Merger = std::function<T(const T&, const T&)>;
    Merger f;
    const T ID;

public:
    SegTree(unsigned int sz, Merger f, T ID): f(f), ID(ID) {
        n = 1 << std::__lg(2 * sz - 1);
        s.resize(2 * n, ID);
    }

    static T min (const T &a, const T &b) { return std::min(a, b); }
    static T max (const T &a, const T &b) { return std::max(a, b); }
    static T gcd (const T &a, const T &b) { return std::gcd(a, b); }
    static T lcm (const T &a, const T &b) { return std::lcm(a, b); }
    static T bitAnd (const T &a, const T &b) { return a & b; }
    static T bitOr (const T &a, const T &b) { return a | b; }

    template<typename U>
    SegTree(const std::vector<U> &a, Merger f, T ID):
        SegTree(a.size(), f, ID) {
        std::copy(a.begin(), a.end(), s.begin() + n);
        for (auto i = n - 1; i > 0; --i)
            s[i] = f(s[i*2], s[i*2 + 1]);
    }

    void update(unsigned idx, T val) {
        for (s[idx += n] = val; idx >>= 1; )
            s[idx] = f(s[idx << 1], s[(idx << 1) + 1]);
    }

    T query(unsigned l, unsigned r) const {
        assert(l <= r);
        T rL = ID, rR = ID;
        for (l += n, r += n; l <= r; l /= 2, r /= 2) {
            if (l % 2 == 1) rL = f(rL, s[l++]);
            if (r % 2 == 0) rR = f(s[r--], rR);
        }
        return f(rL, rR);
    }

    T operator[](unsigned idx) const {
        assert(idx < n);
        return s[idx + n];
    }
};

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (auto &x: a) {
        cin >> x;
    }

    int nQ;
    cin >> nQ;

    SegTree<int> smx(a, SegTree<int>::max, INT_MIN);
    SegTree<int> smn(a, SegTree<int>::min, INT_MAX);
    set<int> badInds;  // Set of all i such that a[i] > a[i+1]
    for (int i = 0; i + 1 < n; ++i) {
        if (a[i] > a[i + 1]) {
            badInds.insert(i);
        }
    }

    auto f = [&]() {
        if (badInds.empty()) {
            cout << "-1 -1\n";
            return;
        }
        int l = *badInds.begin(), r = *badInds.rbegin() + 1;
        int mn = smn.query(l, r), mx = smx.query(l, r);
        l = upper_bound(a.begin(), a.begin() + l, mn) - a.begin();
        r = lower_bound(a.begin() + r + 1, a.end(), mx) - a.begin() - 1;
        cout << l + 1 << ' ' << r + 1 << '\n';
    };

    f();
    while(nQ--) {
        int i, x;
        cin >> i >> x;
        --i;

        a[i] = x;
        smx.update(i, x);
        smn.update(i, x);
        badInds.erase(i - 1);
        badInds.erase(i);
        if (i - 1 >= 0 and a[i-1] > a[i]) {
            badInds.insert(i - 1);
        }
        if (i + 1 < n and a[i] > a[i + 1]) {
            badInds.insert(i);
        }
        f();
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
