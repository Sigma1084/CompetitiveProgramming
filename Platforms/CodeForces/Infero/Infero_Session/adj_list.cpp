#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;  // Number of vertices
    cin >> n >> m;

    // Adjacency List
    vector<vector<int>> adj(n+1);

    /**
     * Just means that adj[i] is 
     * the list of all neighbours of vertex i
     */

    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int i = 0;
    for (auto &u: adj) {
        cout << "Vertex: " << i << ": ";
        for (auto &v: u) {
            cout << v << ' ';
        }
        cout << '\n';
        i++;
    }
}
