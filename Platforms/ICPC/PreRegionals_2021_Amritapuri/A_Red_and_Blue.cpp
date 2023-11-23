#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    vector<int> d(n);
    for (int &x: d) {
        cin >> x;
    }

    int maxR = -1, ans = 0;
    for (int i = 0, r = -1; i < n; ++i) {
        if (s[i] == 'B') {
            if (maxR < i) {
                cout << -1;
                return;
            }
            if (r < i) {
                ++ans;
                r = maxR;
            }
        }
        maxR = max(maxR, i + d[i]);
    }

    cout << ans;
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
