#include <bits/stdc++.h>
using namespace std;

vector<int> dp;

void updateDP(int n) {
    if (n < 0) return;
    if (n == 0) { dp[0] = 0; return; }
    if (n == 1) { dp[0] = 1; dp[1] = 0; return; }
    int k = (int)ceil(sqrt(n));
    int req = k * k;
    for (int i = req-n; i <= n; i++) dp[i] = req-i;
    updateDP(req-n-1);
}

void solve() {
    int n; cin >> n; n;
    dp = vector<int>(n, 0);

    updateDP(n-1);
    for (auto &i: dp) cout << i << ' ';
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
