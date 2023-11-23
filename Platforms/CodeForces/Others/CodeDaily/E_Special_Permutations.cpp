#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> a(m);
    map<int, vector<int>> mp;
    for (int i = 0; i < m; ++i) {
        cin >> a[i];
        mp[a[i]].push_back(i);
    }

    auto pos = [](int i, int x) {
        if (i == x) return 1;
        return x + int(x < i);
    };

    // Calculate for every occurance normally
    // Go and edit for a[i]
    ll ans = 0;
    for (int p = 0; p+1 < m; ++p) {
        ans += abs(pos(1, a[p]) - pos(1, a[p+1]));
    }

    cout << ans << ' ';
    for (int i = 2; i <= n; ++i) {
        /**
         * i and i-1 would change in this iteration
         * i-1 from 1 to i
         * i from i to 1
         */
        set<int> s;
        for (int p: mp[i-1]) {
            s.insert(p-1);
            s.insert(p);
        }
        for (int p: mp[i]) {
            s.insert(p-1);
            s.insert(p);
        }
        s.erase(-1);
        s.erase(m-1);

        for (auto p: s) {
            ans -= abs(pos(i-1, a[p]) - pos(i-1, a[p+1]));
            ans += abs(pos(i, a[p]) - pos(i, a[p+1]));
        }

        cout << ans << ' ';
    }
    cout << '\n';

    return 0;
}
