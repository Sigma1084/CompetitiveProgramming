#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<string> a(n);
    for (auto &s: a) {
        cin >> s;
    }

    vector<int> res(1 << n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] == 'o') {
                res[1 << i] |= 1 << j;
            }
        }
    }

    for (int i = 1; i < (1 << n); ++i) {
        int x = i & -i;
        res[i] = res[x] | res[i ^ x];
    }

    int ans = n;
    for (int i = 0; i < (1 << n); ++i) {
        if (res[i] == (1 << m) - 1) {
            ans = min(ans, __builtin_popcount(i));
        }
    }

    cout << ans << '\n';

    return 0;
}
