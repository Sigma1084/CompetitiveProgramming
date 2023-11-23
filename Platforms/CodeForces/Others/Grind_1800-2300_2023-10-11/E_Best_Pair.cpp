#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;

    map<int, int> cnt;
    for (int i = 0, x; i < n; ++i) {
        cin >> x;
        cnt[x] += 1;
    }

    set<pair<int, int>> bad;
    for (int i = 0, x, y; i < m; ++i) {
        cin >> x >> y;
        bad.emplace(x, y);
    }

    // x and y are elements
    auto isFine = [&bad] (int x, int y) {
        return bad.find(minmax(x, y)) == bad.end();
    };

    /**
     * Maximum number of cnts will be \sqrt(n)
     */
    vector<vector<int>> v(n + 1);  // v[c] = {x | cnt[x] = c}
    vector<int> a;  // Possible counts
    for (auto [x, c]: cnt) {
        if (v[c].empty()) {
            a.push_back(c);
        }
        v[c].push_back(x);
    }

    // Have the elements in reverse order
    for (auto &v1: v) {
        reverse(v1.begin(), v1.end());
    }

    ll ans = 0;
    for (int c1: a) {
        for (int c2: a) {
            for (int x: v[c1]) {
                for (int y: v[c2]) {
                    if (c2 == c1 and x == y) {
                        // Avoid double counting
                        break;
                    }
                    if (isFine(x, y)) {
                        ans = max(ans, 1LL * (x + y) * (c1 + c2));
                        break;
                    }
                }
                if (c2 != c1 and isFine(x, v[c2].front())) {
                    break;
                }
            }
            if (c1 == c2) {
                // Aviod double counting
                break;
            }
        }
    }

    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    while (t--) {
        solve();
        cout << '\n';
    }

    return 0;
}
