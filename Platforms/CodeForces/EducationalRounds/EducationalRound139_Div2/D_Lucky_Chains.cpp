#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MOD = 1e9 + 7;

/**
 * Length of the largest lucky chain
 * Find minimum k such that gcd(x+k, y+k) != 1
 * 
 * d | x+k and d | y+k
 * d | (y-x)
 * d is clearly the smallest prime factor of y-x
 */

const int N = 1e7 + 2;
int sPF[N];

void computeSmallestPrimeFact() {
    for (int i = 1; i < N; i++)
        sPF[i] = i;
    
    for (int i = 2; i*i < N; i++) {
        if (sPF[i] != i) continue;
        for (int j = i*i; j < N; j += i)
            sPF[j] = min(sPF[j], i);
    }
}

void solve() {
    int x, y; cin >> x >> y;
    
    if (__gcd(x, y) != 1) {
        cout << 0;
    } else if (x == y) {
        // Here x = y = 1
        cout << 1;
    } else if (y == x+1) {
        cout << -1;
    } else {
        int ans = INT_MAX;
        for (int d = y-x; d > 1; ) {
            int p = sPF[d];
            ans = min(ans, p - x % p);
            while (d % p == 0) d /= p;
        }
        cout << ans;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int t = 1;
    cin >> t;

    computeSmallestPrimeFact();
    for (int i=1; i<=t; i++) {
        // cout << "Case #" << i << ": ";
        solve(); cout << '\n';
    }
    return 0;
}
