#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n), b(n), c(n);
    for (int &x: a) cin >> x;
    for (int &x: b) cin >> x;
    for (int &x: c) cin >> x;

    const ll S = accumulate(a.begin(), a.end(), 0LL);
    const ll R = (S + 2) / 3;

    array<int, 6> ans;

    auto isPos = [n, R, &ans](const auto &a, const auto &b, const auto &c) {
        int i = 0;
        ans[0] = i + 1;
        ll cur = 0;
        for (; i < n and cur < R; ++i) {
            cur += a[i];
        }
        ans[1] = i;
        if (cur < R) return false;

        cur = 0;
        ans[2] = i + 1;
        for (; i < n and cur < R; ++i) {
            cur += b[i];
        }
        ans[3] = i;
        if (cur < R) return false;

        cur = 0;
        ans[4] = i + 1;
        for (; i < n and cur < R; ++i) {
            cur += c[i];
        }
        ans[5] = i;
        return cur >= R;
    };

    if (isPos(a, b, c)) {
        cout << ans[0] << ' ' << ans[1] << ' ' << ans[2] << ' ' << ans[3] << ' ' << ans[4] << ' ' << ans[5];
    } else if (isPos(a, c, b)) {
        cout << ans[0] << ' ' << ans[1] << ' ' << ans[4] << ' ' << ans[5] << ' ' << ans[2] << ' ' << ans[3];
    } else if (isPos(b, a, c)) {
        cout << ans[2] << ' ' << ans[3] << ' ' << ans[0] << ' ' << ans[1] << ' ' << ans[4] << ' ' << ans[5];
    } else if (isPos(b, c, a)) {
        cout << ans[4] << ' ' << ans[5] << ' ' << ans[0] << ' ' << ans[1] << ' ' << ans[2] << ' ' << ans[3];
    } else if (isPos(c, a, b)) {
        cout << ans[2] << ' ' << ans[3] << ' ' << ans[4] << ' ' << ans[5] << ' ' << ans[0] << ' ' << ans[1];
    } else if (isPos(c, b, a)) {
        cout << ans[4] << ' ' << ans[5] << ' ' << ans[2] << ' ' << ans[3] << ' ' << ans[0] << ' ' << ans[1];
    } else {
        cout << -1;
    }
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
