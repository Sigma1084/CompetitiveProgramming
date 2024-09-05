#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<vector<int>> a(n, vector<int>(n));
    for (auto &x: a) {
        for (auto &y: x) {
            cin >> y;
        }
    }

    vector<int> rs(n), cs(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            rs[i] += a[i][j];
            cs[j] += a[i][j];
        }
    }

    // for (auto x: rs) {
    //     cerr << x << ' ';
    // }
    // cerr << '\n';

    // for (auto x: cs) {
    //     cerr << x << ' ';
    // }
    // cerr << '\n';

    int p1 = -1, p2 = -1;
    for (int i = 0; i < n; ++i) {
        if (rs[i] != cs[i]) {
            if (p1 == -1) {
                p1 = i;
            } else if (p2 == -1) {
                p2 = i;
            } else {
                cout << "NO";
                return;
            }
        }
    }

    if (p1 == -1) {
        cout << "YES\n";
        cout << "1 1\n" << a[0][0];
        return;
    } else if (p2 == -1) {
        cout << "NO";
        return;
    }

    auto rs0 = rs, cs0 = cs;
    if (rs[p1] < cs[p1]) {
        // Adding to a[i][j]
        rs[p1] += cs0[p1] - rs0[p1];
        cs[p2] += cs0[p1] - rs0[p1];
        if (rs[p2] == cs[p2]) {
            cout << "YES\n";
            cout << p1 + 1 << ' ' << p2 + 1 << '\n';
            cout << cs0[p1] - rs0[p1] + a[p1][p2];
            return;
        }
    } else {
        // Adding to a[j][i]
        cs[p1] += rs0[p1] - cs0[p1];
        rs[p2] += rs0[p1] - cs0[p1];
        if (rs[p2] == cs[p2]) {
            cout << "YES\n";
            cout << p2 + 1 << ' ' << p1 + 1 << '\n';
            cout << rs0[p1] - cs0[p1] + a[p2][p1];
            return;
        }
    }

    cout << "NO";
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
