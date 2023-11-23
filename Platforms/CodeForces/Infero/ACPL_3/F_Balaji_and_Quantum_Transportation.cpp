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

    SparseTable(const auto &a, Merger merge) { build(a, merge); }

    void build(const auto &a, Merger _merge) {
        merge = _merge;
        K = std::__lg(a.size());

        st.resize(K + 1);
        int n = static_cast<int>(a.size());
        st[0].resize(n);
        std::copy(a.begin(), a.end(), st[0].begin());

        for (int i = 1; i <= K; i++) {
            st[i].resize(n - (1 << i) + 1);
            for (int j = 0; j < n - (1 << i) + 1; j++) {
                st[i][j] = merge(
                    st[i - 1][j],
                    st[i - 1][j + (1 << (i - 1))]
                );
            }
        }
    }

    constexpr std::vector<std::vector<T>>& operator () () const {
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

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n - 1);
    for (auto &x: a) {
        cin >> x;
        --x;
    }
    a.push_back(n - 1);

    SparseTable<int> st(ranges::iota_view(0, n), [&](int i, int j) {
        return a[i] >= a[j] ? i : j;
    });

    /**
     * dp[i] := Sum of m_ij for all j > i
     * In [i+1, a_i], look for the maximum r
     */
    vector<ll> dp(n);
    int r = 0;
    for (int i = n - 2; i >= 0; --i) {
        // You should look for the index in [i+1, a_i]
        // with the maximum a_j
        int j = st.query(i + 1, a[i]);

        // Go from i to j
        dp[i] += (j - i);

        // Go from j to n - 1
        dp[i] += dp[j] + (n - 1 - a[i]);
    }

    ll ans = accumulate(dp.begin(), dp.end(), 0LL);
    cout << ans << '\n';

    return 0;
}
