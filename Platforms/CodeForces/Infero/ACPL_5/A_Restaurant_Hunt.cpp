#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<string> a(n);
    for (auto &x : a) {
        cin >> x;
    }

    int x = 0, y = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] == '*') {
                x ^= i + 1;
                y ^= j + 1;
            }
        }
    }

    cout << x << " " << y << "\n";

    return 0;
}
