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

    map<int, vector<int>> mp;
    for (int i = 0; i < n; ++i) {
        mp[a[i]].push_back(i);
    }

    if (mp.size() == 1) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    int r = -1, sR = -1;
    for (auto [x, v]: mp) {
        if (r == -1) {
            r = v[0];
            continue;
        }
        if (sR == -1) {
            sR = v[0];
        }
        for (auto y: v) {
            cout << r + 1 << ' ' << y + 1 << '\n';
        }
    }

    for (auto x: mp.begin()->second) {
        if (x == r) continue;
        cout << sR + 1 << ' ' << x + 1 << '\n';
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;

    for (int i = 1; i <= t; ++i) {
        solve();
    }

    return 0;
}
