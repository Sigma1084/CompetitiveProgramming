#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MOD = 1e9 + 7;

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    int ans = 0;

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            char c; cin >> c;
            a[i][j] = c - '0';
            ans += a[i][j];
        }
    }

    if (ans == n*m) { cout << ans - 2; return; }
    for (int i = 0; i < n-1; i++) for (int j = 0; j < m-1; j++) {
        int cnt = a[i][j] + a[i][j+1] + a[i+1][j] + a[i+1][j+1];
        if (cnt <= 2) {
            cout << ans;
            return;
        }
    }
    
    cout << ans - 1;
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

