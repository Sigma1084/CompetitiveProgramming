#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n - 1), b(n);
    for (auto &x: a) {
        cin >> x;
    }
    for (auto &x: b) {
        cin >> x;
    }

    ranges::sort(a);
    ranges::sort(b);

    int mx = b.back();
    int j = 0;
    for (int i = 0; i + j < n and i < n - 1; ++i) {
        while (i+j < n and a[i] >= b[i+j]) {
            mx = b[i+j];
            j++;
        }
    }

    j = max(0, j - 1);

    // the mx is the point where shit breaks
    ll ans = 1LL * m * j;
    ans += max(m - mx + 1, 0);

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
