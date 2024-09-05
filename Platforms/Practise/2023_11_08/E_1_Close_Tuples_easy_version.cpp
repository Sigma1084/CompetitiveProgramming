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
    sort(a.begin(), a.end());

    ll ans = 0;
    for (int i = 0, j = 2; i + 2 < n; ++i) {
        while (j < n and a[j] - a[i] <= 2) {
            j += 1;
        }
        ans += 1LL * (j - i - 1) * (j - i - 2) / 2;
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
