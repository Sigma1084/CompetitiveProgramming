#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    cin >> n;

    vector<array<ll, 2>> a(n);
    for (auto &[x, y]: a) {
        cin >> x >> y;
    }
    sort(a.begin(), a.end(), [](auto &a, auto &b) {
        return a[1] < b[1];
    });

    // Put from end, tend from beginning
    ll tot = 0, ans = 0;
    for (int i = 0, j = n - 1; i <= j; ) {
        if (tot >= a[i][1]) {
            ans += a[i][0];
            tot += a[i][0];
            ++i;
        } else {
            ll cur = min(a[i][1] - tot, a[j][0]);
            a[j][0] -= cur;
            tot += cur;
            ans += cur * 2;
            if (a[j][0] == 0) {
                --j;
            }
        }
    }

    cout << ans << '\n';

    return 0;
}
