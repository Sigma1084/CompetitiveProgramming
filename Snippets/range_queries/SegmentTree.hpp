#pragma once

#include <cstddef>
#include <vector>
#include <cassert>
#include <functional>
#include <numeric>

template<typename T>
class SegTree {
public:
    using Index = unsigned int;

private:
    std::size_t n;
    std::vector<T> s;

    using Merger = std::function<T(T a, T b)>;
    Merger f;
    const T ID;

public:
    static T min (T a, T b) { return std::min(a, b); }
    static T max (T a, T b) { return std::max(a, b); }
    static T gcd (T a, T b) { return std::gcd(a, b); }
    static T lcm (T a, T b) { return std::lcm(a, b); }
    static T bitAnd (T a, T b) { return a & b; }
    static T bitOr (T a, T b) { return a | b; }

    SegTree(std::size_t sz, Merger f, T ID): f(f), ID(ID) {
        n = 1 << std::__lg(2 * sz - 1);
        s.resize(2 * n, ID);
    }

    template<typename U>
    SegTree(const std::vector<U> &a, Merger f, T ID): SegTree(a.size(), f, ID) {
        std::copy(a.begin(), a.end(), s.begin() + n);
        for (Index i = n - 1; i > 0; --i)
            s[i] = f(s[i * 2], s[i * 2 + 1]);
    }

    void update(Index i, T val) {
        for (s[i += n] = val; i /= 2; )
            s[i] = f(s[i * 2], s[i * 2 + 1]);
    }

    T query(Index l, Index r) {
        assert(l <= r);
        T rL = ID, rR = ID;
        for (l += n, r += n; l <= r; l /= 2, r /= 2) {
            if (l % 2 == 1) rL = f(rL, s[l++]);
            if (r % 2 == 0) rR = f(s[r--], rR);
        }
        return f(rL, rR);
    }

    T operator[](Index i) {
        assert(i < n);
        return s[i + n];
    }
};
