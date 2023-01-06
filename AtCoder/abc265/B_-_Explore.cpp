#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MOD = 1e9 + 7;

void solve() {
    int n, m; ll T;
    cin >> n >> m >> T;
    vector<int> a(n-1), b(n);
    for (auto &i: a) cin >> i;
    
    for (int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        b[x] = y;
    }

    bool ok = true;

    for (int i = 0; ok and i+1 < n; i++) {
        T -= a[i];
        if (T <= 0) ok = false;
        T += b[i+2];
    }

    if (ok) {
        cout << "Yes";
    } else {
        cout << "No";
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

