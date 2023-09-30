#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<string> a(n);
    for (auto &s: a) {
        cin >> s;
    }

    int i1 = n, i2 = 0, j1 = m, j2 = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 'W') continue;
            i1 = min(i1, i);
            i2 = max(i2, i);
            j1 = min(j1, j);
            j2 = max(j2, j);
        }
    }

    cout << (i1 + i2) / 2 + 1 << ' ' << (j1 + j2) / 2 + 1 << std::endl;

    return 0;
}
