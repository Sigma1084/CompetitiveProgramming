#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;

    vector a(n, vector(m, 0));
    for (auto &r: a) {
        for (auto &x: r) {
            cin >> x;
            --x;
        }
    }

    vector b(n, vector(m, 0));
    for (auto &r: b) {
        for (auto &x: r) {
            cin >> x;
            --x;
        }
    }

    // Make the first column equal
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] == b[0][0]) {
                // Swap the j-th column with the 0th
                for (int k = 0; k < n; ++k) {
                    swap(a[k][j], a[k][0]);
                }
                break;
            }
        }
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    vector colsA(m, vector(n, 0)), colsB(m, vector(n, 0));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            colsA[i][j] = a[j][i];
            colsB[i][j] = b[j][i];
        }
    }
    sort(colsA.begin(), colsA.end());
    sort(colsB.begin(), colsB.end());

    if (colsA == colsB) {
        cout << "YES";
    } else {
        cout << "NO";
    }
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
