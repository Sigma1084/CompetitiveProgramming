#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MOD = 1e9 + 7;
const ll INF = 1e18;

void add(vector<ll> &a, const vector<ll> &b) {
    // a += b (But in a good way :) )
    if (b[0] < a[0]) { a = b; }
    else if (a[0] == b[0]) { a[1] = (a[1] + b[1]) % MOD; }
}

void solve() {
    string s, t;
    cin >> s >> t;

    vector<int> occ;
    for (int i = 0; i + t.size() <= s.size(); i++) {
        bool ok = true;
        for (int j = 0; j < t.size(); j++) {
            if (s[i+j] != t[j]) {
                ok = false;
                break;
            }
        }
        if (ok) occ.push_back(i);
    }

    occ.push_back(s.size());

    vector<vector<ll>> dp[occ.size()];
    // [0] : { m, w } WO Removing
    // [1] : { m, w } W Removing
    dp[occ.size()-1] = {{0, 1}, {0, 0}};

    for (int i = occ.size()-2; i >= 0; i--) {
        // We have occ[i] gives starting index
        dp[i] = {{INF, 0}, {INF, 0}};
        int j;
        for (j = i + 1; occ[j] < occ[i] + t.size(); j++)
            add(dp[i][0], dp[j][1]);
        dp[i][1] = dp[j][0];
        add(dp[i][1], dp[j][1]);
        dp[i][1][0] += 1;
    }

    auto ans = dp[0][0];
    add(ans, dp[0][1]);

    cout << ans[0] << ' ' << ans[1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int t = 1;
    cin >> t;

    for (int i=1; i<=t; i++) {
        // cout << "Case #" << i << ": ";
        solve(); cout << '\n';
    }
    return 0;
}

