#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MOD = 1e9 + 7;

void solve() {
    int n; cin >> n;
    vector<int> d(n); for (auto &x: d) cin >> x;

    vector<int> a(n); a[0] = d[0];
    for (int i = 1; i < n; i++) {
        if (d[i] and a[i-1] - d[i] >= 0) {
            cout << "-1";
            return;
        }
        a[i] = a[i-1] + d[i];
    }

    for (auto &x: a) cout << x << " ";
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

