#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MOD = 1e9 + 7;

void solve() {
    int n, c; cin >> n >> c;
    vector<int> a(n); for (auto &x: a) cin >> x;

    map<int, int> m;
    for (auto &i: a) m[i]++;

    ll ans = 0;
    for (auto [i, f]: m) {
        ans += min(f, c);
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

