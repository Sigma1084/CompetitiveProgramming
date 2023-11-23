#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;

    vector<pair<int, int>> a(n);
    for (auto &[x, t]: a) cin >> x;
    for (auto &[x, t]: a) cin >> t;

    map<int, vector<int>> cnt;
    for (auto [x, t]: a) {
        cnt[x].push_back(t);
    }
    cnt[1e9 + 1e7];  // dummy

    int y = 0;
    multiset<int, greater<>> ms;
    ll curSum = 0;
    ll ans = 0;

    for (const auto &[x, ts]: cnt) {
        while (y < x and ms.size()) {
            int t = *ms.begin();
            ms.erase(ms.begin());
            curSum -= t;
            ans += curSum;
            ++y;
        }

        y = x;
        for (int t: ts) {
            ms.insert(t);
            curSum += t;
        }
    }

    cout << ans;

    return 0;
}
