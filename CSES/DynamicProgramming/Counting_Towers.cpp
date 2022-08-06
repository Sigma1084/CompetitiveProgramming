#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MOD = 1e9 + 7;

const int N = 1e6 + 2;
vector<ll> dp1(N);
vector<ll> dp2(N);

void update() {
    dp1[1] = 1; dp2[1] = 1;
    for (int i=2; i<N; i++) {
        dp1[i] = dp2[i-1] + 4 * dp1[i-1];
        dp2[i] = 2 * dp2[i-1] + dp1[i-1];
        dp1[i] %= MOD;
        dp2[i] %= MOD;
    }
}

void solve() {
    int n; cin >> n;
    cout << (dp1[n] + dp2[n]) % MOD;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int t = 1;
    cin >> t;
    update();

    for (int i=1; i<=t; i++) {
        // cout << "Case #" << i << ": ";
        solve(); cout << '\n';
    }

    return 0;
}
