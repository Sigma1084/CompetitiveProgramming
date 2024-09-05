#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool isCol(int x1, int x2, int y1, int y2) {
    return 1LL * x1 * y2 == 1LL * x2 * y1;
}

void solve() {
    int n;
    cin >> n;

    vector<array<int, 4>> a(n);
    for (auto &[v, x, y, _]: a) {
        cin >> x >> y >> v;
    }
    for (int i = 0; i < n; ++i) {
        a[i][3] = i + 1;
    }
    sort(a.begin(), a.end());

    int i = 0;
    for (; i + 1 < n; ++i) {
        if (a[i][0] == a[i+1][0]) {
            break;
        }
    }

    if (i + 1 == n) {
        cout << -1;
        return;
    }

    for (int j = 0; j < n; ++j) {
        if (j == i or j == i + 1) {
            continue;
        }
        if (isCol(a[i][1] - a[j][1], a[i+1][1] - a[j][1],
                a[i][2] - a[j][2], a[i+1][2] - a[j][2]))
        {
            continue;
        }
        cout << 3 << '\n';
        cout << a[i][3] << ' ' << a[i+1][3] << ' ' << a[j][3];
        return;
    }

    cout << -1;
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
