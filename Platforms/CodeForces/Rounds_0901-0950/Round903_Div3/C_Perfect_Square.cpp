#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;

    vector<string> board(n);
    for (auto &line: board) {
        cin >> line;
    }

    int ans = 0;
    for (int l = 0; 2 * l < n; ++l) {
        for (int t = 0; 2 * t < n; ++t) {
            map<char, int> cnt;

            for (int i = 0; i < 4; ++i) {
                tie(l, t) = make_pair(t, n - 1 - l);
                cnt[board[l][t]]++;
            }

            int fin = 0;
            int req = cnt.rbegin()->first;
            for (auto &[k, v]: cnt) {
                fin += v * (req - k);
            }
            ans += fin;
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
