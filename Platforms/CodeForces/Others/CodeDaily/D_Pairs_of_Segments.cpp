#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template<typename T>
class SparseTable {
public:
    using Merger = std::function<T(const T&, const T&)>;

    // A few examples of merge functions can be passed to the constructor
    constexpr static T min (const T &a, const T &b) { return std::min(a, b); }
    constexpr static T max (const T &a, const T &b) { return std::max(a, b); }
    constexpr static T gcd (const T &a, const T &b) { return std::gcd(a, b); }
    constexpr static T lcm (const T &a, const T &b) { return std::lcm(a, b); }
    constexpr static T bitAnd (const T &a, const T &b) { return a & b; }
    constexpr static T bitOr (const T &a, const T &b) { return a | b; }

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
    int n; cin >> n;
    vector<array<int, 2>> a(n);
    for (auto &[l, r]: a) {
        cin >> l >> r;
    }

    constexpr int A = 1e9 + 7;
    a.push_back({A, A});
    sort(a.begin(), a.end());

    using STNode = array<int, 2>;
    vector<STNode> ends(n);
    for (int i = 0; i < n; ++i) {
        ends[i] = {a[i][1], i};
    } 
    SparseTable<STNode> st(ends, SparseTable<STNode>::min);

    vector<int> dp(n + 1);
    for (int i = n - 2; i >= 0; --i) {
        // Answer without taking this segment
        dp[i] = dp[i + 1];

        // Find j such that s[j] > e[i]
        int j = lower_bound(a.begin(), a.end(), array{a[i][1] + 1, 0}) - a.begin();
        if (j == i + 1) {
            // We can not take this segment
            continue;
        }

        // Find the segment in [i + 1, j - 1] with minimum r
        int k = st.query(i + 1, j - 1)[1];

        // Find the least index greater than e[k] and e[i]
        auto temp = array{max(a[k][1], a[i][1]) + 1, 0};
        int l = lower_bound(a.begin(), a.end(), temp) - a.begin();
        dp[i] = max(dp[i], 1 + dp[l]);
    }

    cout << n - 2 * dp[0];
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

    return 0;
}
