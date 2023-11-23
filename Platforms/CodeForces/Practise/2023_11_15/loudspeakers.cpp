#include <bits/stdc++.h>
using namespace std;

class DSU {
    const int n; // Number of nodes
    int nC; // Number of components
    std::vector<int> p;  // Parent
    std::vector<int> sz;  // Size of the component
public:
    DSU(int n): n(n), nC(n) { p.resize(n, -1); sz.resize(n, 1); }
    bool isLeader(int u) const { return p[u] < 0; }
    int size(int u) { return sz[find(u)]; }
    int numComp() const { return nC; }

    int find(int u) {
        if (isLeader(u)) return u;
        return p[u] = find(p[u]);
    }

    bool merge(int u, int v) {
        u = find(u); v = find(v);
        if (u == v) return false;
        if (sz[u] < sz[v]) std::swap(u, v);
        p[v] = u; nC--;
        sz[u] += sz[v]; sz[v] = 0;
        return true;
    }
};

/**
 * Loudspeaker: <br>
 *
 * We have A cities and B roads connecting them.
 *
 * There are C cities which have loudspeakers.
 * A loudspeaker's voice can propagate through a road.
 */

int solve(int A, const vector<array<int, 2>> &B, const vector<int> &C,
          int S, int D) {
    // Convert the edge list to adjacency list and use 0-based indexing

    int n = A;  // Total number of nodes
    vector<vector<int>> adj(A + B.size());

    // Insert the roads by iterating the edge list
    for (auto [u, v]: B) {
        // Make a new node between cities u and v
        --u; --v;  // Convert to 0-based indexing

        // Insert a new node between u and v, say n

        // Insert (u, n)
        adj[u].push_back(n);
        adj[n].push_back(u);

        // Insert (v, n)
        adj[v].push_back(n);
        adj[n].push_back(v);

        // Update n (total number of nodes)
        ++n;
    }

    // Convert the loudspeaker list to 0-based indexing
    vector<bool> is_loudspeaker(n);
    for (auto c: C) {
        --c;  // Convert to 0-based indexing
        is_loudspeaker[c] = true;  // Mark the city as a loudspeaker
    }
    --S; --D;  // Convert to 0-based indexing
    is_loudspeaker[S] = true;
    is_loudspeaker[D] = true;

    // Initially, all nodes are in different components
    DSU dsu(n);

    // Initially, all the cities with loudspeakers are the outer layer
    int d = 0;
    vector<int> out;
    vector<bool> vis(n, false);
    for (int u = 0; u < n; ++u) {
        if (is_loudspeaker[u]) {
            out.push_back(u);
        }
    }

    while (dsu.find(S) != dsu.find(D) and not out.empty()) {
        // Propagate the loudspeaker's voice
        vector<int> q2;

        // Iterate over all the nodes in the outer layer
        for (auto u: out) {
            // Mark the node as visited
            vis[u] = true;

            // All nodes connected to the outer layer
            for (auto v: adj[u]) {
                if (not vis[v]) {
                    q2.push_back(v);  // Next layer
                    dsu.merge(u, v);  // Merge the components
                }
            }
        }

        // Update the outer layer
        out = q2;

        // Update the distance
        ++d;
    }

    // Case when the destination is not reachable from the source
    if (dsu.find(S) != dsu.find(D)) {
        return -1;
    }

    return d;
}

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output_sol.txt", "w", stdout);

    int A = 6;
    vector<array<int, 2>> B = {{1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 6}};
    vector<int> C = {1, 3};
    int S = 1, D = 6;

    auto ans = solve(A, B, C, S, D);
    assert(ans == 3);

    return 0;
}
