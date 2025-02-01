#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<array<int, 2>> a(n);
    for (auto &[x, s]: a) {
        cin >> x;
    }
    for (auto &[x, s]: a) {
        cin >> s;
    }
    sort(a.begin(), a.end(), greater<>());

    // Only if there is a ball after it such that it reaches before it
    // Same time should not be considered
    // Then, it won't be considered

    auto lt = [&](array<int, 2> &a, array<int, 2> &b) {
        return 1LL * a[0] * b[1] <= 1LL * b[0] * a[1];
    };

    int ans = 0;
    array<int, 2> minTime = {INT_MAX, 1};
    for (auto curTime: a) {
        ans += lt(curTime, minTime);
        if (lt(curTime, minTime)) {
            minTime = curTime;
        }
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
