#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    ll m;
    cin >> n >> m;

    vector<int> a(n);
    for (auto &x: a) {
        cin >> x;
    }
    sort(a.begin(), a.end());

    ll cur = 0, ans = 0;
    for (int i = 0, j = 0; i < n; ++i) {
        while (j < n and a[j] <= a[i] + 1 and cur + a[j] <= m) {
            cur += a[j++];
        }
        ans = max(ans, cur);
        cur -= a[i];
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
