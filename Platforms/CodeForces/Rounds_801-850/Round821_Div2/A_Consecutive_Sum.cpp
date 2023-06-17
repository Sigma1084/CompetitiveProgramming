#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MOD = 1e9 + 7;

void solve() {
    int n, k; cin >> n >> k;
    vector<ll> a(n); for (auto &x: a) cin >> x;

    vector<ll> x(k);
    for (int i = 0; i < n; i++) {
        x[i%k] = max(x[i%k], a[i]);
    }

    // ll s = 0;
    // for (auto &i: x) s += i;
    // cout << s;

    cout << accumulate(x.begin(), x.end(), 0LL);
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

