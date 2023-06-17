#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MOD = 998244353;

// a ^ b (mod MOD)
ll modPow(ll a, ll b) {
  if (b == 0) return 1;
  ll x = modPow(a, b/2) % MOD;
  x = (x * x) % MOD;
  return (x * (b%2 ? a : 1)) % MOD;
}

// Using Fermat's Little Theorem, (only works for prime MOD)
ll modInverse(ll a) {
  return modPow(a, MOD-2);
}

void solve() {
    int n, m;
    cin >> n >> m;
    
    // n is odd
    if (n % 2 == 1) {
        cout << 1;
        return;
    }

    // m is even
    // if (m % 2 == 0) {
    //     cout << modInverse(2);
    //     return;
    // }

    // n Even, m Odd
    ll pS = 0;
    ll num = 0;

    for (int r = 1; r <= m; r += 2)  {
        pS += modPow(r, n/2 - 1); pS %= MOD;
        num += (modPow(m+1-r, n/2 - 1) * pS) % MOD;
        num %= MOD;
    }

    pS = 0;
    for (int r = 2; r <= m; r += 2) {
        pS += modPow(r, n/2 - 1); pS %= MOD;
        num += (modPow(m+1-r, n/2 - 1) * pS) % MOD;
        num %= MOD;
    }

    ll den = modPow(m, n);
    ll ans = (num * modInverse(den)) % MOD;
    // ans %= MOD;

    cout << num << ' ' << den << '\n';

    cout << ans;
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

