#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;

    vector<int> a(n);
    string s; cin >> s;

    auto apply = [] (int n) {
        return (n + 1) / 3;
    };

    int f = count(s.begin(), s.end(), 'R');
    if (f == 0 or f == n) {
        cout << apply(n - 2) + 1 << '\n';
        return;
    }

    if (s.front() == 'L' and s.back() == 'R') {
        // We are good
    } else {
        int k = 0;
        for (; k + 1 < n; k++) {
            if (s[k] == 'R' and s[k + 1] == 'L') {
                break;
            }
        }
        rotate(s.begin(), s.begin() + k + 1, s.end());
    }

    int ans = 0, l = 0, r = 0;
    for (int i = 1; i + 1 < n; ++i) {
        if (s[i] == 'R') {
            r += 1;
            ans += apply(l);
            l = 0;
        } else if (s[i] == 'L') {
            l += 1 - int(r > 0);
            ans += apply(r - 1);
            r = 0;
        } else {
            assert(false);
        }
    }

    ans += apply(l) + apply(r);

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
