#include<bits/stdc++.h>
using namespace std;

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

int main() {
	int n = 6;
	vector<vector<int>> edges = {{0, 1}, {0, 2}, {2, 3}, {2, 4}, {2, 5}};
	Solution s;
	for (int i: s.sumOfDistancesInTree(n, edges)) {
		cout << i << ' ';
	}
	cout << endl;
	return 0;
}
