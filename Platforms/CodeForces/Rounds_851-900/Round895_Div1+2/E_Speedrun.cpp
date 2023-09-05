#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, m, k; // numQuests, numDepes, numHours
    cin >> n >> m >> k;

    vector<int> h(n);
    for (int &i: h) {
        cin >> i;
    }

    vector<int> ord(n);  // h[ord[i]] < h[ord[i + 1]]
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&] (int i, int j) {
        return h[i] < h[j];
    });

    vector<int> invOrd(n);  // invOrd[i] = j s.t. ord[j] = i
    for (int i = 0; i < n; i++) {
        invOrd[ord[i]] = i;
    }

    sort(h.begin(), h.end());

    vector<vector<int>> e(n);
    vector<vector<int>> re(n);

    for (int i = 0, a, b; i < m; i++) {
        cin >> a >> b;
        a = invOrd[a - 1];
        b = invOrd[b - 1];
        e[a].push_back(b);
        re[b].push_back(a);
    }

    vector<int> days(n, 0);  // number of days req
    vector<int> dep(n, 0);  // max dependency

    // Topological sort
    vector<int> inDeg(n);
    for (int i = 0; i < n; i++) {
        inDeg[i] = re[i].size();
    }

    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (inDeg[i] == 0) {
            days[i] = 0;
            dep[i] = i;
            q.push(i);
        }
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v: e[u]) {
            inDeg[v]--;
            int pos = days[u] + int(v < u);
            if (days[v] == pos) {
                dep[v] = min(dep[v], dep[u]);
            } else if (days[v] < pos) {
                days[v] = pos;
                dep[v] = dep[u];
            }
            if (inDeg[v] == 0) {
                q.push(v);
            }
        }
    }

    vector<vector<int>> rDep(n);
    for (int i = 0; i < n; i++) {
        rDep[dep[i]].push_back(i);
    }

    vector<ll> ans(n);
    multiset<ll> s;
    for (int i = 0; i < n; i++) {
        ans[i] = 1LL * days[i] * k + h[i];
        s.insert(ans[i]);
    }
    ll finalAns = *s.rbegin() - *s.begin();

    // Now slowly remove and increase the 
    // deps from least to highest

    for (int i = 0; i < n; i++) {
        for (int j: rDep[i]) {
            s.erase(s.find(ans[j]));
            ans[j] += k;
            s.insert(ans[j]);
        }
        finalAns = min(finalAns, *s.rbegin() - *s.begin());
    }

    cout << finalAns;
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
