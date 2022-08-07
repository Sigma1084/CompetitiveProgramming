#include <bits/stdc++.h>
using namespace std;

#define ll long long int

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<pair<int, int>>> e(n+1, vector<pair<int, int>>());
    vector<ll> distance(n+1, -1);
    distance[0] = 0;

    for (int i=0; i<m; i++) {
        int a, b, c; cin >> a >> b >> c;
        e[a].push_back({b, c});
    }

    typedef pair<ll, pair<int, int>> trip;

    /**
     * @brief Stores the attached Edges to the current tree
     * 
     * First Value is the Distance of the edge from head
     * Second pair contains u, v indicating edge from u to v
     */
    priority_queue<trip,  vector<trip>, greater<trip>> vs;
    vs.push({0, {0, 1}});

    while (!vs.empty()) {
        auto i = vs.top(); vs.pop();
        ll d = i.first;
        int u = i.second.first, v = i.second.second;
        if (distance[v] != -1) continue;
        distance[v] = d;
        for (auto &winfo: e[v]) {
            int w = winfo.first, dvw = winfo.second;
            if (distance[w] == -1)
                vs.push({distance[v] + dvw, {v, w}});
        }
    }

    for (int i=1; i<=n; i++) cout << distance[i] << ' ';
    cout << '\n';
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int t = 1;
    // cin >> t;

    for (int i=1; i<=t; i++) {
        // cout << "Case #" << i << ": ";
        solve(); cout << '\n';
    }

    return 0;
}
