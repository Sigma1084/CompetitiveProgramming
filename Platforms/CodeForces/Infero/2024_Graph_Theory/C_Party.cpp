#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> p(n);
    for (auto &x: p) {
        cin >> x;
        --x;
    }

    vector<int> d(n, -1);
    function<int(int)> dfs = [&](int u) {
        if (u == -2) return -1;
        if (d[u] != -1) return d[u];
        return d[u] = 1 + dfs(p[u]);
    };

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans = max(ans, dfs(i));
    }

    cout << ans + 1;

    return 0;
}
