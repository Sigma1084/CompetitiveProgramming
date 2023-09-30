#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n), h(n);
    for (int &x: a) cin >> x;
    for (int &x: h) cin >> x;

    int ans = 0;
    for (int i = 0, j = 0, cur; j < n; ) {
        cur = 0;
        do {
            cur += a[j++];
            while (cur > k) {
                cur -= a[i++];
            }
            ans = max(ans, j - i);
        } while (j < n and h[j - 1] % h[j] == 0);
        i = j;
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
