#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int &x: a) {
        cin >> x;
    }

    if (n <= 2) {
        cout << 0;
        return;
    } else if (n == 3) {
        cout << (a[0] == a[2]);
        return;
    } else if (n == 4) {
        if (a[0] == a[1] and a[1] == a[2] and a[2] == a[3] and a[3] == a[0]) {
            cout << 2;
        } else if (a[0] == a[3] and a[1] != a[0] and a[2] != a[0]) {
            cout << 0;
        } else {
            cout << 1;
        }
        return;
    }

    vector<array<int, 3>> cnts(n + 3, {0, 0, 0});
    for (int i = 0; i < n; ++i) {
        cnts[a[i]][i % 3] += 1;
    }

    int ans = n;
    for (int x = 1; x <= n + 2; ++x) {
        for (int y = 1; y <= n + 2; ++y) {
            for (int z = 1; z <= n + 2; ++z) {
                if (x == y or y == z or z == x) {
                    continue;
                }

                // 1-cycles
                int cur = n - cnts[x][0] - cnts[y][1] - cnts[z][2];

                // 2-cycles
                int xy = min(cnts[x][1], cnts[y][0]);
                int xz = min(cnts[x][2], cnts[z][0]);
                int yz = min(cnts[y][2], cnts[z][1]);
                cur -= (xy + yz + xz);

                // 3-cycles
                cur -= min({cnts[x][1] - xy, cnts[y][2] - yz, cnts[z][0] - xz});
                cur -= min({cnts[x][2] - xz, cnts[y][0] - xy, cnts[z][1] - yz});

                ans = min(ans, cur);
            }
        }
    }

    cout << ans;
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
