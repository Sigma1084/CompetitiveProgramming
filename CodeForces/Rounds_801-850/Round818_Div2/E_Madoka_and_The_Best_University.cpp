#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MOD = 1e9 + 7;

void solve() {
    int n; cin >> n;

    auto brute = [&] () -> ll {
        ll ans = 0;
        for (int i = 1; i <= n-2; i++) {
            for (int j = 1; i+j <= n-1; j++) {
                int k = n - i -j;
                ans += lcm(i, gcd(j, k));
            }
        }
        return ans;
    };

    auto brute2 = [&] () -> ll {
        ll ans = 0;
        for (int i = 1; i <= n-2; i++) {
            for (int j = 1; i+j <= n-1; j++) {
                int k = n - i -j;
                ans += k*lcm(n, gcd(i, j));
            }
        }
        return ans/n;
    };

    for (n = 3; n <= 50; n++) {
        cout << n << ' ' << brute2() << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int t = 1;
    // cin >> t;

    for (int i=1; i<=t; i++) {
        // cout << "Case #" << i << ": ";
        solve(); cout << '\n';
    }
    return 0;
}

