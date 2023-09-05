#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/**
 * For a given k
 * Least u can do is 1 + ... + k
 * n - (k * (k + 1) / 2) should be a multiple of k
 * n - k^2 / 2 - k / 2 should be a multiple of k
 * 
 * 
 * Suppose k is 2
 * n - 2 - 1 should be a multiple of 2 => n should be odd
 * 
 * k != 2
 * Suppose k is odd
 * n should be a multiple of k
 * k is odd => n = ak for some integer a
 * Take the least prime divisor not equal to 2
 * Call it p
 * 
 * Now, if n >= p*(p+1)/2 then done
 * 
 * Suppose k is even; k = 2k'
 * n - 2k'^2 - k' should be a multiple of 2k'
 * n - k' should be a multiple of 2k'
 * n - k' = 2ak'
 * n = k'(2a + 1)
 */
void solve() {
    ll n; cin >> n;

    ll k = 1, o = n;
    while ((o & 1) == 0) {
        o >>= 1;
        k <<= 1;
    }

    auto isPossible = [&] (ll x) {
        if (x > 2e9) return false;
        return n - x * (x + 1) / 2 >= 0;
    };

    if (isPossible(2 * k)) {
        cout << 2 * k;
    } else if (o != 1 and isPossible(o)) {
        cout << o;
    } else {
        cout << -1;
    }
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
