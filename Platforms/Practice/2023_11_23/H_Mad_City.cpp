#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> cycle(int n, const vector<vector<int>> &e) {
    vector<int> d(n, -1), p(n);
    d[0] = 0; p[0] = -1;
    queue<int> q;
    q.push(0);
    int p1 = -1, p2 = -1;
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto &v: e[u]) {
            if (v == p[u]) continue;
            if (d[v] != -1) {
                // The cycle is from u to v
                p1 = v; p2 = u;   // d[v] <= d[u]
                break;
            }
            d[v] = d[u] + 1;
            p[v] = u;
            q.push(v);
        }
        if (p1 != -1) break;
    }


    if (d[p1] > d[p2]) swap(p1, p2);

    // There is a cycle from p1 to p2
    vector<int> ans;
    while (d[p2] > d[p1]) {
        ans.push_back(p2);
        p2 = p[p2];
    }

    while (p1 != p2) {
        ans.push_back(p1);
        ans.push_back(p2);
        p1 = p[p1];
        p2 = p[p2];
    }
    ans.push_back(p1);
    return ans;
}

void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    --a; --b;

    vector<vector<int>> e(n);
    for (int i = 0; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    vector<int> c = cycle(n, e);

    vector<bool> isC(n);
    for (auto &x: c) {
        isC[x] = true;
    }

    // Compute distances from a to all nodes
    vector<int> da(n, -1);
    da[a] = 0;
    queue<int> q;
    q.push(a);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto &v: e[u]) {
            if (da[v] != -1) continue;
            da[v] = da[u] + 1;
            q.push(v);
        }
    }

    q.push(b);
    vector<int> db(n, -1);
    db[b] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (isC[u]) {
            if (da[u] <= db[u]) {
                cout << "NO";
            } else {
                cout << "YES";
            }
            return;
        }
        for (auto &v: e[u]) {
            if (db[v] != -1) continue;
            db[v] = db[u] + 1;
            q.push(v);
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
