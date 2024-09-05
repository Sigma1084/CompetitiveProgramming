#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m, d;
    cin >> n >> m >> d;

    vector<int> p(m);
    for (auto &x: p) {
        cin >> x;
    }

    vector<array<int, 2>> pos(m);
    int cur = 0;
    for (int i = 0; i < m; ++i) {
        pos[i] = {cur, cur + p[i] - 1};
        cur += p[i];
    }

    cur = n;
    for (int i = m - 1; i >= 0; --i) {
        if (pos[i][1] + d >= cur) {
            cur = 0;
            break;
        }
        pos[i][1] = cur - d;
        pos[i][0] = pos[i][1] - p[i] + 1;
        cur = pos[i][0];
    }

    if (cur < d) {
        cout << "YES\n";
        vector<int> ans(n);
        for (int i = 0; i < m; ++i) {
            for (int j = pos[i][0]; j <= pos[i][1]; ++j) {
                ans[j] = i + 1;
            }
        }
        for (auto &x: ans) {
            cout << x << ' ';
        }
    } else {
        cout << "NO";
    }

    return 0;
}
