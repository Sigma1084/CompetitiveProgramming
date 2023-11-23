#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<vector<int>> mp(n + 1);
    for (int i = 0, ai; i < n; ++i) {
        cin >> ai;
        mp[ai].push_back(i);
    }

    ll m;
    cin >> m;

    // [s, e, time]
    set<tuple<int, int, int>> s;
    s.emplace(0, n - 1, n);  // Unattended intervals

    // Number of intervals of length
    vector<ll> numInt(n + 1);

    for (int i = n; i >= 0; --i) {
        for (int idx: mp[i]) {
            // We need to remove a range and split it
            auto it = --s.upper_bound({idx, n, 0});
            auto [ls, re, t] = *it;
            s.erase(it);

            numInt[re - ls + 1] += t - i;

            if (ls != idx) {
                s.emplace(ls, idx - 1, i);
            }
            if (re != idx) {
                s.emplace(idx + 1, re, i);
            }
        }
    }

    ll ans = 0;
    for (int i = n; i >= 2 and m; --i) {
        // Number of intervals possible to take
        ll k = min(numInt[i], m / i);
        ans += k * (i - 1);
        m -= k * i;
        numInt[i] -= k;

        if (numInt[i] and m) {
            ans += m - 1;
            m = 0;
            numInt[i] -= 1;
        }
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
