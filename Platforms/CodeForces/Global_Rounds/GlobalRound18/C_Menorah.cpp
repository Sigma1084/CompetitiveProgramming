#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    string s, t;
    cin >> s >> t;

    int zz = 0, zo = 0, oz = 0, oo = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '0' && t[i] == '0') {
            ++zz;
        } else if (s[i] == '0' && t[i] == '1') {
            ++zo;
        } else if (s[i] == '1' && t[i] == '0') {
            ++oz;
        } else {
            ++oo;
        }
    }

    if (zz + zo == n) {
        // We don't have 1s at all
        if (zo + oo == 0) {
            cout << 0;
        } else {
            cout << -1;
        }
        return;
    }

    int ans = INT_MAX;

    // Case 1: No flip
    if (oz == zo) {
        ans = oz + zo;
    }

    // Case 2: Flip a 10
    if (oz) {
        int zz1 = oz - 1, zo1 = oo, oz1 = zz + 1, oo = zo;
        if (oz1 == zo1) {
            ans = min(ans, 1 + oz1 + zo1);
        }
    }

    // Case 3: Flip a 11
    if (oo) {
        int zz1 = oz, zo1 = oo - 1, oz1 = zz, oo1 = zo + 1;
        if (oz1 == zo1) {
            ans = min(ans, 1 + oz1 + zo1);
        }
    }

    if (ans == INT_MAX) {
        cout << -1;
    } else {
        cout << ans;
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
