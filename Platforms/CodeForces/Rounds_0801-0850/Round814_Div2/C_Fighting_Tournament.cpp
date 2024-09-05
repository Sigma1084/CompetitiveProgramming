#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MOD = 1e9 + 7;

void solve() {
    int n, q; cin >> n >> q;
    vector<int> a(n); for (auto &x: a) cin >> x;
    vector<int> perm(n + 1); for (int i = 1; i <= n; i++) perm[i] = a[i-1];

    vector<int> win;
    int cur = a[0];
    for (int i = 1; i < n; i++) {
        cur = max(cur, a[i]);
        win.push_back(cur);
    }

    for (int _ = 0; _ < q; _++) {
        int p, r; cin >> p >> r; p = perm[p];
        auto ub = upper_bound(win.begin(), win.begin() + min(r, n-1), p);
        auto lb = lower_bound(win.begin(), win.begin() + min(r, n-1), p);
        cout << (ub - lb) + ((r>=n and p==n) ? (r-n+1) : 0) << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int t = 1;
    cin >> t;

    for (int i=1; i<=t; i++) {
        // cout << "Case #" << i << ": ";
        solve(); // cout << '\n';
    }
    return 0;
}

