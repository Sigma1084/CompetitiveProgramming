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

    vector<int> vis(n, -1), b(n, -1);
    int u = 0;
    while (vis[u] == -1) {
        vis[u] = 0;
        u = p[u];
    }

    for (int u = 0; u < n; ++u) {
        if (b[u] != -1) continue;
        int v = u;
        while (vis[v] == -1) {
            vis[v] = u;
            v = p[v];
        }
        if (vis[v] == u) {
            // Cycle
            while (b[v] == -1) {
                b[v] = v;
                v = p[v];
            }
        }
        // v is the first point of contact
        for (int w = u; w != v; w = p[w]) {
            b[w] = b[v];
        }
    }

    for (auto x: b){
        cout << x + 1 << ' ';
    }
    
    return 0;
}
