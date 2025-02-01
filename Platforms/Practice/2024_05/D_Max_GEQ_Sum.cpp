#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template<typename T>
class SparseTable {
public:
    using Merger = std::function<T(const T&, const T&)>;

    // A few examples of merge functions can be passed to the constructor
    static T min (const T &a, const T &b) { return std::min(a, b); }
    static T max (const T &a, const T &b) { return std::max(a, b); }
    static T gcd (const T &a, const T &b) { return std::gcd(a, b); }
    static T lcm (const T &a, const T &b) { return std::lcm(a, b); }
    static T bitAnd (const T &a, const T &b) { return a & b; }
    static T bitOr (const T &a, const T &b) { return a | b; }

private:
    int K;
    std::vector<std::vector<T>> st;
    Merger merge;

    T query(int l, int r, int k) {
        return merge(st[k][l], st[k][r - (1 << k) + 1]);
    }

public:
    SparseTable() = default;
    SparseTable(const SparseTable<T> &st) = default;
    template<class V>
    SparseTable(const std::vector<V> &a, Merger merge) { build(a, merge); }

    template<class V>
    void build(const std::vector<V> &a, Merger _merge) {
        merge = _merge;
        K = std::__lg(a.size());

        st.resize(K + 1);
        std::size_t n = a.size();
        st[0].resize(n);
        std::copy(a.begin(), a.end(), st[0].begin());

        for (int i = 1; i <= K; i++) {
            st[i].resize(n - (1 << i) + 1);
            for (int j = 0; j < static_cast<int>(n - (1 << i) + 1); j++) {
                st[i][j] = merge(
                    st[i - 1][j],
                    st[i - 1][j + (1 << (i - 1))]
                );
            }
        }
    }

    const std::vector<std::vector<T>>& operator () () const {
        return st;
    }

    T query(int l, int r) {
        if (l > r) {
            throw std::invalid_argument("l must be <= r");
        } else {
            int k = std::log2(r - l + 1);
            return merge(st[k][l], st[k][r - (1 << k) + 1]);
        }
    }
};

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (auto &x: a) {
        cin >> x;
    }

    vector<array<int, 2>> b(n);
    for (int i = 0; i < n; ++i) {
        b[i] = {a[i], i};
    }

    vector<ll> p(n + 1);
    for (int i = 0; i < n; ++i) {
        p[i+1] = p[i] + a[i];
    }

    vector<ll> pL(n), pH(n);
    copy(p.begin(), p.end() - 1, pL.begin());
    copy(p.begin() + 1, p.end(), pH.begin());

    // We need to have a Segment tree that gives maximum value and index
    SparseTable<ll> pLS(pL, SparseTable<ll>::min), pHS(pH, SparseTable<ll>::max);
    SparseTable<array<int, 2>> aS(b, SparseTable<array<int, 2>>::max);

    function<bool(int, int)> check = [&](int l, int r) {
        if (l >= r) return true;
        auto [x, m] = aS.query(l, r);
        if (ll(x) >= pHS.query(m, r) - pLS.query(l, m)) {
            return check(l, m - 1) and check(m + 1, r);
        } else {
            return false;
        }
    };

    cout << (check(0, n - 1) ? "YES" : "NO");
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
