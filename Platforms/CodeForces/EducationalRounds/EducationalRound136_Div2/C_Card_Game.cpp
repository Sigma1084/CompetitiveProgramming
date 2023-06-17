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

ll comb(int n, int k) {
    ll ans = n;
    for (int i = 2; i <= k; i++) {
        ans *= (n-i+1);
        ans %= MOD;
        ans *= modInverse(i);
        ans %= MOD;
    }
    return ans;
}

vector<pair<ll, ll>> dp(61);

void compute() {
    dp[1] = {1, 0};  // Alex = 1, Bob = 0
    dp[2] = {3, 2};  // Alex = 3, Bob = 2
    for (int i = 3; i <= 60; i++) {
        // Alex has 2*n
        dp[i].first += comb(2*i-1, i);

        // Alex has 2*n - 1 and Bob has 2*n
        dp[i].second += dp[i-1].first;
        dp[i].first += dp[i-1].second;

        // Bob has both 2*n - 1 and 2*n
        dp[i].second += comb(2*i-2, i);

        dp[i].first %= MOD;
        dp[i].second %= MOD;
    }
}

void solve() {
    int n; cin >> n;
    cout << dp[n/2].first << " " << dp[n/2].second << " 1";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int t = 1;
    cin >> t;

    compute();

    for (int i=1; i<=t; i++) {
        // cout << "Case #" << i << ": ";
        solve(); cout << '\n';
    }
    return 0;
}

