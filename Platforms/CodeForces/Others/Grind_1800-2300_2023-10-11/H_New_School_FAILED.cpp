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
    int K = 0;
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
        if (l < 0 or r > static_cast<int>(st[0].size()) - 1) {
            throw std::out_of_range("l and r must be in [0, n-1]");
        } else if (l > r) {
            throw std::invalid_argument("l must be <= r");
        } else {
            int k = std::__lg(r - l + 1);
            return merge(st[k][l], st[k][r - (1 << k) + 1]);
        }
    }
};

struct Fraction: std::pair<ll, int> {
    Fraction() = default;

    bool operator < (const Fraction &other) const {
        return first * other.second < other.first * second;
    }

    bool operator <= (const Fraction &other) const {
        return first * other.second <= other.first * second;
    }

    template<typename T>
    bool operator < (T other) const {
        return first < other * second;
    }

    template<typename T>
    bool operator <= (T other) const {
        return first <= other * second;
    }

    [[nodiscard]] double toDouble() const {
        return static_cast<double>(first) / second;
    }
};


void solve() {
    int nT, nG, nS = 0;
    cin >> nT >> nG;

    vector<int> a(nT);
    for (auto &x: a) {
        cin >> x;
    }
    sort(a.begin(), a.end(), greater<>());
    a.resize(nG);  // Consider only the best nG teachers
    reverse(a.begin(), a.end());  // Ascending order

    vector<Fraction> avgs(nG);
    vector<vector<array<int, 2>>> b(nG);
    for (int i = 0, j = 0; i < nG; ++i) {
        auto &[num, den] = avgs[i];
        cin >> den;
        b[i].resize(den);
        nS += den;
        for (auto &[x, ind]: b[i]) {
            cin >> x;
            ind = j++;
            num += x;
        }
    }

    // Sort groups in ascending order of average age
    vector<int> ord(nG);
    auto comp = [&](int i, int j) -> bool {
        return avgs[i] < avgs[j];
    };
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), comp);
    sort(avgs.begin(), avgs.end());

    /**
     * We now refer to the groups by b[ord[i]]
     * We can however refer to the average of b[ord[i]] as avgs[i]
     */

    vector<bool> isFine(nG);
    vector<bool> isGreaterFine(nG);
    vector<bool> isLesserFine(nG);

    for (int i = 0; i < nG; ++i) {
        isFine[i] = avgs[i] <= a[i];
        if (i + 1 < nG) {
            isGreaterFine[i] = avgs[i] <= a[i+1];
        }
        if (i - 1 >= 0) {
            isLesserFine[i] = avgs[i] <= a[i-1];
        }
    }

    SparseTable<bool>::Merger merger = SparseTable<bool>::bitAnd;
    SparseTable<bool> isFineST(isFine, merger);
    SparseTable<bool> isGreaterFineST(isGreaterFine, merger);
    SparseTable<bool> isLesserFineST(isLesserFine, merger);

    vector<int> isPos(nS, 1);

    Fraction newAvg;  // Query
    auto &[newSum, newSize] = newAvg;
    for (int i = 0, j; i < nG; ++i) {
        newAvg = avgs[i];
        newSize--;
        for (auto [x, ind]: b[ord[i]]) {
            newSum -= x;
            int &ans = isPos[ind];
            // Here, we need to see where newAvg fits in the sorted array
            auto lb = lower_bound(avgs.begin(), avgs.end(), newAvg);
            j = static_cast<int>(lb - avgs.begin());
            if (j > i) --j;  // Since we will be deleting the current element

            if (min(i - 1, j - 1) >= 0) {
                ans &= isFineST.query(0, min(i - 1, j - 1));
            }
            if (max(i + 1, j + 1) < nG) {
                ans &= isFineST.query(max(i + 1, j + 1), nG - 1);
            }
            ans &= newAvg <= a[j];

            if (j < i) {
                ans &= isGreaterFineST.query(j, i - 1);
            } else if (i < j) {
                ans &= isLesserFineST.query(i + 1, j);
            }

            newSum += x;
        }
    }

    for (auto x: isPos) {
        cout << x;
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

    return 0;
}
