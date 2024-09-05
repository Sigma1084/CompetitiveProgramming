#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    string a;
    cin >> a;

    ll s = 0, ans = 0;
    map<ll, int> mp;
    mp[0] = 1;
    for (auto x: a) {
        s += x - '0' - 1;
        if (mp.find(s) != mp.end()) {
            ans += mp.at(s);
        }
        mp[s]++;
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
