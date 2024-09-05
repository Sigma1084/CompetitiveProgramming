#pragma once

#include <cstddef>
#include <vector>
#include <numeric>

template <typename T, typename U = T>
class LazySegTreeBase {
protected:
    using Index = unsigned int;
    using Node = unsigned int;

    const std::size_t n;
    std::vector<T> tree;
    std::vector<U> lazy;
    std::vector<Index> nL, nR;

    // The below functions to be implemented by the user
    virtual T merge(T t1, T t2) = 0;
    virtual U& mergeUpdate(U& update, U newUpdate) = 0;
    virtual void consume(Node node) = 0;

    [[nodiscard]] inline constexpr bool outside(Node node, Index l, Index r) const {
        return nR[node] < l or r < nL[node];
    }

    [[nodiscard]] inline constexpr bool inside(Node node, Index l, Index r) const {
        return l <= nL[node] and nR[node] <= r;
    }

    [[nodiscard]] inline constexpr bool isLeaf(Node node) const {
        return node >= n;
    }

    [[nodiscard]] inline constexpr std::size_t sizeOf(Node node) const {
        return nR[node] - nL[node] + 1;
    }

private:
    void push(Node node) {
        if (lazy[node] == lazy[0]) return;

        // Propagate the update to the children
        if (!isLeaf(node)) {
            mergeUpdate(lazy[node * 2], lazy[node]);
            mergeUpdate(lazy[node * 2 + 1], lazy[node]);
        }

        consume(node);
        lazy[node] = lazy[0];
    }

    void pull(Node node) {
        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    }

    T query(Node node, Index l, Index r) {
        push(node);

        if (outside(node, l, r)) return tree[0];
        if (inside(node, l, r)) return tree[node];

        return merge(query(node * 2, l, r), query(node * 2 + 1, l, r));
    }

    void update(Node node, Index l, Index r, U up) {
        // The fact that update is called means there will be a pull
        push(node);  // Have to push before updating

        if (outside(node, l, r)) return;  // node out of range

        if (inside(node, l, r)) {
            // Perfect overlap.
            lazy[node] = up;
            push(node);
        } else {
            // Partial overlap.
            update(node * 2, l, r, up);
            update(node * 2 + 1, l, r, up);
            pull(node);
        }
    }

public:
    explicit LazySegTreeBase(std::size_t sz, T idT = T(), U idU = U()):
            n(1 << std::__lg(2 * sz - 1)) {
        tree.resize(2 * n, idT);
        lazy.resize(2 * n, idU);
        nL.resize(2 * n);
        nR.resize(2 * n);

        std::iota(nL.begin() + n, nL.end(), 0);
        std::iota(nR.begin() + n, nR.end(), 0);

        for (Node u = n - 1; u > 0; u--) {
            nL[u] = nL[2 * u];
            nR[u] = nR[2 * u + 1];
        }
    };

    template<typename V>
    void assign(const std::vector<V> &v) {
        std::copy(v.begin(), v.end(), tree.begin() + n);
        for (Node u = n - 1; u > 0; --u) {
            tree[u] = merge(tree[u * 2], tree[u * 2 + 1]);
        }
    }

    T query(Index l, Index r) {
        return query(1, l, r);
    }

    void update(Index l, Index r, U up) {
        update(1, l, r, up);
    }
};

using T = long long;
using U = long long;
struct SegTree: LazySegTreeBase<T, U> {
    constexpr static T idElement = 0;
    constexpr static U idUpdate = 0;

    SegTree(std::size_t n): LazySegTreeBase<T, U>(n, idElement, idUpdate) {}

private:
    T merge(T t1, T t2) override {
        // This is the querying operation
        return t1 + t2;
    }

    U& mergeUpdate(U& update, U newUpdate) override {
        // This is the updating operation
        return update += newUpdate;
    }

    void consume(Node node) override {
        tree[node] = sizeOf(node) * lazy[node];
    }
};
