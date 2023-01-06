# Graph Algorithms

A graph is a non linear data structure with nodes and edges

```cpp
// Use 1 indexing

int n, m; // Number of vertices, edges
vector<vector<int>> e(n + 1);  // Edges

vector<vector<pair<int, int>> e(n + 1);  // Weighted Edges
```

### DFS (Depth First Search)

Simplest graph algorithm. 

```cpp
vector<int> p(n + 1, 0);  // DFS Tree
p[root] = root;  // Setting parent of root
void dfs(int u) {
	for (auto &v: e[u]) {
		if (v == p[u]) continue;
		p[v] = u;
		dfs(v);  // Recursion
	}
}
// Run dfs[root]

// constructing p is mostly sufficient for any basic DFS questions
```

### BFS (Breadth First Search)

Using a queue, traverse the graph once

```cpp
vector<int> p(n + 1, 0);  // BFS Tree
void bfs(int root) {
	// Starting from root, perform bfs (usually 1)
	queue<int> q = { root };
	p[root] = root;
	while (not q.empty()) {
		int u = q.top(); q.pop();
		for (auto &v: e[u]) {
			if (p[v]) continue;
			p[v] = u;
			q.push_back(v);
		}
	}
}
```

## Minimum Spanning Tree (For Weighted Graphs)

### Dijkstra's Algorithm
