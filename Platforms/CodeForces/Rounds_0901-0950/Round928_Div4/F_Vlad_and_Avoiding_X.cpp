#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int N = 7;
array<string, N> b;

bool isValid(bool p) {
    for (int i = 0; i < N; ++i) {
        for (int j = p ^ (i % 2); j < N; j += 2) {
            if (i == 0 or i == N - 1 or j == 0 or j == N - 1) {
                continue;
            }
            if (b[i][j] == 'W') {
                continue;
            }
            int sc = 0;
            for (int dx: {-1, 1}) {
                for (int dy: {-1, 1}) {
                    sc += b[i + dx][j + dy] == b[i][j];
                }
            }
            if (sc == 4) {
                return false;
            }
        }
    }
    return true;
}

bool isPos(int k, bool p) {
    if (k == 0) {
        return isValid(p);
    }
    for (int i = 0; i < N; ++i) {
        for (int j = p ^ (i % 2); j < N; j += 2) {
            b[i][j] ^= 'A' ^ 'B';
            if (isPos(k - 1, p)) {
                return true;
            }
            b[i][j] ^= 'A' ^ 'B';
        }
    }
    return false;
}

void solve() {
    for (auto &r: b) {
        cin >> r;
    }

    array<int, 2> ans = {4, 4};
    for (int i = 0; i <= 3; ++i) {
        if (isPos(i, 0)) {
            ans[0] = i;
            break;
        }
    }
    for (int i = 0; i <= 3; ++i) {
        if (isPos(i, 1)) {
            ans[1] = i;
            break;
        }
    }

    cout << ans[0] + ans[1];
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
