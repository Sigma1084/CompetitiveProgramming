#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<string> b(n);
    for (auto &row: b) {
        cin >> row;
    }

    vector<vector<bool>> vis(n, vector<bool>(m, false));

    for (int i = n - 1; i >= 0; --i) {
        for (int j = m - 1; j >= 0; --j) {
            if (b[i][j] != '*') {
                continue;
            }
            // Now check what d is
            int d = 1;
            while(true) {
                if (i - d < 0 or j - d < 0 or j + d >= m) {
                    break;
                }
                if (b[i - d][j - d] != '*' or b[i - d][j + d] != '*') {
                    break;
                }
                ++d;
            }

            if (d <= k) {
                if (!vis[i][j]) {
                    cout << "NO";
                    return;
                } else {
                    continue;
                }
            } 

            for (int l = 0; l < d; ++l) {
                vis[i - l][j - l] = true;
                vis[i - l][j + l] = true;
            }
        }
    }

    cout << "YES";
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
