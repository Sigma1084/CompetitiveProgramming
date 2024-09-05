#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    freopen("paintbarn.in", "r", stdin);
    freopen("paintbarn.out", "w", stdout);

    int n, k;
    cin >> n >> k;

    constexpr int N = 1000;
    vector a(N + 1, vector<int>(N));

    for (int i = 0; i < n; ++i) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        a[x1][y1]++;
        a[x1][y2]--;
        a[x2][y1]--;
        a[x2][y2]++;
    }

    for (int i = 1; i < N; ++i) {
        a[i][0] += a[i - 1][0];
        a[0][i] += a[0][i - 1];
    }
    for (int i = 1; i < N; ++i) {
        for (int j = 1; j < N; ++j) {
            a[i][j] += a[i-1][j] + a[i][j-1] - a[i-1][j-1];
        }
    }

    int ans = 0;
    for (const auto &r: a) {
        for (auto x: r) {
            ans += x == k;
        }
    }

    cout << ans << '\n';

    return 0;
}
