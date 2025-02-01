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

    void augmentEdge(EdgeIndex edgeIndex, FlowType flow) {
        edges[edgeIndex].flow += flow;
        edges[edgeIndex ^ 1].flow -= flow;
    }

    const VertIndex numVertices, source, sink;

protected:
    std::vector<std::vector<std::pair<VertIndex, EdgeIndex>>> adj;
    std::vector<Edge> edges;

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

    int n1, n2, m;
    cin >> n1 >> n2 >> m;

    DinicFlowGraph<int> graph(n1 + n2 + 2, 0, n1 + n2 + 1, n1 + n2 + m);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        graph.addEdge(u + 1, n1 + v + 1, 1);
    }
    for (int i = 1; i <= n1; ++i) {
        graph.addEdge(0, i, 1);
    }
    for (int i = 1; i <= n2; ++i) {
        graph.addEdge(n1 + i, n1 + n2 + 1, 1);
    }

    auto s = graph.source, t = graph.sink;
    auto &adj = graph.getAdj();
    auto &edges = graph.getEdges();

    vector<int> path;
    function<void(int)> dfs = [&](FlowGraph<int>::VertIndex u) {
        path.push_back(u);
        if (u == t) return;
        for (const auto &[v, edgeIndex] : adj[u]) {
            if (!(edgeIndex & 1) and edges[edgeIndex].flow) {
                graph.augmentEdge(edgeIndex, -1);
                return dfs(v);
            }
        }
    };

    auto maxFlow = graph.maxFlow();
    cout << maxFlow << '\n';

    for (int i = 0; i < maxFlow; ++i) {
        path.clear();
        dfs(s);
        cout << path[1] - 1 << ' ' << path[2] - n1 - 1 << '\n';
    }

    return 0;
}