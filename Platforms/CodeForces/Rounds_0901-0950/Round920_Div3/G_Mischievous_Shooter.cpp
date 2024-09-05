#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<string> b(n);
    for (auto &x: b) {
        cin >> x;
    }

    vector<vector<int>> sq(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            sq[i][j] = (b[i][j] == '1');
            if (i > 0) {
                sq[i][j] += sq[i-1][j];
            }
            if (j > 0) {
                sq[i][j] += sq[i][j-1];
            }
            if (i > 0 and j > 0) {
                sq[i][j] -= sq[i-1][j-1];
            }
        }
    }

    vector<vector<int>> diag(n + m - 1);
    for (int d = 0; d < n + m - 1; ++d) {
        for (int i = 0, j = d - i; i < n and j >= 0; ++i, --j) {
            if (j >= m) continue;
            diag[d].push_back(sq[i][j]);
        }
    }

    /**
     * Returns the sum of d squares total
     * including the square at (i, j)
     */
    auto top = [&](int i, int j, int d) {
        auto res = sq[i][j];
        if (i - d >= 0) {
            res -= sq[i-d][j];
        }
        if (j - 1 >= 0) {
            res -= sq[i][j-1];
        }
        if (i - d >= 0 and j - d >= 0) {
            res += sq[i-d][j-1];
        }
        return res;
    };
    auto left = [&](int i, int j, int d) {
        auto res = sq[i][j];
        if (i - 1 >= 0) {
            res -= sq[i-1][j];
        }
        if (j - d >= 0) {
            res -= sq[i][j-d];
        }
        if (i - 1 >= 0 and j - d >= 0) {
            res += sq[i-1][j-d];
        }
        return res;
    };

    /**
     * Returns num squares in diagonal d starting with i
     */
    auto diag = [&](int i, int d, int num) {
        int j = d - i;
        int 
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
