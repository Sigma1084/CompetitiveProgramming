#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

template <typename T, class Compare = less<>>
using OSet = tree<
    T, null_type, Compare, rb_tree_tag,
    tree_order_statistics_node_update
>;

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
        K = std::log2(a.size());

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

    vector<array<int, 2>> inp(n);
    for (auto &[p, h]: inp) {
        cin >> p >> h;
        --p;
    }

    OSet<int> av;
    for (int i = 0; i < n; ++i) {
        av.insert(i);
    }
    vector<array<int, 2>> a(n);
    for (int i = n - 1; i >= 0; --i) {
        a[i][1] = -i;
        auto [p, h] = inp[i];
        auto i1 = *av.find_by_order(p);
        av.erase(i1);
        a[i1][0] = h;
    }

    SparseTable<array<int, 2>> st(a, SparseTable<array<int, 2>>::min);
    vector<array<int, 2>> ans;
    ans.reserve(n);

    function<void(int, int)> f = [&](int l, int r) {
        if (l > r) return;
        auto [ai, i] = st.query(l, r);
        i = -i;
        ans.push_back({l + 1, ai});
        f(l, i - 1);
        f(i + 1, r);
    };
    f(0, n - 1);

    for (auto [x, y]: ans) {
        cout << x << ' ' << y << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    while (t--) {
        solve();
        cout << '\n';
    }
}