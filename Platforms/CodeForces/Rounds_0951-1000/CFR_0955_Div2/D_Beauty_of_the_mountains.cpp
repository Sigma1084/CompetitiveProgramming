#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    vector a(n, vector<int>(m));
    for (auto &r: a) {
        for (auto &x: r) {
            cin >> x;
        }
    }

    vector<string> s(n);
    for (auto &x: s) {
        cin >> x;
    }

    vector<vector<int>> sm0(n + 1, vector<int>(m + 1));
    vector<vector<int>> sm1(n + 1, vector<int>(m + 1));
    ll val = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            sm0[i+1][j+1] = sm0[i][j+1] + sm0[i+1][j] - sm0[i][j];
            sm1[i+1][j+1] = sm1[i][j+1] + sm1[i+1][j] - sm1[i][j];
            if (s[i][j] == '1') {
                sm1[i+1][j+1] += 1;
                val += a[i][j];
            } else {
                sm0[i+1][j+1] += 1;
                val -= a[i][j];
            }
        }
    }

    int g = 0;
    for (int i = 0; i + k <= n; ++i) {
        for (int j = 0; j + k <= m; ++j) {
            int c0 = sm0[i+k][j+k] - sm0[i][j+k] - sm0[i+k][j] + sm0[i][j];
            int c1 = sm1[i+k][j+k] - sm1[i][j+k] - sm1[i+k][j] + sm1[i][j];
            g = gcd(g, abs(c0 - c1));
        }
    }

    if (val == 0) {
        cout << "YES";
    } else if (g != 0 and abs(val) % g == 0) {
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
