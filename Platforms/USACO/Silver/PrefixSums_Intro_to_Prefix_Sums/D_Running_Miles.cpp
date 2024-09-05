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

    vector<int> l(n), r(n);
    for (int i = 0; i < n; ++i) {
        l[i] = a[i] + i;
        r[i] = a[i] - i;
    }
    for (int i = 1; i < n; ++i) {
        l[i] = max(l[i], l[i - 1]);
    }
    for (int i = n - 2; i >= 0; --i) {
        r[i] = max(r[i], r[i + 1]);
    }

    int ans = 0;
    for (int i = 1; i + 1 < n; ++i) {
        ans = max(ans, l[i-1] + r[i+1] + a[i]);
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
