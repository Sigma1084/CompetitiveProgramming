#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;

    vector<int> a(n);
    map<int, int> cnt;
    for (int &x: a) {
        cin >> x;
        ++cnt[x];
    }

    for (auto [x, f]: cnt) {
        if (f % 2 != 0) {
            cout << -1 << '\n';
            return;
        }
    }

    vector<int> ts;
    vector<pair<int, int>> ans;
    int t = 0;  // Number of elements seen so far

    for (int i = 0; i < n; i += 2) {
        // Find j such that a[i] = a[j]
        int j = i + 1;
        while (a[j] != a[i]) ++j;
        for (int k = i + 1, p = t + (j - i) + 1; k < j; ++k, ++p) {
            ans.emplace_back(p, a[k]);
        }
        ts.push_back(2 * (j - i));
        t += ts.back();
        reverse(a.begin() + i + 1, a.begin() + j + 1);
    }

    cout << ans.size() << '\n';
    for (auto [x, y]: ans) {
        cout << x << ' ' << y << '\n';
    }

    cout << ts.size() << '\n';
    for (int x: ts) {
        cout << x << ' ';
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    while (t--) {
        solve();
        cout << "\n "[t == 0];
    }

    return 0;
}
