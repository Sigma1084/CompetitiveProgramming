#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int &x : a) cin >> x;

    map<int, int> f;
    for (int x : a) f[x]++;

    int M = 0;
    while (f.find(M) != f.end()) M++;

    // dp[i] := Answer assuming that the MEX right now is i
    vector<ll> dp(M + 1, 1e18);
    dp[0] = 0;
    for (int i = 1; i <= M; ++i) {
        // Assuming the array is {0, 0, ..., i - 1, i - 1}
        for (int j = 0; j < i; ++j) {
            // We remove all the js now
            dp[i] = min(dp[i], 1LL * i * (f[j] - 1) + j + dp[j]);
        }
    }

    cout << dp[M];
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
