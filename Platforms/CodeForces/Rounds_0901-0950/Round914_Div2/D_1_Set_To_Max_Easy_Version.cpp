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

    vector<int> a(n), b(n);
    for (auto &x: a) {
        cin >> x;
        --x;
    }
    for (auto &x: b) {
        cin >> x;
        --x;
    }

    SparseTable<int> st(a, SparseTable<int>::max);

    vector<vector<int>> ap(n);
    for (int i = 0; i < n; ++i) {
        ap[a[i]].push_back(i);
    }
    vector<vector<int>> bp(n);
    for (int i = 0; i < n; ++i) {
        bp[b[i]].push_back(i);
    }

    set<pair<int, int>> ranges;
    ranges.emplace(0, n - 1);
    for (int x = 0; x < n; ++x) {
        for (int i: bp[x]) {
            // Identify the range of a[i]
            auto it = ranges.lower_bound({i + 1, 0});
            --it;
            auto [l, r] = *it;

            // Identify the nearest pos in a
            auto it2 = lower_bound(ap[x].begin(), ap[x].end(), i);
            if (it2 != ap[x].end() and *it2 <= r and st.query(i, *it2) == x) {
                continue;
            }
            if (it2 == ap[x].begin()) {
                cout << "NO";
                return;
            }
            --it2;
            if (*it2 >= l and st.query(*it2, i) == x) {
                continue;
            } else {
                cout << "NO";
                return;
            }
        }
        // Update the ranges
        for (int i: bp[x]) {
            auto it = --ranges.lower_bound({i + 1, 0});
            auto [l, r] = *it;
            ranges.erase(it);
            if (l <= i - 1) {
                ranges.emplace(l, i - 1);
            }
            if (i + 1 <= r) {
                ranges.emplace(i + 1, r);
            }
        }
    }

    assert(ranges.empty());

    cout << "YES";
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
