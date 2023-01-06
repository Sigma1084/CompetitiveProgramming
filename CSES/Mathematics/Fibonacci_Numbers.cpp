#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

const int MOD = 1e9 + 7;

map<ll, ll> f;

ll fib(ll n) {
    if (f.find(n) == f.end()) {
        int i = n/2;
        f[n] = (fib(i+1) * fib(n-i)) % MOD;
        f[n] += (fib(i) * fib(n-i-1)) % MOD;
        f[n] %= MOD;
    }
    return f[n];
}

void solve() {
    ll n; cin >> n;
    f[0] = 0, f[1] = 1, f[2] = 1;
    auto x = fib(n);
    cout << x;
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

