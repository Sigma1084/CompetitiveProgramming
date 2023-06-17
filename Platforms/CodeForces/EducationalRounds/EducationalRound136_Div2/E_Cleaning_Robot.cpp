#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MOD = 1e9 + 7;

int n;
int dp[2][200005][2];  // [row][col][posChange]
string s[2];

int dpp(int r, int c, int p) {
    if (c > n) return 0;
    int &ans = dp[r][c][p];
    if (ans != -1) return ans;
    ans = dpp(r, c+1, 1);  // Can always go front
    if (p and s[1-r][c] == '1') ans = max(ans, 1 + dpp(1-r, c+1, 0));  // Down
    ans += (s[r][c] == '1');
    return ans;
}

void solve() {
    cin >> n >> s[0] >> s[1];
    memset(dp, -1, sizeof(dp));
    cout << dpp(0, 0, 1);
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

