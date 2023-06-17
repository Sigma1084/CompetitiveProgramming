#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MOD = 1e9 + 7;

const int N = 102;
int dp[N][N][2][2];

// dp[numEven, numOdd, required, p0/p1]
int dpp(int nE, int nO, int r, int p) {
    if (nE < 0 or nO < 0) return 1-p;
    int &ans = dp[nE][nO][r][p];
    if (ans != -1) return ans;
    if (p == 0) ans = dpp(nE-1, nO, r, 1) or dpp(nE, nO-1, 1-r, 1);
    else ans = dpp(nE-1, nO, r, 0) and dpp(nE, nO-1, r, 0);
    return ans;
}

void solve() {
    int n; cin >> n;
    int nE = 0, nO = 0, x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x % 2 == 1) nO++;
        else nE++;
    }

    cout << (dpp(nE, nO, 0, 0) ? "Alice" : "Bob");
    
    // for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) {
    //         cout << i << ' ' << j << ": " << dp[i][j][0][0] << ' '
    //              << dp[i][j][0][1] << ' ' << dp[i][j][1][0] << ' '
    //              << dp[i][j][1][1] << '\n';
    //     }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    memset(dp, -1, sizeof(dp));
    dp[0][0][0][0] = dp[0][0][0][1] = 1;
    dp[0][0][1][0] = dp[0][0][1][1] = 0;

    int t = 1;
    cin >> t;

    for (int i=1; i<=t; i++) {
        // cout << "Case #" << i << ": ";
        solve(); cout << '\n';
    }
    return 0;
}

