#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<string> a(n); for (auto &x: a) cin >> x;

    int x = 0; for (auto &s: a) for (auto &c: s) if (c == 'X') x++;

    for (int d=0; d<3; d++) {
        int y = 0;
        auto b = a;
        for (int i=0; i<n; i++) for (int j=0; j<n; j++) if ((i+j) % 3 == d) {
            if (b[i][j] == 'X') b[i][j] = 'O', y++;
        }
        if (y <= x/3) {
            for (auto &s: b) cout << s << '\n';
            break;
        }
    }
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
