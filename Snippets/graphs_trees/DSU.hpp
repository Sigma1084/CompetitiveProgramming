#pragma once

#include <utility>
#include <vector>

class DSU {
public:
    using Node = unsigned int;
    using Size = unsigned int;

private:
    const Size n; // Number of nodes
    Size nC; // Number of components
    std::vector<Node> p;  // Parent
    std::vector<Size> sz;  // Size of the component

public:
    DSU(Size n): n(n), nC(n), p(n, n), sz(n, 1) {}
    bool isLeader(Node u) const { return p[u] == n; }
    Size size(Node u) { return sz[leader(u)]; }
    Size numComp() const { return nC; }

    Node leader(Node u) {
        if (isLeader(u)) return u;
        return p[u] = leader(p[u]);
    }

    bool merge(Node u, Node v) {
        u = leader(u); v = leader(v);
        if (u == v) return false;
        if (sz[u] < sz[v]) std::swap(u, v);
        p[v] = u; nC--;
        sz[u] += sz[v]; sz[v] = 0;
        return true;
    }
};
