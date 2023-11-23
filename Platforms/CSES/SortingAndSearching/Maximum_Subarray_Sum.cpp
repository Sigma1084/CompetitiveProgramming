#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    cin >> n;

    /// Suppose we have pref[i].
    /// We need to subtract with min pref before
    ll minBef = 0, cur = 0, ans = -1e18;
    for (int i = 0, x; i < n; ++i) {
        cin >> x;
        cur += x;
        ans = max(ans, cur - minBef);
        minBef = min(minBef, cur);
    }

    cout << ans << '\n';

    return 0;
}
