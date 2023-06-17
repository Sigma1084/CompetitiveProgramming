#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MOD = 1e9 + 7;
const int N = 2e1 + 2;

int dp[2][N];
int dp2[2][N][2];  // [row][col][other/not]
int n;
string s[2];

void eval(int r, int C) {
    if (dp[r][C] != -1)
        return;
    
    dp[r][C] = 0;
    
    for (int c = C+1; c-1 < n; c++) {
        if (c < n and s[r][c] == '1' and c and s[1-r][c-1] == '1') {
            // Conflict
            // Solve the later first
            eval(1-r, c-1);

            // Then mark the other one as worthless and check
            s[1-r][c+1] = '0';
            eval(r, c);

            // Demark it
            s[1-r][c-1] = '1';

            dp[r][C] += max(dp[r][c], dp[1-r][c+1]) + 1;
            return;
        } else if (c < n and s[r][c] == '1') {
            dp[r][C]++;
        } else if (c and s[1-r][c-1] == '1') {
            dp[r][C]++;
        }
    }
}

void solve() {
    cin >> n;
    string s1, s2; cin >> s1 >> s2;

    for (int i = 0; i < n; i++) {
        if (s1[i] == '1' or s2[i] == '1') {
            s[0].push_back(s1[i]);
            s[1].push_back(s2[i]);
        }
    }
    n = s[0].size();
    if (n == 0) {
        cout << 0;
        return;
    }

    // for (auto &v: dp)
    //     for (int i = 0; i < n; i++)
    //         v[i] = -1;

    // eval(0, 0);
    // cout << dp[0][0];

    
    dp2[0][n-1][0] = (s[0][n-1] == '1');
    dp2[1][n-1][0] = (s[1][n-1] == '1');
    dp2[0][n-1][1] = dp2[0][n-1][0] + dp2[1][n-1][0];
    dp2[1][n-1][1] = dp2[0][n-1][0] + dp2[1][n-1][0];

    for (int c = n-2; c >= 0; c--) {
        for (int r = 0; r < 2; r++) {
            dp2[r][c][0] = dp2[r][c+1][1] + (s[r][c] == '1');
        }

        for (int r = 0; r < 2; r++) {
            dp2[r][c][1] = (s[r][c] == '1') + 
                max(dp2[r][c+1][1], dp2[1-r][c+1][0] + (s[1-r][c] == '1'));
        }
    }

    for (int i = 0; i < 2; i++) {
        for (int c = 0; c < n; c++) {
            cout << dp2[i][c][0] << ' ' << dp2[i][c][1] << "  ";
        }
        cout << "\n";
    }

    cout << dp2[0][0][1];
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

