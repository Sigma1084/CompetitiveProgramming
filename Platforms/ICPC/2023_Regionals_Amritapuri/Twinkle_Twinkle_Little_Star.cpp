#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, r, c;
    cin >> n >> r >> c;

    vector<vector<string>> b(n, vector<string>(r));
    for (auto &x : b) {
        int i;
        cin >> i;
        for (auto &y : x) {
            cin >> y;
        }
    }

    int p = 0, s = 0;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            int cnt = 0;
            for (const auto &g: b) {
                if (g[i][j] == '*') {
                    ++cnt;
                }
            }
            if (cnt == n) {
                ++p;
            } else if (cnt > 0) {
                ++s;
            }
        }
    }

    cout << p << ' ' << s;
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
