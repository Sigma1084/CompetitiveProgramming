#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    // dp (l, r) := From the (left, right)
    vector<int> dpl(n + 1), dpr(n + 1);

    // dp1 means good and dp2 means bad
    vector<int> dp1(n + 1), dp2(n + 1);
    for (int i = 1; i <= n; ++i) {
        // Can NOT go left from here
        if (s[i-1] == 'L') {
            dp1[i] = dp2[i-1] + 1;
            dp2[i] = 0;
        } else {
            dp1[i] = 0;
            dp2[i] = dp1[i-1] + 1;
        }
    }
    dpl = dp1;

    dp1.assign(n + 1, 0);
    dp2.assign(n + 1, 0);
    for (int i = n - 1; i >= 0; --i) {
        if (s[i] == 'R') {
            dp1[i] = dp2[i+1] + 1;
            dp2[i] = 0;
        } else {
            dp1[i] = 0;
            dp2[i] = dp1[i+1] + 1;
        }
    }
    dpr = dp1;

    for (int i = 0; i <= n; ++i) {
        cout << dpl[i] + dpr[i] + 1 << ' ';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    for (int i = 1; i <= t; ++i) {
        solve();
        cout << '\n';
    }

    return 0;
}
