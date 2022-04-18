#include <bits/stdc++.h>
using namespace std;

typedef unsigned long int ul;
typedef long long int ll;
typedef unsigned long long int ull;
typedef vector<int> vi;
typedef vector<long long int> vll;
typedef pair<int, int> pii;

#define MOD 998244353
#define pb push_back

void solve() {
    int n;
    cin >> n;

    // Code starts here
    if (n%2 == 1) {
        cout << 0;
        return;
    }

    // We need (n/2)! ^ 2
    ll ans = 1;
    for (int i=1; 2*i <= n; i++) {
        ans *= (ll)i * i;
        ans %= MOD;
    }

    cout << ans;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
        cout << "\n";
    }

    return 0;
}
