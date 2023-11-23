#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    ll c, d;
    cin >> n >> c >> d;

    vector<int> a(n);
    for (auto &x: a) {
        cin >> x;
    }

    map<int, int> cnt;
    for (int x: a) {
        cnt[x]++;
    }

    int rem = n, add = 0, prev = 0;
    ll ans = c * rem + d;
    for (auto [x, f]: cnt) {
        // Add all numbers from prev + 1 to x
        add += x - prev - 1;
        rem -= 1;
        ans = min(ans, c * rem + d * add);
        prev = x;
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
