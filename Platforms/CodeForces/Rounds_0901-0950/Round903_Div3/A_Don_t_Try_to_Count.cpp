#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;

    string s, t;
    cin >> s >> t;

    for (int ans = 0; ans < 25; ++ans) {
        for (int i = 0; i + t.size() <= s.size(); ++i) {
            if (s.substr(i, t.size()) == t) {
                cout << ans;
                return;
            }
        }
        s += s;
        if (ans > 1 and s.size() > 2 * t.size()) {
            break;
        }
    }

    cout << -1;
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
