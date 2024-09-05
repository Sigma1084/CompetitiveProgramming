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

    int ans = min(a[0], a[1]);
    for (int i = 0; i + 2 < n; ++i) {
        array<int, 3> b = {a[i], a[i + 1], a[i + 2]};
        sort(b.begin(), b.end());
        ans = max(ans, b[1]);
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
