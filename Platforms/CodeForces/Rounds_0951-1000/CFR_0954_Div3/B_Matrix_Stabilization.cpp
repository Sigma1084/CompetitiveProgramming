#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(n, vector<int>(m));
    for (auto &row: a) {
        for (auto &x: row) {
            cin >> x;
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int nb = 0;
            if (i - 1 >= 0) {
                nb = max(nb, a[i-1][j]);
            }
            if (j - 1 >= 0) {
                nb = max(nb, a[i][j-1]);
            }
            if (i + 1 < n) {
                nb = max(nb, a[i+1][j]);
            }
            if (j + 1 < m) {
                nb = max(nb, a[i][j+1]);
            }
            a[i][j] = min(a[i][j], nb);
        }
    }

    for (const auto &row: a) {
        for (auto x: row) {
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

    for (int i = 1; i <= t; ++i) {
        solve();
    }

    return 0;
}
