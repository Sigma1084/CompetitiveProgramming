#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k; cin >> n >> k;
    vector<pair<int, int>> a(n);
    for (auto &x: a) cin >> x.first >> x.second;

    bool ok = false;
    for (int i = 0; i < n and !ok; i++) {
        int x = a[i].first, y = a[i].second;
        bool ok2 = true;
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            int x1 = a[j].first, y1 = a[j].second;
            if (abs(x - x1) + abs(y - y1) > k) { ok2 = false; break; }
        }
        if (ok2) ok = true;
    }
    cout << (ok ? 1 : -1);
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
