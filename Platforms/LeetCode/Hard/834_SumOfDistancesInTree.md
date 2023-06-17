# Approach
Let us first define a few variables.

`par[u]` := Parent of u assuming root is 0
`siz[u]` := Size of the subtree from u
`from[u]` := Total steps from node u to cover _only_ the subtree below it
`ans[u]` := The final answer for node u

Use Depth-First Search to initially compute `par`, `siz` and `from`.

Let us assume that we know the answers to all the nodes above the current node in the rooted tree.

Consider some node `u`. We will try to find `ans[u]`.
The contribution of the nodes below can be given by `from[u]` by definition of `from`.

Subtracting `from[u] + siz[u]` from `ans[par[u]]` will get rid of the contribution of the current subtree from it's parent.
Now, we add the _size of the remaining tree_, given by `n - siz[u]` since we need to travel 1 more time than it's parent to the remaining nodes.

Hence, the final answer for a node would be
`ans[u] = from[u] + ans[par[u]] - (from[u] + siz[u]) + n - siz[u]`
which on simplification yields
`ans[u] = ans[par[u]] + n - 2 * siz[u]`.

Notice that this can not be applied for `u = 0` and we will handle this separately by setting `ans[0] = from[0]`.


# Complexity
- Time complexity: $$O(n)$$

- Space complexity:  $$O(n)$$


# Code
```
class Solution {
    int n;
    vector<vector<int>> adj;
    vector<int> par;
    vector<int> siz;
    vector<int> from;
    vector<int> ans;

    void dfsPre(int u) {
        for (int v: adj[u]) {
            if (v == par[u]) continue;
            par[v] = u;
            dfsPre(v);
            siz[u] += siz[v];
            from[u] += from[v] + siz[v];
        }
    }

    void dfsAns(int u) {
        if (u) {
            ans[u] = ans[par[u]] + n - 2 * siz[u];
        } else {
            ans[0] = from[0];
        }
        for (int v: adj[u]) {
            if (v == par[u]) continue;
            dfsAns(v);
        }
    }

public:
    vector<int> sumOfDistancesInTree(int n, 
                const vector<vector<int>>& edges) {
        this->n = n;
        adj.resize(n, vector<int>());
        par.resize(n, 0);
        siz.resize(n, 1);  // Size is initially 1
        from.resize(n, 0);
        ans.resize(n, 0);

        for (const auto &e: edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        dfsPre(0);
        dfsAns(0);

        return ans;
    }
};
```