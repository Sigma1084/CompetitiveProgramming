#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for (auto &x: a) {
        cin >> x;
    }
    for (auto &x: b) {
        cin >> x;
    }

    // Deal with the same ones first
    int sc1 = 0, sc2 = 0, sameNeg = 0, samePos = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] > b[i]) {
            sc1 += a[i] == 1;
        } else if (a[i] < b[i]) {
            sc2 += b[i] == 1;
        } else {
            if (a[i] == 1) {
                ++samePos;
            } else if (a[i] == -1) {
                ++sameNeg;
            }
        }
    }

    // We have some score now
    while (samePos--) {
        if (sc1 < sc2) {
            ++sc1;
        } else {
            ++sc2;
        }
    }
    while (sameNeg--) {
        if (sc1 < sc2) {
            --sc2;
        } else {
            --sc1;
        }
    }

    cout << min(sc1, sc2);
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
