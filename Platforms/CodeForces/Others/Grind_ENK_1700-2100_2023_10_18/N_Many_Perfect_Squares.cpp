#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/**
 * a + x = p^2 and b + x = q^2
 * => p^2 - q^2 = b - a
 * => (p + q)(p - q) = b - a
 * 
 * (p + q)(p - q) = f * f' where f' > f
 * p + q = f' AND p - q = f
 * => p = (f + f') / 2 AND q = (f' - f) / 2
 */
void solve() {
    int n; cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    map<ll, int> xs;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            int d = a[i] - a[j];  // b - a
            for (int f = 1; f * f <= d; ++f) {
                if (d % f) continue;
                int f2 = d / f;
                if (f2 % 2 != f % 2) continue;
    
                // We can solve for p and q
                int p = (f2 + f) / 2;
                int q = (f2 - f) / 2;
                if (1LL * p * p - a[i] >= 0) {
                    xs[1LL * p * p - a[i]] += 1;
                }
            }
        }
    }

    int ans = 1;
    for (auto &[x, cur]: xs) {
        cur = int(sqrt(2 * cur) + 1);
        ans = max(ans, cur);
    }

    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    for (int i = 1; i <= t; ++i) {
        solve();
        cout << '\n';
    }

    return 0;
}
