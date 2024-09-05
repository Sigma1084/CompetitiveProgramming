#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    // freopen("lazy.in", "r", stdin);
    // freopen("lazy.out", "w", stdout);

    int n, k;
    cin >> n >> k;

    vector a(n, vector(n, 0));
    for (auto &r: a) {
        for (auto &x: r) {
            cin >> x;
        }
    }

    auto dU = a, dD = a;
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (j > 0) {
                dD[i][j] += dD[i-1][j-1];
            }
            if (j + 1 < n) {
                dU[i][j] += dU[i-1][j+1];
            }
        }
    }

    vector s(n, vector(n, 0LL));
    for (int i = 0; i <= k; ++i) {
        s[0][0] += dU[i][0];
    }

    auto down = [&](int x1, int y1, int x2, int y2) {
        assert(x2 - x1 == y2 - y1);
        if (x2 >= n) {
            y2 -= x2 - (n - 1);
            if (y2 >= n or y2 < 0) return 0;
            x2 = n - 1;
        }
        if (y2 >= n) {
            x2 -= y2 - (n - 1);
            if (x2 >= n or x2 < 0) return 0;
            y2 = n - 1;
        }
        if (x1 <= 0) {
            y1 -= x1;
            if (y1 >= n or y1 < 0) return 0;
            x1 = 0;
        }
        if (y1 <= 0) {
            x1 -= y1;
            if (x1 >= n or x1 < 0) return 0;
            y1 = 0;
        }
        if (x1 <= x2 and y1 <= y2) {
            return dD[x2][y2] - (x1 > 0 ? dD[x1-1][y1-1] : 0);
        } else {
            return 0;
        }
    };

    auto remDU = [&](int x1, int y1, int x2, int y2) {
        if (x2 >= n) {
            y2 += x2 - (n - 1);
            if (y2 >= n or y2 < 0) {
                return 0;
            }
            x2 = n - 1;
        }
        if (y2 >= n) {
            x2 += y2 - (n - 1);
            if (x2 >= n or x2 < 0) {
                return 0;
            }
            y2 = n - 1;
        }
        if (x1 <= 0) {
            y1 -= x1;
            if (y1 >= n or y1 < 0) {
                return 0;
            }
            x1 = 0;
        }
        if (y1 <= 0) {
            x1 -= y1;
            if (x1 >= n or x1 < 0) {
                return 0;
            }
            y1 = 0;
        }
        return dU[x2][y2] - (x1 > 0 ? dU[x1-1][y1+1] : 0);
    };

    // First column
    for (int j = 1; j < n; ++j) {
        s[0][j] = s[0][j-1];

        // Subtract the top row

    }

    return 0;
}
