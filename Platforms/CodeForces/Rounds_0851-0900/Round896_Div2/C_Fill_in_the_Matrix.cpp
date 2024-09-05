#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < min(m - 1, n); ++i) {
        for (int j = 0, v = m - 1 - i; j < m; j++) {
            a[i][j] = (v + j) % m;
        }
    }

    for (int i = m - 1; i < n; ++i) {
        // Copy the first row
        a[i] = a[0];
    }

    int ans = min(n + 1, m);
    if (m == 1) ans = 0;

    cout << ans << '\n';
    for (const auto &r: a) {
        for (auto x: r) {
            cout << x << ' ';
        }
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
