#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;

    vector<vector<int>> a(n);
    for (int i = 0, k; i < n; ++i) {
        cin >> k;
        a[i].resize(k);
        for (int &x: a[i]) cin >> x;
    }

    map<int, int> f;
    for (const auto &v: a) {
        for (auto x: v) {
            f[x]++;
        }
    }

    int ans = 0;
    for (const auto &v: a) {
        int numUnique = std::count_if(v.begin(), v.end(), [&](int x) { return f[x] == 1; });
        numUnique = f.size() - numUnique;
        ans = max(ans, numUnique);
    }

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
