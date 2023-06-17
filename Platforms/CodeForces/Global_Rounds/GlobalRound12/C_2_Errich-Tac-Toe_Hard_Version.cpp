#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<string> a(n); for (auto &x: a) cin >> x;

    int x = 0; for (auto &s: a) for (auto &c: s) if (c == 'X') x++;
    int o = 0; for (auto &s: a) for (auto &c: s) if (c == 'O') o++;

    bool ok = false;
    for (int d1=0; d1<3 and not ok; d1++) for (int d2=0; d2<3; d2++) {
        if (d1 == d2) continue;
        int y = 0;
        auto b = a;
        for (int i=0; i<n; i++) for (int j=0; j<n; j++) if ((i+j) % 3 == d1) {
            if (b[i][j] == 'X') b[i][j] = 'O', y++;
        }
        for (int i=0; i<n; i++) for (int j=0; j<n; j++) if ((i+j) % 3 == d2) {
            if (b[i][j] == 'O') b[i][j] = 'X', y++;
        }
        if (y <= (x+o)/3) {
            for (auto &s: b) cout << s << '\n';
            ok = true;
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
