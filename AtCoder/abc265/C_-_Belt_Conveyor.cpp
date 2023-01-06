#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MOD = 1e9 + 7;

void solve() {
    int n, m; cin >> n >> m;

    vector<string> b(n); for (auto &s: b) cin >> s;

    vector<vector<bool>> vis(n, vector<bool>(m, false));
    int x = 0, y = 0;
    vis[0][0] = true;
    bool ok = true;

    while (ok) {
        int x1 = x, y1 = y;
        switch (b[x][y]) {
            case 'D': x1 += 1; break;
            case 'U': x1 -= 1; break;
            case 'L': y1 -= 1; break;
            case 'R': y1 += 1; break;
        }

        if (x1 < 0 or x1 >= n or y1 < 0 or y1 >= m) {
            break;
        } else if (vis[x1][y1]) {
            ok = false;
        } else {
            vis[x1][y1] = true;
            x = x1, y = y1;
        }
    }

    if (ok) {
        cout << x+1 << ' ' << y+1;
    } else {
        cout << -1;
    }
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

