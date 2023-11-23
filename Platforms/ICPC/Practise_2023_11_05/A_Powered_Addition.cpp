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

    int ans = 0, mx = INT_MIN;
    for (int i = 0; i + 1 < n; ++i) {
        mx = max(mx, a[i]);
        int diff = mx - a[i+1];
        if (diff <= 0) continue;
        ans = max(ans, __lg(diff) + 1);
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
