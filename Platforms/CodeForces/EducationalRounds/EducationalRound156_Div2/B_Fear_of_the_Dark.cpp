#include <bits/stdc++.h>
using namespace std;
using ll = long long;

double dist(array<int, 2> a, array<int, 2> b) {
    return hypot(a[0] - b[0], a[1] - b[1]);
}

void solve() {
    array<int, 2> p, a, b, z;
    z = {0, 0};
    cin >> p[0] >> p[1];
    cin >> a[0] >> a[1];
    cin >> b[0] >> b[1];

    // One possibility is to use a single one
    double ans = max(dist(z, a), dist(p, a));
    ans = min(ans, max(dist(z, b), dist(p, b)));

    // Another is to join them and connect a to z and b to p
    double r = dist(a, b) / 2;

    // a to z and b to p
    ans = min(ans, max({r, dist(z, a), dist(p, b)}));

    // a to p and b to z
    ans = min(ans, max({r, dist(z, b), dist(p, a)}));

    cout << fixed << setprecision(10) << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    while (t--) {
        solve();
        cout << '\n';
    }

    return 0;
}
