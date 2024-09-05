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

    map<int, int> l, r;
    for (int i = 0; i < n; ++i) {
        if (l.find(a[i]) == l.end()) {
            l[a[i]] = i;
            r[a[i]] = i;
        } else {
            r[a[i]] = i;
        }
    }

    int mx = 0;
    int mL = 0, mR = n - 2;  // Where can we end the first range
    while (mL <= mR) {
        // Can we have mx in both left and right
        if (l.find(mx) == l.end()) {
            // Good, we can select any value in this range
            cout << 2 << '\n';
            cout << 1 << ' ' << mL + 1 << '\n';
            cout << mL + 2 << ' ' << n << '\n';
            return;
        } else if (l[mx] == r[mx]) {
            cout << -1 << '\n';
            return;
        }
        // Now, we restrict mL and mR
        mL = max(mL, l[mx]);
        mR = min(mR, r[mx]);

        mx++;
    }

    cout << -1 << '\n';
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
