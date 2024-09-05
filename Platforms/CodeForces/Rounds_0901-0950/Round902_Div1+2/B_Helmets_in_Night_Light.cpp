#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, p;
    cin >> n >> p;

    // [cost, number]
    vector<array<int, 2>> a(n);
    for (auto &[cost, number] : a) cin >> number;
    for (auto &[cost, number] : a) cin >> cost;

    sort(a.begin(), a.end());

    ll ans = p;
    int count = 1;
    for (auto [cost, number] : a) {
        if (cost > p or count == n) break;
        ans += 1LL * cost * min(n - count, number);
        count += min(n - count, number);
    }
    ans += 1LL * p * (n - count);

    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    while (t--) {
        solve();
        cout << '\n';
    }

    return 0;
}
