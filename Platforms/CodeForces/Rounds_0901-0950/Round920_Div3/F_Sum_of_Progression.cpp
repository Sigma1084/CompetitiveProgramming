#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, nQ;
    cin >> n >> nQ;

    vector<int> a(n);
    for (auto &x: a) cin >> x;

    int sq = sqrt(n);
    vector<vector<ll>> p0(sq + 1, vector<ll>(n));
    vector<vector<ll>> p1(sq + 1, vector<ll>(n));
    for (int d = 1; d <= sq; ++d) {
        for (int i = 0; i < d; ++i) {
            p0[d][i] = a[i];
            p1[d][i] = a[i];
        }
        for (int i = d; i < n; ++i) {
            p0[d][i] = p0[d][i - d] + a[i];
            p1[d][i] = p1[d][i - d] + 1LL * (i/d + 1) * a[i];
        }

        // cerr << "d = " << d << '\n';
        // cerr << "p0: ";
        // for (auto x: p0[d]) cerr << x << ' ';
        // cerr << '\n';
        // cerr << "p1: ";
        // for (auto x: p1[d]) cerr << x << ' ';
        // cerr << '\n';
    }

    for (int s, d, k; nQ--; ) {
        cin >> s >> d >> k;
        --s;
        if (d > sq) {
            ll ans = 0;
            for (int i = s, j = 1; j <= k; i += d, ++j) {
                ans += 1LL * j * a[i];
            }
            cout << ans << ' ';
        } else {
            // We need to p1 - (numBef) * p0
            ll ans = p1[d][s + d*(k-1)], sub = p0[d][s + d*(k-1)];
            if (s > d) {
                ans -= p1[d][s - d];
                sub -= p0[d][s - d];
            }
            ans -= sub * (s/d);
            cout << ans << ' ';
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;

    for (int i = 1; i <= t; ++i) {
        solve();
        std::cout << '\n';
    }

    return 0;
}
