#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MOD = 1e9 + 7;

void solve() {
    ll n, k, b, s;
    cin >> n >> k >> b >> s;

    ll mn = b*k;
    ll mx = b*k + n*(k-1);

    if (s < mn or s > mx) {
        cout << -1;
        return;
    }
    
    s -= b*k;
    if (s > k-1) {
        cout << b*k + (k-1) << ' ';
        s -= k-1;
    } else {
        cout << b*k + s << ' ';
        s = 0;
    }
    for (int i = 2; i <= n; i++) {
        ll temp = min(k-1, s);
        cout << temp << ' ';
        s -= temp;
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

