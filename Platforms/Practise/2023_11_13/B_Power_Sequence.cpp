#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    for (auto &x: a) {
        cin >> x;
    }
    std::ranges::sort(a);

    if (n <= 2) {
        cout << a[0] - 1 << '\n';
        return 0;
    }

    const ll mx = 1LL * (n + 1) * 1000000000;
    ll ans = mx;

    for (int c = 1; ; ++c) {
        ll cur = 0;
        ll p = 1;
        int i = 0;
        for (; i < n and p <= mx; ++i) {
            cur += abs(a[i] - p);
            p *= c;
        }
        if (i == n) {
            ans = min(ans, cur);
        } else {
            break;
        }
    }

    cout << ans << '\n';

    return 0;
}