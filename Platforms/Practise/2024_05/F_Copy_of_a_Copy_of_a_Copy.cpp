#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;
    ++k;

    vector bs(k, vector<string>(n));
    for (auto &b: bs) {
        for (auto &x: b) {
            cin >> x;
        }
    }

    vector<int> a(k);
    for (int i = 0; i < k; ++i) {
        for (int r = 1; r + 1 < n; ++r) {
            for (int c = 1; c + 1 < m; ++c) {
                // Check if surrounding cells are equal
                if (bs[i][r-1][c] != bs[i][r+1][c]) continue;
                if (bs[i][r][c-1] != bs[i][r][c+1]) continue;
                if (bs[i][r-1][c] != bs[i][r][c-1]) continue;

                // Check if surrounding cells are not equal to the center cell
                if (bs[i][r][c] == bs[i][r-1][c]) continue;
                a[i]++;
            }
        }
    }

    vector<int> o(k);
    iota(o.begin(), o.end(), 0);
    sort(o.begin(), o.end(), [&](int i, int j) {
        return a[i] > a[j];
    });
    // Gives us an ordering of the indices of the array

    auto comp = [&](const auto &b1, const auto &b2) -> vector<array<int, 2>> {
        vector<array<int, 2>> res;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (b1[i][j] != b2[i][j]) {
                    res.push_back({i, j});
                }
            }
        }
        return res;
    };

    cout << o[0] + 1 << '\n';

    vector<array<int, 3>> ops;
    for (int i = 1; i < k; ++i) {
        auto ch = comp(bs[o[i]], bs[o[i-1]]);
        for (auto [r, c]: ch) {
            ops.push_back({1, r+1, c+1});
        }
        ops.push_back({2, o[i] + 1, -1});
    }

    cout << ops.size() << '\n';
    for (auto [t, x, y]: ops) {
        cout << t;
        if (t == 1) {
            cout << ' ' << x << ' ' << y;
        } else {
            cout << ' ' << x;
        }
        cout << '\n';
    }

    return 0;
}
