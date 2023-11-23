#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    cin >> n;

    // [time, deadline]
    vector<pair<int, int>> a(n);
    for (auto &[t, d]: a) {
        cin >> t >> d;
    }
    sort(a.begin(), a.end());

    ll ans = 0, cur = 0;
    for (auto [t, d]: a) {
        cur += t;
        ans += d - cur;
    }

    cout << ans << '\n';

    return 0;
}
