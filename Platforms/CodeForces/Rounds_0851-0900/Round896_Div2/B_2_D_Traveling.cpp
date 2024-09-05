#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, k, a, b;
    cin >> n >> k >> a >> b;
    a--; b--;
    
    vector<array<ll ,2>> pos(n);
    for (auto &[x, y]: pos) {
        cin >> x >> y;
    }

    ll d1 = 1e18, d2 = 1e18;
    for (int i = 0; i < k; i++) {
        d1 = min(d1, abs(pos[i][0] - pos[a][0]) + abs(pos[i][1] - pos[a][1]));
        d2 = min(d2, abs(pos[i][0] - pos[b][0]) + abs(pos[i][1] - pos[b][1]));
    }

    ll ans = abs(pos[a][0] - pos[b][0]) + abs(pos[a][1] - pos[b][1]);
    ans = min(ans, d1 + d2);

    cout << ans;
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
