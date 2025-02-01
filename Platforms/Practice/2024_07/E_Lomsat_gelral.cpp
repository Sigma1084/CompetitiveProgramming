#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> c(n);
    for (auto &x: c) {
        cin >> x;
    }

    vector<vector<int>> g(n);
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);   
    }

    // Let's maintain the maximum and the sum
    vector<pair<int, long long>> ans(n);
    vector<map<int, int>> fs(n);

    function<void(int, int)> dfs = [&](int u, int p) {
        for (int &v: g[u]) {
            if (v == p) {
                swap(v, g[u].back());
                g[u].pop_back();
                break;
            }
        }

        for (int v: g[u]) {
            dfs(v, u);
        }

        if (g[u].size() == 0) {
            fs[u][c[u]] = 1;
            ans[u] = {1, c[u]};
            return;
        }
        auto mx = max_element(g[u].begin(), g[u].end(), [&](int x, int y) {
            return fs[x].size() < fs[y].size();
        });
        swap(g[u][0], *mx);

        swap(fs[u], fs[g[u][0]]);
        ans[u] = ans[g[u][0]];
        for (int i = 1; i < (int)g[u].size(); ++i) {
            int v = g[u][i];
            for (auto [col, f]: fs[v]) {
                fs[u][col] += f;
                if (fs[u][col] > ans[u].first) {
                    ans[u] = {fs[u][col], col};
                } else if (fs[u][col] == ans[u].first) {
                    ans[u].second += col;
                }
            }
            fs[v].clear();
        }
        fs[u][c[u]]++;
        if (fs[u][c[u]] > ans[u].first) {
            ans[u] = {fs[u][c[u]], c[u]};
        } else if (fs[u][c[u]] == ans[u].first) {
            ans[u].second += c[u];
        }
    };
    dfs(0, -1);

    for (auto [val, sm]: ans) {
        cout << sm << ' ';
    }

    return 0;
}
