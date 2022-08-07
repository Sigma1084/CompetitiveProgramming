#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef vector<int> vi;

void solve() {
    int n; cin >> n;
    vector<vi> a(n, vi(3));
    for (auto &i: a) cin >> i[0] >> i[1] >> i[2], i[0]--;
    sort(a.begin(), a.end(), [] (vi &x, vi &y) { return x[1] <= y[1]; } );

    /**
     * @brief dp[ending_time]
     * 
     * Max Profit Before the Ending Time
     */

    map<int, ll> dp; dp[0] = 0;
    int s, e, m;
    for (int i=0; i<n; i++) {
        s = a[i][0], e = a[i][1], m = a[i][2];
        auto it = prev(dp.upper_bound(s));
        dp[e] = max(it->second + m, prev(dp.end())->second);
    }
    cout << prev(dp.end())->second;
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
