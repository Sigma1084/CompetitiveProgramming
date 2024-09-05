#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (auto &x: a) {
        cin >> x;
    }

    vector<int> loc(n);
    for (int i = 0; i < n; ++i) {
        loc[a[i]] = i;
    }

    ll ans = 0;
    for (int l = n-1, r = 0, d = 1, c = 0; d <= n; ++d) {
        if (d % 2 == 1) {
            l = min(l, loc[c]);
            r = max(r, loc[c]);
            ++c;
        }
        // [l, r] MUST be there
        if (r - l + 1 > d) {
            continue;
        }
        // we need to add a few things now
        int L = max(0, r - d + 1);
        int R = min(n - 1, l + d - 1);
        ans += R - L + 2 - d;
    }

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
