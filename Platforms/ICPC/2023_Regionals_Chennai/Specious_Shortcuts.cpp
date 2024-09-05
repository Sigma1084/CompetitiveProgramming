#include <bits/stdc++.h>
using namespace std;
using ll = long long;

auto bfs(int n, const vector<vector<int>> &g, int s) {
    vector<int> d(n, -1);
    queue<int> q;
    q.push(s);
    d[s] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto v: g[u]) {
            if (d[v] == -1) {
                d[v] = d[u] + 1;
                q.push(v);
            }
        }
    }
    return d;
}

void solve() {
    int n, m, k, s, t;
    cin >> n >> m >> k >> s >> t;
    --s; --t;

    while (k--) {
        int x;
        cin >> x;
    }

    bool joined = false;
    vector<vector<int>> g(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;

        if (minmax(u, v) == minmax(s, t)) {
            joined = true;
        }

        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> dist1 = bfs(n, g, s);
    vector<int> dist2 = bfs(n, g, t);

    map<int, map<int, int>> cnt;
    for (int u = 0; u < n; ++u) {
        if (u == s or u == t) {
            continue;
        }
        ++cnt[dist1[u]][dist2[u]];
    }

    ll m1 = 0;
    for (auto [ds, smap]: cnt) {
        for (auto [dt, f]: smap) {
            m1 += 1LL * f * (f - 1) / 2;
            m1 += 1LL * f * smap[dt - 1];
            if (cnt.find(ds - 1) != cnt.end()) {
                m1 += 1LL * f * (cnt.at(ds - 1)[dt] + cnt.at(ds - 1)[dt - 1] + cnt.at(ds - 1)[dt + 1]);
            }
        }
    }

    for (int u = 0; u < n; ++u) {
        if (u == s or u == t) {
            continue;
        }
        for (int v: g[u]) {
            if (v == s or v == t) {
                continue;
            } else if (v > u) {
                --m1;
            }
        }
    }

    if (not joined) {
        joined = true;
        for (int u = 0; u < n; ++u) {
            if (u == s or u == t) {
                continue;
            }
            if (abs(dist1[u] - dist2[u]) > 1) {
                joined = false;
                break;
            }
        }
        m1 += joined;
    }

    cout << m1;
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
