#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    for (auto &x: a) {
        cin >> x;
        x %= n;
    }

    ll s = 0, ans = 0;
    map<int, int> mp;
    mp[0] = 1;
    for (auto x: a) {
        s = (s + x) % n;
        if (s < 0) {
            s += n;
        }
        if (mp.find(s) != mp.end()) {
            ans += mp.at(s);
        }
        mp[s]++;
    }

    cout << ans << '\n';

    return 0;
}
