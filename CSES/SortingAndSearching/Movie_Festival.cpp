#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<pair<int, int>> a(n);
    for (auto &x: a) cin >> x.second >> x.first;
    sort(a.begin(), a.end());

    int ans = 0, curTime = 0;
    for (auto &p: a) {
        int e = p.first, s = p.second;
        if (s >= curTime) ans++, curTime = e;
    }

    cout << ans;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int t = 1;
    // cin >> t;

    for (int i=1; i<=t; i++) {
        // cout << "Case #" << i << ": ";
        solve(); cout << '\n';
    }

    return 0;
}
