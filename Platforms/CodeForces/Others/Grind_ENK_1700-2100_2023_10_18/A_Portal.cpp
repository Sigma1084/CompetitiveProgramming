#include <bits/stdc++.h>
using namespace std;
constexpr int INF = 1e9;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<string> b(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
        b[i] = " " + b[i];
    }

    vector<vector<int>> pref(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            pref[i][j] = (b[i][j] == '1');
            pref[i][j] += pref[i - 1][j];
            pref[i][j] += pref[i][j - 1];
            pref[i][j] -= pref[i - 1][j - 1];
        }
    }
    auto get = [&](int i1, int j1, int i2, int j2) {
        int res = pref[i2][j2];
        res -= pref[i1 - 1][j2];
        res -= pref[i2][j1 - 1];
        res += pref[i1 - 1][j1 - 1];
        return res;
    };

    int ans = INF;
    for (int i1 = 1; i1 + 4 <= n; ++i1) {
        for (int i2 = i1 + 4; i2 <= n; ++i2) {
            // Express as f(i1, i2, j1) + g(i1, i2, j2)
            int minG = INF;
            for (int j = m - 3; j >= 1; --j) {
                int f = 0, g = 0, j2 = j + 3;

                // Full negative sum
                f -= get(i1, j, i2, m);
                if (j2 != m) {
                    g += get(i1, j2 + 1, i2, m);
                }

                // Accounting for the corners
                f += (b[i1][j] == '1') + (b[i2][j] == '1');
                g += (b[i1][j2] == '1') + (b[i2][j2] == '1');

                // Add the inside 2 times
                f += 2 * get(i1 + 1, j + 1, i2 - 1, m);
                g -= 2 * get(i1 + 1, j2, i2 - 1, m);
                
                // Accounting for the edges
                f += 2 * (i2 - i1 - 1) + 2 * (0 - j - 1);
                g += 2 * j2;

                minG = min(minG, g);
                ans = min(ans, f + minG);
            }
        }
    }

    cout << ans;
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
