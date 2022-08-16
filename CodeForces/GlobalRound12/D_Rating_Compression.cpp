#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n); for (auto &x: a) cin >> x;

    vector<bool> ans(n+1);
    multiset<int> m; for (auto &x: a) m.insert(x);
    {
        // k = 1
        vector<bool> pres(n+1);
        bool ok = true;
        for (auto &x: a) pres[x] = true;
        for (int i=1; i<=n and ok; i++) if (not pres[i]) ok = false;
        if (ok) ans[1] = true;
    }

    int k, s = 0, e = n-1;
    for (int i=1; i<n; i++) {
        k = n + 1 - i;
        if (i > *m.begin()) break;
        if (m.find(i) != m.end()) {
            m.erase(m.find(i));
            ans[k] = true;
            if (a[s] == i) s++;
            else if (a[e] == i) e--;
            else break;
        } else {
            break;
        }
    }
    for (int i=1; i<=n; i++) cout << ans[i];
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int t = 1;
    cin >> t;

    for (int i=1; i<=t; i++) {
        // cout << "Case #" << i << ": ";
        solve(); cout << '\n';
    }

    return 0;
}
