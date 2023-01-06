#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MOD = 1e9 + 7;

void solve() {
    int n, m; cin >> n >> m;
    string ans[] = {"", "Burenka", "Tonya"};
    if (n == m) {
        cout << ans[2];
        return;
    }
    int x = abs(n - m);
    // For 3, 2
    // (3, 2) --> (2, 2) Player 1 wins
    if (x % 2 == 0) cout << ans[2];
    else cout << ans[1];
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

