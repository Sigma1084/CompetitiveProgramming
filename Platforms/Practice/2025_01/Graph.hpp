#include <vector>
#include <utility>
#include <limits>

template <typename FlowType = int>
class FlowGraph {
public:
    using Index = unsigned int;
    using VertIndex = Index;
    using EdgeIndex = Index;

    static constexpr FLOW_MAX = std::numeric_limits<FlowType>::max() / 2;

    struct Edge {
        VertIndex u, v;
        FlowType capacity, flow;

        Edge(VertIndex u, VertIndex v, FlowType capacity) : u(u), v(v), capacity(capacity), flow(0) {}

        FlowType remainingCapacity() const {
            return capacity - flow;
        }
    };

protected:
    VertIndex numVertices, source, sink;
    std::vector<std::vector<std::pair<VertIndex, EdgeIndex>>> adj;
    std::vector<Edge> edges;

    void augmentEdge(EdgeIndex edgeIndex, FlowType flow) {
        edges[edgeIndex] += flow;
        edges[edgeIndex ^ 1] -= flow;
    }

public:
    FlowGraph() = default;

    FlowGraph(
        VertIndex numVert,
        VertIndex source = 0,
        VertIndex sink = numVert - 1,
        EdgeIndex exptectedNumEdges = 0
    ) : numVertices(numVertices), source(source), sink(sink)
    {
        adj.resize(numVertices);
        edges.reserve(2 * exptectedNumEdges);
    }

    void addEdge(VertIndex u, VertIndex v, FlowType capacity) {
        adj[u].emplace_back(v, edges.size());
        edges.emplace_back(u, v, capacity);
        adj[v].emplace_back(u, edges.size());
        edges.emplace_back(v, u, 0);
    }

    const auto& getAdj() { return adj; }

    virtual FlowType maxFlow() = 0;
};

template <typename FlowType = int>
class DinicFlowGraph : public FlowGraph<FlowType> {
    using FlowGraph<FlowType>::FlowGraph;  // Inherit constructors

    // Using declarations to bring types from FlowGraph into the scope of DinicFlowGraph
    using typename FlowGraph<FlowType>::Index;
    using typename FlowGraph<FlowType>::VertIndex;

    std::vector<int> level;
    std::vector<Index> next;

    bool computeLevel() {
        level.assign(this->numVertices, -1);
        level[this->source] = 0;
        std::queue<VertIndex> q{{this->source}};
        while (!q.empty()) {
            auto u = q.front();
            q.pop();
            for (const auto [v, edgeIndex] : this->adj[u]) {
                if (level[v] == -1 and this->edges[edgeIndex].remainingCapacity() > 0) {
                    level[v] = level[u] + 1;
                    q.push(v);
                }
            }
        }
        return level[this->sink] != -1;
    }

    FlowType computePath(VertIndex u = this->source, FlowType flow = FLOW_MAX) {
        if (u == this->sink) {
            return flow;
        }
        for (; next[u] < this->adj[u].size(); ++next[u]) {
            const auto [v, edgeIndex] = this->adj[u][next[u]];
            auto &edge = this->edges[edgeIndex];
            if (level[v] == level[u] + 1 && edge.remainingCapacity() > 0) {
                if (auto curFlow = computePath(v, std::min(flow, edge.remainingCapacity()))) {
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
            while (auto curFlow = computePath()) {
                flow += curFlow;
            }
        }
        return flow;
    }
};
