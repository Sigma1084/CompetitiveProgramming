#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MOD = 1e9 + 7;

void solve() {
    int n, k; cin >> n >> k; k %= 4;
    if (k == 0) { cout << "NO\n"; return; }
    if (k == 2) {
        cout << "YES\n";
        for (int i = 1; i <= n; i += 2) {
            if (i % 4 == 1) {
                cout << i + 1 << ' ' << i << '\n';
            } else {
                cout << i << ' ' << i + 1 << '\n';
            }
        }
    } else {
        cout << "YES\n";
        for (int i = 1; i <= n; i += 2) {
            cout << i << ' ' << i + 1 << '\n';
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
        solve(); // cout << '\n';
    }
    return 0;
}

