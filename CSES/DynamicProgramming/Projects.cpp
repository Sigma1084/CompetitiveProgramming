#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef vector<int> vi;

void solve() {
    int n; cin >> n;
    vector<vi> a(n, vi(3));
    for (auto &i: a) cin >> i[0] >> i[1] >> i[2];
    sort(a.begin(), a.end(), [] (vi &x, vi &y) { return x[1] <= y[1]; } );

    // map<int, ll> dp; dp[0] = 0;
    // dp[1] = 4;
    // dp[3] = 8;
    // dp[4] = 3;
    // dp[5] = 9;
    // auto x = dp.lower_bound(4);
    // cout << x->first << ' ' << x->second;

    vector<int> b = {1, 2, 2, 2, 2, 3, 4, 5, 8};
    cout << lower_bound(b.begin(), b.end(), 2) - b.begin() << '\n';
    cout << upper_bound(b.begin(), b.end(), 2) - b.begin() << '\n';
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
