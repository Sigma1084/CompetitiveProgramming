#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MOD = 1e9 + 7;

void solve() {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;

    ll x = a*d, y = b*c;

    if (x == y) cout << 0;
    else if (x == 0 or y == 0 or x % y == 0 or y % x == 0) cout << 1;
    else cout << 2;
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

