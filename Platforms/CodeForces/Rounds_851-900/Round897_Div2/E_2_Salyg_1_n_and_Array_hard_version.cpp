#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int query(int q) {
    cout << "? " << q << endl;
    int res; cin >> res;
    return res;
}

void solve() {
    int n, k; cin >> n >> k;

    int i = n - k + 1, ans = 0;
    while (i >= k) {
        ans ^= query(i);
        i -= k;
    }

    // Now, we have i in [k, 2k)
    int t = i / 2;
    ans ^= query(1) ^ query(t + 1) ^ query(i);

    cout << "! " << ans << endl;
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
