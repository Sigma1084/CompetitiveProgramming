#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, m; cin >> n >> m;

    vector<string> b(n);
    for (string &s: b) {
        cin >> s;
    }

    vector<string> ans(n, string(m, '.'));

    // First do rows by only inserting tops
    int cur = 0;
    for (int i = 0; i + 1 < n; i++) {
        for (int j = 0; j < m; j++) {
            if (b[i][j] != 'U') continue;
            if (cur) {
                ans[i][j] = 'W';
                ans[i + 1][j] = 'B';
            } else {
                ans[i][j] = 'B';
                ans[i + 1][j] = 'W';
            }
            cur ^= 1;
        }
        cur ^= 1;
    }

    // Now do columns by only inserting lefts
    cur = 0;
    for (int j = 0; j + 1 < m; j++) {
        for (int i = 0; i < n; i++) {
            if (b[i][j] != 'L') continue;
            if (cur) {
                ans[i][j] = 'W';
                ans[i][j + 1] = 'B';
            } else {
                ans[i][j] = 'B';
                ans[i][j + 1] = 'W';
            }
            cur ^= 1;
        }
        cur ^= 1;
    }

    // Check if it works
    vector<int> r(n), c(m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (ans[i][j] == 'W') {
                r[i]++;
                c[j]++;
            } else if (ans[i][j] == 'B') {
                r[i]--;
                c[j]--;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (r[i] != 0) {
            cout << -1 << '\n';
            return;
        }
    }

    for (int j = 0; j < m; j++) {
        if (c[j] != 0) {
            cout << -1 << '\n';
            return;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
