#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    ll m;
    cin >> n >> m;

    vector<pair<int, int>> a(n);
    for (auto &[x, _] : a) {
        cin >> x;
    }
    for (auto &[_, f] : a) {
        cin >> f;
    }
    sort(a.begin(), a.end());

    ll ans = 0, cur;
    for (int i = 0; i < n; ++i) {
        int q = min(m / a[i].first, 0LL + a[i].second);
        cur = 1LL * q * a[i].first;
        ans = max(ans, cur);
        if (i + 1 < n and a[i].first + 1 == a[i + 1].first) {
            // Ignore some of these and take them
            // Let's see what happens when we convert everything to  + 1
            int q2 = min((m - cur) / (a[i + 1].first), 0LL + a[i + 1].second);
            cur += 1LL * q2 * (a[i].first + 1);
            cur += min(q, a[i+1].second - q2);
            ans = max(ans, cur);
        }
    }

    ans = min(ans, m);
    cout << ans;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;

    for (int i = 1; i <= t; ++i) {
        solve();
        std::cout << '\n';
    }

    return 0;
}
