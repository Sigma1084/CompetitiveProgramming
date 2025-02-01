#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
    }
    for (auto &gu: g) {
        sort(gu.begin(), gu.end());
    }

    vector<int> d(n, -1);
    d[0] = 0;
    queue<int> q{ {0} };
    while (not q.empty()) {
        int u = q.front();
        q.pop();
        for (int v: g[u]) {
            if (v == 0) {
                cout << d[u] + 1;
                return 0;
            }
            if (d[v] == -1) {
                d[v] = d[u] + 1;
                q.push(v);
            }
        }
    }

    cout << -1;
    return 0;
}
