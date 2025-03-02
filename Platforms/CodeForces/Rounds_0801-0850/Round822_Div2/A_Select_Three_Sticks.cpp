#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MOD = 1e9 + 7;

void solve() {
    int n; cin >> n;
    vector<int> a(n); for (auto &x: a) cin >> x;

    sort(a.begin(), a.end());
    int ans = MOD;
    for (int i = 1; i+1 < n; i++) {
        ans = min(ans, a[i+1] - a[i-1]);
    }

    cout << ans;
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

