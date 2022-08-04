#include <bits/stdc++.h>
using namespace std;
#define V vector
typedef long long int ll;

/**
 * @note Memory Limit Exceeded
 * 
 * In the last test case, the numberRequired was 10^6, m is 100
 * This forces the total memory required to be 60GB which is 
 * way more than the memory limit offered, that is 2GB 
 * 
 * Therefore, I decided to drop this idea and look for a better solution
 */

void solve() {
    int n, m; cin >> n >> m;
    V<int> a(n); for (auto &i: a) cin >> i;

    if (n == 1) {
        if (a[0] == 0) {
            cout << m; return;
        } else if (a[0] <= 0 or a[0] > m) {
            cout << 0; return;
        } else {
            cout << 1; return;
        }
    }

    int mR = 0; for (int x=0, i=1; i<n-1; i++) {
        if (a[i] == 0) x++;
        else x = 0;
        mR = max(mR, x);
    }
    cout << (mR+1) << ' ' << m+1 << ' ' << m+1 << endl;

   V<V<V<ll>>> dp(mR+1, V<V<ll>>(m+1, V<ll>(m+1, 0))); // dp[num_0][start][end]
   const int MOD = 1e9 + 7;

   for (int s=1; s<=m; s++) for (int e=max(1, s-1); e<=min(m, s+1); e++)
       dp[0][s][e] = 1;
   for(int z=1; z<=mR; z++) for(int l=1; l<=m; l++) for(int r=0; r<=m; r++)
       for (int s = max(0, l-1); s <= min(m, l+1); s++)
           dp[z][l][r] += dp[z-1][s][r], dp[z][l][r] %= MOD;


   ll ans = 1;
   int start = 0, end = 1;

   while (end < n and ans) {
       while (end < n and a[end] == 0) end++;
       // In 2 0 2, start = 0 and end = 2
       // If end = n, Implies a[n-1] = 0

       ll tempAns = 0;

       // Start and End are decided
       if (start == 0 and a[0] == 0 and end == n) {
           // Case with ALL zeroes
           for (int i=1; i<=m; i++) for (int j=1; j<=m; j++) {
               tempAns += dp[n-2][i][j];
               tempAns %= MOD;
           }
       } else if (end == n) {
           // Case ending with zeros
           for (int j=1; j<=m; j++) {
               tempAns += dp[n-start-2][a[start]][j];
           }
       } else if (start == 0 and a[0] == 0) {
           // Case when beginning is 0
           for (int i=1; i<=m; i++) {
               tempAns += dp[end-start-1][i][a[end]];
               tempAns %= MOD;
           }
       } else {
           // Any other case
           tempAns = dp[end-start-1][a[start]][a[end]];
       }

       ans *= tempAns;
       ans %= MOD;
       start = end;
       end++;
   }

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
