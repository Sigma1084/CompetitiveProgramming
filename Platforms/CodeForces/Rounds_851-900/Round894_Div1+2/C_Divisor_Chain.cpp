#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int x; cin >> x;
    vector<int> ans = {x};

    for (int i = 0; (x & (-x)) != x; i++) {
        if (x & (1 << i)) {
            x -= (1 << i);
            ans.push_back(x);
        }
    }

    while (x != 1) {
        ans.push_back(x /= 2);
    }

    cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << ' ';
    }
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
