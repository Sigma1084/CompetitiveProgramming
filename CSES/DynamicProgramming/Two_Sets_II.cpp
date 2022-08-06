#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MOD = 1e9 + 7;

void solve() {
    int n; cin >> n;
    if (n % 4 == 1 or n % 4 == 2) {
        cout << 0;
        return;
    }

    /**
     * Return 0 if n%4 is 0 or 1 since it is not possible
     * Required Sum, rS = n*(n-1) / 4
     * 
     * Knapsack using DP
     * kdp[num_elements_from_beginning_used][adding_to_sum]
     */

    int rS = n * (n+1) / 4;
    vector<vector<ll>> kdp(n+1, vector<ll>(rS+1));
    for (int i=0; i<=n; i++) kdp[i][0] = 1;

    for (int i=1; i<=n; i++) {
        for (int s=1; s<=rS; s++) {
            kdp[i][s] += kdp[i-1][s];
            if (s - i >= 0) kdp[i][s] += kdp[i-1][s-i];
            kdp[i][s] %= MOD;
        }
    }

    cout << (((MOD+1) / 2) * kdp[n][rS]) % MOD;
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
