#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, x; cin >> n >> x;
    vector<int> a(n); for (auto& x: a) cin >> x;
    sort(a.begin(), a.end());

    int ans = 0;
    int b = 0, e = n-1;
    while (b < e and e >= 0) {
        if (a[b] + a[e] <= x) b++, e--, ans++;
        else e--, ans++;
    }
    if (b == e) ans++;

    cout << ans;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int t = 1;
    // cin >> t;

    for (int i=1; i<=t; i++) {
        // cout << "Case #" << i << ": ";
        solve(); cout << '\n';
    }

    return 0;
}
