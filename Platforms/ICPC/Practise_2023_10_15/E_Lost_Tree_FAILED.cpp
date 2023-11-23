#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;

    auto ask = [n](int u) {
        cout << "? " << u + 1 << endl;
        vector<int> d(n);
        for (int i = 0; i < n; i++) {
            cin >> d[i];
        }
        return d;
    };

    vector<array<int, 2>> g;
    vector<bool> vis(n);
    queue<int> q;

    q.push(0);
    vis[0] = true;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        auto d = ask(u);

        int num1 = 0;
        int w = -1;
        for (int i = 0; i < n; i++) {
            if (d[i] == 1) {
                if (vis[i]) {
                    vis[u] = true;
                    g.push_back({i, u});
                } else {
                    num1++;
                    w = i;
                }
            }
        }

        if (num1 == 1) {
            vis[w] = true;
            g.push_back({u, w});
        } else {
            num1 = 0;
        }

        for (int i = 0; i < n; i++) {
            if (vis[i]) continue;
            if (d[i] == 1 + num1) {
                vis[i] = true;
                g.push_back({w, i});
            } else if (d[i] == 2 + num1) {
                q.push(i);
            }
        }
    }

    cout << "!" << endl;
    for (auto [u, v] : g) {
        cout << u + 1 << " " << v + 1 << endl;
    }
}

