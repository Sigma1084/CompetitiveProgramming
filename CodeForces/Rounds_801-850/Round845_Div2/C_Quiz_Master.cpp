#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
#define all(x) (x).begin(), (x).end()


void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(n); for (auto &x: a) cin >> x;
    sort(all(a));

    int l = 0, r = 0, count = 0, ans = 1e7;

    vector<int> f(m+1);
    while (l < n) {
        if (count == m) {
            ans = min(ans, a[r-1] - a[l]);
            for (int i = 1; i*i <= a[l]; i++) {
                if (a[l] % i) continue;
                if (i <= m) {
                    f[i]--;
                    if (not f[i]) count--;
                }
                if (a[l] / i <= m) {
                    f[a[l] / i]--;
                    if (not f[a[l] / i]) count--;
                }
            }
            l++;
            if (l > r) break;  // When we have encountered l = r once
        } else {
            if (r == n) break;
            for (int i = 1; i*i <= a[r]; i++) {
                if (a[r] % i) continue;
                if (i <= m) {
                    f[i]++;
                    if (f[i] == 1) count++;
                }
                if (a[r] / i <= m) {
                    f[a[r] / i]++;
                    if (f[a[r] / i] == 1) count++;
                }
            }
            r++;
        }
    }

    if (ans == 1e7) {
        cout << -1;
    } else {
        cout << ans;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;

    for (int i = 1; i <= t; i++) {
        solve(); cout << '\n';
    }
    return 0;
}
