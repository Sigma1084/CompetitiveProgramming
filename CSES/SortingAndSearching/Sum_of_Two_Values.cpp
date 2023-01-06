#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, x; cin >> n >> x;
    vector<int> b(n); for (auto &x: b) cin >> x;
    vector<int> a = b;
    sort(a.begin(), a.end());

    int s = 0, e = n-1;
    while(s < e) {
        int sm = a[s] + a[e];
        if (sm == x) break;
        if (sm < x) s++;
        else e--;
    }

    if (s < e) {
        auto x = find(b.begin(), b.end(), a[s]);
        auto y = x;
        if (a[s] == a[e]) y = find(next(x), b.end(), a[e]);
        else y = find(b.begin(), b.end(), a[e]);
        cout << (x - b.begin() + 1) << ' ' << (y - b.begin() + 1);
    } else {
        cout << "IMPOSSIBLE";
    }
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
