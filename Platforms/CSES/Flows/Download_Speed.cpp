#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template <typename FlowType = int>
class FlowGraph {
public:
    using Index = unsigned int;
    using VertIndex = Index;
    using EdgeIndex = Index;

    static constexpr FlowType FLOW_MAX = std::numeric_limits<FlowType>::max() / 2;

    struct Edge {
        VertIndex u, v;
        FlowType capacity, flow;

        Edge(VertIndex u, VertIndex v, FlowType capacity)
        : u(u), v(v), capacity(capacity), flow(0) {}

        FlowType remCap() const {
            return capacity - flow;
        }
    };

    const VertIndex numVertices, source, sink;

protected:
    std::vector<std::vector<std::pair<VertIndex, EdgeIndex>>> adj;
    std::vector<Edge> edges;

    void augmentEdge(EdgeIndex edgeIndex, FlowType flow) {
        edges[edgeIndex].flow += flow;
        edges[edgeIndex ^ 1].flow -= flow;
    }

public:
    FlowGraph() = default;

    FlowGraph(VertIndex numVertices, VertIndex source,
            VertIndex sink, EdgeIndex expectedNumEdges = 0)
        : numVertices(numVertices), source(source), sink(sink) {
        adj.resize(numVertices);
        edges.reserve(2 * expectedNumEdges);
    }

    void addEdge(VertIndex u, VertIndex v, FlowType capacity) {
        if (u >= numVertices || v >= numVertices) {
            throw std::out_of_range("Vertex index out of range");
        }
        adj[u].emplace_back(v, edges.size());
        edges.emplace_back(u, v, capacity);
        adj[v].emplace_back(u, edges.size());
        edges.emplace_back(v, u, 0);
    }

    const auto& getAdj() const { return adj; }
    const auto& getEdges() const { return edges; }

    virtual FlowType maxFlow() = 0;
};

template <typename FlowType = int>
class DinicFlowGraph : public FlowGraph<FlowType> {
    using Base = FlowGraph<FlowType>;
    using Base::Base;  // Inherit constructors

    using typename Base::Index;
    using typename Base::VertIndex;
    using Base::FLOW_MAX;

    std::vector<int> level;
    std::vector<Index> next;

    bool computeLevel() {
        level.assign(this->numVertices, -1);
        level[this->source] = 0;
        std::queue<VertIndex> q{{this->source}};
        while (!q.empty()) {
            auto u = q.front();
            q.pop();
            for (const auto &[v, edgeIndex] : this->adj[u]) {
                if (level[v] == -1 and this->edges[edgeIndex].remCap() > 0) {
                    level[v] = level[u] + 1;
                    q.push(v);
                }
            }
        }
        return level[this->sink] != -1;
    }

    FlowType computePath(VertIndex u, FlowType flow = FLOW_MAX) {
        if (u == this->sink) {
            return flow;
        }
        for (; next[u] < this->adj[u].size(); ++next[u]) {
            const auto [v, edgeIndex] = this->adj[u][next[u]];
            auto &edge = this->edges[edgeIndex];
            if (level[v] == level[u] + 1 && edge.remCap() > 0) {
                if (auto curFlow = computePath(v, std::min(flow, edge.remCap()))) {
                    this->augmentEdge(edgeIndex, curFlow);
                    return curFlow;
                }
            }
        }
        return 0;
    }

public:
    FlowType maxFlow() override {
        FlowType flow = 0;
        while (computeLevel()) {
            next.assign(this->numVertices, 0);
            while (auto curFlow = computePath(this->source)) {
                flow += curFlow;
            }
        }
        return flow;
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    DinicFlowGraph<ll> graph(n, 0, n - 1);
    for (int i = 0; i < m; ++i) {
        int u, v, c;
        std::cin >> u >> v >> c;
        graph.addEdge(u - 1, v - 1, c);
    }

    std::cout << graph.maxFlow() << '\n';

    return 0;
}