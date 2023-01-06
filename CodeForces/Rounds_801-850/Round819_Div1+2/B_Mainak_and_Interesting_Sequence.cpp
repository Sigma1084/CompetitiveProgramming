#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MOD = 1e9 + 7;

void solve() {
    int n, m; cin >> n >> m;
    int q = m / n, r = m % n;

    if (q == 0) {
        cout << "NO";
    } else  if (r == 0) {
        cout << "YES\n";
        for (int i = 0; i < n; i++) cout << q << ' ';
    } else if ((n - r) % 2 == 0) {
        cout << "YES\n";
        for (int i = 0; i < n-r; i++) {
            cout << q << ' ';
        }
        for (int i = 0; i < r; i++) {
            cout << q + 1 << ' ';
        }
    } else if (r % 2 == 0) {
        cout << "YES\n";
        for (int i = 0; i < n-r+1; i++) {
            cout << q << ' ';
        }
        for (int i = 0; i < r-2; i++) {
            cout << q + 1 << ' ';
        }
        if (r == 0) cout << q;
        else cout << q + 2;
    } else {
        cout << "NO";
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

