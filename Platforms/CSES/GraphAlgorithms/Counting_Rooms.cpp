#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<string> b;
int ans = 0;

void perform(int i, int j, bool add=true) {
    if (i<0 or i>=n or j<0 or j>=m or b[i][j]!='.') return;
    b[i][j] = '_';
    ans += add;
    for (int x: {-1, 1}) {
        perform(i + x, j, false);
        perform(i, j + x, false);
    }
}

void solve() {
    cin >> n >> m; ans = 0;
    b = vector<string>(n); for (auto &i: b) cin >> i;
    for (int i=0; i<n; i++) for (int j=0; j<m; j++) perform(i, j);
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
