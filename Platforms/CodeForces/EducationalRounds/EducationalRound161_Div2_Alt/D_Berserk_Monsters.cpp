#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n), d(n);
    for (auto &x: a) {
        cin >> x;
    }
    for (auto &x: d) {
        cin >> x;
    }

    set<int> alive;
    vector<int> toErase;
    for (int i = 0; i < n; ++i) {
        alive.insert(i);
        int dmg = (i > 0 ? a[i-1] : 0) + (i+1 < n ? a[i+1] : 0);
        if (d[i] < dmg) {
            toErase.push_back(i);
        }
    }

    int cur = 0;
    vector<int> ans(n + 1);
    while (cur < n and !alive.empty() and !toErase.empty()) {
        ++cur;
        ans[cur] = toErase.size();

        for (auto i: toErase) {
            alive.erase(i);
        }

        set<int> toChange;
        for (auto i: toErase) {
            // Check if there's a left alive
            if (alive.lower_bound(i) != alive.begin()) {
                int j = *prev(alive.lower_bound(i));
                toChange.insert(j);
            }
            // Check if there's a right alive
            if (alive.upper_bound(i) != alive.end()) {
                int j = *alive.upper_bound(i);
                toChange.insert(j);
            }
        }

        toErase.clear();
        for (auto i: toChange) {
            // Check if there's a left alive
            int dmg = 0;
            if (alive.lower_bound(i) != alive.begin()) {
                int j = *prev(alive.lower_bound(i));
                dmg += a[j];
            }
            // Check if there's a right alive
            if (alive.upper_bound(i) != alive.end()) {
                int j = *alive.upper_bound(i);
                dmg += a[j];
            }
            if (d[i] < dmg) {
                toErase.push_back(i);
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << ' ';
    }
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
