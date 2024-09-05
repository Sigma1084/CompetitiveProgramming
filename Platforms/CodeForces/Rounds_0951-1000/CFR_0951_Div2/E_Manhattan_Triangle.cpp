#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, d;
    cin >> n >> d;
    d /= 2;

    vector<array<int, 2>> xy(n);
    for (auto &[x, y] : xy) {
        cin >> x >> y;
    }

    int I = 0, J = 0, K = 0;
    auto work = [&]() {
        vector<array<int, 3>> a(n);
        for (int i = 0; i < n; ++i) {
            auto [x, y] = xy[i];
            a[i] = {x + y, x, i};
        }
        sort(a.begin(), a.end());

        vector<array<int, 4>> b;
        for (auto [s, x, i]: a) {
            auto it = lower_bound(a.begin(), a.end(), array{s, x + d, 0});
            if (it == a.end()) continue;
            auto [s1, x1, j] = *it;
            if (s1 == s and x1 == x + d) {
                b.push_back({s, x, i, j});
            }
        }

        for (auto [s, x, i]: a) {
            auto it = lower_bound(b.begin(), b.end(), array{s + 2*d, x, 0, 0});
            if (it != b.end()) {
                auto [s1, x1, j, k] = *it;
                if (s1 == s + 2*d and x1 <= x + d) {
                    I = i + 1;
                    J = j + 1;
                    K = k + 1;
                    return;
                }
            }
            it = lower_bound(b.begin(), b.end(), array{s - 2*d, x - 2*d, 0, 0});
            if (it != b.end()) {
                auto [s1, x1, j, k] = *it;
                if (s1 == s - 2*d and x1 <= x - d) {
                    I = i + 1;
                    J = j + 1;
                    K = k + 1;
                    return;
                }
            }
        }
    };

    work();
    if (I == 0) {
        for (auto &[x, y] : xy) {
            y = -y;
        }
        work();
    }

    cout << I << ' ' << J << ' ' << K;
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
