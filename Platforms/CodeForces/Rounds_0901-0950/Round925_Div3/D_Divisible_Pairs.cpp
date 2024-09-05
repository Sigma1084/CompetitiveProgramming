#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, x, y;
    cin >> n >> x >> y;

    vector<int> a(n);
    for (int &ai: a) cin >> ai;

    ll ans = 0;
    map<pair<int, int>, int> cnt;
    for (auto e: a) {
        ans += cnt[{(x - e % x) % x, e % y}];
        ++cnt[{e % x, e % y}];
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
