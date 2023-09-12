#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, m, k; // numQuests, numDepes, numHours
    cin >> n >> m >> k;

    vector<int> h1(n);
    for (int &i: h1) {
        cin >> i;
    }

    vector<vector<int>> e(n);
    vector<vector<int>> re(n);

    for (int i = 0, a, b; i < m; i++) {
        cin >> a >> b;
        a--; b--;
        e[a].push_back(b);
        re[b].push_back(a);
    }

    auto func = [&] (const vector<int> &h) -> ll {
        vector<int> ans(n, n + 1);  // Delay

        // Topological sort
        vector<int> inDeg(n);
        for (int i = 0; i < n; i++) {
            inDeg[i] = re[i].size();
        }

        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (inDeg[i] == 0) {
                ans[i] = 0;
                q.push(i);
            }
        }

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v: e[u]) {
                inDeg[v]--;
                if (inDeg[v] == 0) {
                    ans[v] = min(ans[v], ans[u] + (h[v] < h[u]));
                    q.push(v);
                }
            }
        }

        ll mn = 1e18, mx = 0;
        for (int i = 0; i < n; i++) {
            ll cur = 1LL * ans[i] * k + h[i];
            mn = min(mn, cur);
            mx = max(mx, cur);
        }

        return mx - mn;
    };

    // Order based on hours
    vector<int> ord(n);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&] (int i, int j) {
        return h1[i] < h1[j];
    });

    for (int i = 0; i < n; i++) {
        cerr << h1[ord[i]] << ' ';
    }
    cerr << '\n';

    int a = 0, b = n - 1;
    ll fa = func(h1);
    ll fb = fa + k;

    cerr << fa << '\n';
    vector<int> h2 = h1;
    for (int i = 0; i < n; i++) {
        h2[ord[i]] += k;
        ll f = func(h2);
        cerr << f << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    while (t--) {
        solve();
        cout << '\n';
    }

    return 0;
}
