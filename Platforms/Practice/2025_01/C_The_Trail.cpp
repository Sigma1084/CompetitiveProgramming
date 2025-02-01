#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;

    string p;
    cin >> p;
    p += 'D';

    vector g(n, vector<ll>(m, 0));
    for (auto &v : g) {
        for (auto &x : v) {
            cin >> x;
        }
    }

    int r = 0, c = 0;
    for (int t = 0; t < n + m - 1; ++t) {
        if (p[t] == 'D') {
            for (int j = 0; j < m; ++j) {
                if (j != c) {
                    g[r][c] -= g[r][j];
                }
            }
            r++;
        } else if (p[t] == 'R') {
            for (int i = 0; i < n; ++i) {
                if (i != r) {
                    g[r][c] -= g[i][c];
                }
            }
            c++;
        } else {
            assert(false);
        }
    }

    for (const auto &v : g) {
        for (auto x : v) {
            cout << x << ' ';
        }
        cout << '\n';
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;

    while (t--) {
        solve();
        std::cout << '\n';
    }

    return 0;
}
