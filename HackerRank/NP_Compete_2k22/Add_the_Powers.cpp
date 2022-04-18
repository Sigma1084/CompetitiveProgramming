#include <bits/stdc++.h>
using namespace std;

typedef unsigned long int ul;
typedef long long int ll;
typedef unsigned long long int ull;
typedef vector<int> vi;
typedef vector<long long int> vll;
typedef pair<int, int> pii;

#define MOD 1000000007
#define pb push_back

int phi(int n) {
    if (n == 1)
        return 0;
    int ans = 1;
    int mult;
    int curr;
    for (curr = 2; curr*curr <= n; curr++) {
        if (n%curr != 0)
            continue;

        // n divides curr
        mult = 1;
        while (n > 0 && n%curr == 0) {
            mult *= curr;
            n /= curr;
        }
        ans *= (mult - mult/curr);
    }
    // If n > 0 then it is some prime p
    if (n > 1)
        ans *= (n-1);

    return ans;
}

void solve() {
    int n, k, m;
    cin >> n >> k >> m;

    int p = phi(m);
    // We know that r^p = 1(mod m) for any r
    k = k % p;

    // r^k(mod m) can be calculated in O(log k)
    // Final answer in the form O(n log k)

    int rep = n / p;
    int rem = n % p;

    auto digits = [&](int n) -> int {
        int ans = 0;
        while (n > 0) {
            n /= 2;
            ans++;
        }
        return ans;
    };

    auto nPowK = [&](int n) -> int {
        if (n == 1)
            return 1;
        int digs = digits(n);
        ll curr = n;
        ll ans = 1;
        for (int i=0; i<digs; i++, n/=2) {
            if (n & 1)
                ans = (curr * ans) % m;
            curr = (curr * curr) % m;
        }
        return (int)ans;
    };

    ll ans = 0;
    for (int i=1; i<p; i++) {
        ll iPk = nPowK(i);
        ll temp = ((ll)(rep + (i<=rem)) * iPk) % m;
        ans = (ans + temp) % m;
    }

    cout << ans;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;

    while (t--) {
        solve();
        cout << "\n";
    }

    return 0;
}
