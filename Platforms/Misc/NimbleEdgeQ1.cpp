#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;


struct Solution {
    int n, m;
    vector<int> colors;
    vector<int> par;
    set<int> whites;
    set<int> comps;
    set<int> whiteComps;

    int Find(int i) {
        if (par[i] == i) return i;
        return par[i] = Find(par[i]);
    }

    void Union(int i, int j) {
        if (Find(i) == Find(j)) return;
        if (Find(i) == i and Find(j) == j) {
            // Both are disjoint and isolated
            par[i] = j;
            comps.insert(j);
            if (colors[i] or colors[j]) whiteComps.insert(j);
        } else if (Find(i) == i) {
            par[i] = j;
            if (colors[i]) whiteComps.insert(Find(i));
        } else if (Find(j) == j) {
            par[j] = i;
            if (colors[j]) whiteComps.insert(Find(j));
        } else {
            // Both have different components
            i = Find(i);
            j = Find(j);
            par[j] = i;
            comps.erase(j);
            whiteComps.erase(j);
        }
    }

    int findMinimum(vector<int> cols, vector<int> costs, 
        vector<int> u, vector<int> v) {
        
        colors = cols;
        
        n = colors.size();
        m = costs.size();
        par.resize(n + 1);
        for(int i = 0; i <= n; i++) par[i] = i;

        for (int i = 0; i < n; i++) if(colors[i] == 1) {
            whites.insert(i+1);
        }

        vector<tuple<int, int, int>> ed;
        for (int i = 0; i < m; i++) {
            ed.push_back({costs[i], u[i], v[i]});
        }
        sort(ed.begin(), ed.end());

        int ans = 0;

        for (auto &ii: ed) {
            if (whites.empty() and whiteComps.size() == 1) return ans;
            auto &[w, i, j] = ii;
            ans = w;
            whites.erase(i); whites.erase(j);
            Union(i, j);
        }
        return ans;
    }
};


int prim(vector<int> cols, vector<int> cost, 
    vector<int> us, vector<int> vs) {

    int n = cols.size();
    set<int> whites;

    // Insert Whites
    for (int i = 0; i < cols.size(); i++) 
        if (cols[i]) whites.insert(i+1);

    if (whites.empty()) {
        return *min_element(cost.begin(), cost.end());
    }

    // Construct Edges
    vector<vector<pair<int, int>>> e(n+1);
    for (int i = 0; i < cost.size(); i++) {
        e[us[i]].push_back({cost[i], vs[i]});
        e[vs[i]].push_back({cost[i], us[i]});
    }

    // Sorting all the edges
    for (auto &eu: e) sort(eu.begin(), eu.end());

    if (whites.size() == 1) {
        // Single White
        int u = *whites.begin();
        // Weight of the minimum edge connected to it
        return min_element(e[u].begin(), e[u].end())->first;
    }

    // Prims
    vector<bool> visited(n + 1);
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({0, *whites.begin()});

    int ans = 0;

    // We need to select all the whites
    while (!q.empty() and !whites.empty()) {
        // Use the popped element
        auto [w, u] = q.top(); q.pop();
        ans = max(ans, w);
        whites.erase(u);
        visited[u] = true;

        for (auto &[wN, v]: e[u]) {
            if (not visited[v]) q.push({wN, v});
        }
    }

    return ans;
}


int main() {
    Solution s;
    cout << s.findMinimum({1, 1, 1, 0}, {2, 3, 4, 5}, 
        {1, 1, 1, 2}, {2, 3, 4, 3}) << '\n';
}
