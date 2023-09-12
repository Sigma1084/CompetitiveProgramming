#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<pair<int, int>> ans;
    ans.emplace_back(1, n);
    ans.emplace_back(1, n - (n % 2));

    if (n % 2) {
        ans.emplace_back(n - 1, n);
        ans.emplace_back(n - 1, n);
    }

    cout << ans.size() << '\n';
    for (auto [x, y] : ans) {
        cout << x << ' ' << y << '\n';
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
