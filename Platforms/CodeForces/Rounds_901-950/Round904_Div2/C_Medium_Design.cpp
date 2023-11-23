#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<array<int, 2>> a(n);
    for (auto &[l, r]: a) {
        cin >> l >> r;
    }

    set<array<int, 3>> s;
    for (auto [l, r]: a) {
        s.insert({l, 0, r});  // 0 means left
        s.insert({r, 1, l});  // 1 means right
    }

    int curInt = 0;
    int ans = 0;
    int valAt1 = 0, valAtM = 0;

    for (auto [x, t, y]: s) {
        int l, r;
        if (t == 0) {
            tie(l, r) = make_pair(x, y);
            t = 1;
        } else if (t == 1) {
            tie(l, r) = make_pair(y, x);
            t = -1;
        }
        curInt += t;
        if (l == 1) {
            valAt1 += t;
        }
        if (r == m) {
            valAtM += t;
        }
        int cur = curInt - min(valAt1, valAtM);
        ans = max(ans, cur);
    }

    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    for (int i = 1; i <= t; ++i) {
        solve();
        cout << '\n';
    }

    return 0;
}
