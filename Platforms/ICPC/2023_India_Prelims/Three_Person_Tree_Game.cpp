#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    int a, b, c;
    cin >> a >> b >> c;
    --a, --b, --c;

    vector<vector<int>> e(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    vector<int> p(n, -1);
    vector<int> d(n, -1);

    // Compute path from a to b and c
    function<void(int)> dfs = [&](int u) {
        for (int v: e[u]) {
            if (v == p[u]) continue;
            p[v] = u;
            d[v] = d[u] + 1;
            dfs(v);
        }
    };
    d[a] = 0;
    dfs(a);

    vector<int> pb, pc;
    for (int i = b; i != a; i = p[i]) {
        pb.push_back(i);
    }
    for (int i = c; i != a; i = p[i]) {
        pc.push_back(i);
    }
    reverse(pb.begin(), pb.end());
    reverse(pc.begin(), pc.end());

    int x = 0;
    while (x < pb.size() and x < pc.size()) {
        if (pb[x] != pc[x]) break;
        ++x;
    }

    int y = int(pb.size()) - x;
    int z = int(pc.size()) - x;

    if (x == 0) {
        cout << "A";
        return;
    } else if (y == 0) {
        cout << "B";
        return;
    } else if (z == 0) {
        if (x == 1) {
            cout << "A";
        } else {
            cout << "C";
        }
        return;
    }

    int m = min({x, y, z});
    x -= m - 1;
    y -= m - 1;
    z -= m - 1;

    if (x == 1) {
        if (y != 1) {
            cout << "A";
        } else if (z != 1) {
            cout << "B";
        } else {
            cout << "DRAW";
        }
        return;
    }

    x -= 1;

    if (y == 1) {
        if (z != 1) {
            cout << "B";
        } else if (x != 1) {
            cout << "C";
        } else {
            cout << "DRAW";
        }
        return;
    }

    y -= 1;

    if (z == 1) {
        if (x != 1) {
            cout << "C";
        } else if (y != 1) {
            cout << "A";
        } else {
            cout << "DRAW";
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;

    for (int i = 1; i <= t; ++i) {
        solve();
        std::cout << '\n';
    }

    return 0;
}