#pragma once

#include <cassert>
#include <cmath>
#include <functional>
#include <numeric>
#include <vector>

template<typename T>
class SparseTable {
public:
    using Index = unsigned int;
    using Merger = std::function<T(T, T)>;

    // A few examples of merge functions can be passed to the constructor
    static T min (T a, T b) { return std::min(a, b); }
    static T max (T a, T b) { return std::max(a, b); }
    static T gcd (T a, T b) { return std::gcd(a, b); }
    static T lcm (T a, T b) { return std::lcm(a, b); }
    static T bitAnd (T a, T b) { return a & b; }
    static T bitOr (T a, T b) { return a | b; }

private:
    Index K = 0;
    std::vector<std::vector<T>> st;
    Merger f;

public:
    SparseTable() = default;
    SparseTable(const SparseTable<T> &st) = default;
    template<class V>
    SparseTable(const std::vector<V> &a, Merger merge) { build(a, merge); }

    template<class V>
    void build(const std::vector<V> &a, Merger _merge) {
        f = _merge;
        K = std::__lg(a.size());

        st.resize(K + 1);
        std::size_t n = a.size();
        st[0].resize(n);
        std::copy(a.begin(), a.end(), st[0].begin());

        for (Index i = 1; i <= K; i++) {
            st[i].resize(n - (1<<i) + 1);
            for (Index j = 0; j <= n - (1 << i); ++j) {
                st[i][j] = f(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
            }
        }
    }

    const std::vector<std::vector<T>> &operator()() const {
        return st;
    }

    T query(Index l, Index r) const {
        assert(l <= r);
        int k = std::__lg(r - l + 1);
        return f(st[k][l], st[k][r - (1 << k) + 1]);
    }
};
