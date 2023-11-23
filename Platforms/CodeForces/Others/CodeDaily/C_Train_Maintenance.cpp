#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    int m1 = static_cast<int>(sqrt(m));

    vector<pair<int, int>> a(n);
    for (auto &[x, y]: a) {
        cin >> x >> y;
    }

    vector<int> big(m);
    vector<vector<int>> small(m1 + 1);
    vector<int> start(n, -1);
    int ans = 0;

    for (int i = 1; i <= m1; ++i) {
        small[i].resize(i, 0);
    }

    for (int i = 0; i < m; ++i) {
        int t, k;
        cin >> t >> k;
        k--;

        if (t == 2) t = -1;
        if (t == 1) start[k] = i;

        int s = start[k];
        auto [x, y] = a[k];

        // Is the train already in maintainence?
        int cls = (i - start[k]) % (x + y) + 1;
        if (cls > x) {
            ans += t;
        }

        // Process the current one
        ans += big[i];
        for (cls = 2; cls <= m1; ++cls) {
            ans += small[cls][i % cls];
        }
        cout << ans << '\n';

        // How does the current one affect the future?
        if (x + y > m1) {
            for (int ss = s + x; ss < m; ss += x + y) {
                big[ss] += t;
            }
            for (int ss = s; ss < m; ss += x + y) {
                big[ss] -= t;
            }
        } else if (x + y <= m1) {
            // small[x+y] will be affected
            small[x + y][(s + x) % (x+y)] += t;
            small[x + y][s % (x+y)] -= t;
        } else {
            assert(false);
        }
    }

    return 0;
}
