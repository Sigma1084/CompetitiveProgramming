#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    array<array<int, 3>, 4> ps;
    for (auto &p: ps) {
        for (auto &x: p) {
            cin >> x;
        }
    }

    for (int i = 0; i < 3; ++i) {
        if (ps[0][i] > ps[2][i]) {
            swap(ps[0][i], ps[2][i]);
            swap(ps[1][i], ps[3][i]);
        }
        if (ps[2][i] >= ps[1][i]) {
            cout << "No\n";
            return 0;
        }
    }

    cout << "Yes\n";

    return 0;
}
