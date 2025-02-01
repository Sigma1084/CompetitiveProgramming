#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    array<array<int, 4>, 4> a;
    for (auto &x: a) {
        for (auto &y: x) {
            cin >> y;
        }
    }

    for (int i = 0; i < 4; ++i) {
        if (a[i][3] and (a[i][0] or a[i][1] or a[i][2])) {
            cout << "YES";
            return 0;
        }
    }

    for (int i = 0; i < 4; ++i) {
        if (a[i][3]) {
            for (int j = 1; j <= 3; ++j) {
                if (a[(i + 4 - j) % 4][(3 + 4 - j) % 4]) {
                    cout << "YES";
                    return 0;
                }
            }
        }
    }

    cout << "NO";

    return 0;
}
