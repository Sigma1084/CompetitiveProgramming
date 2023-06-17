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

void solve() {
    ll n, k;
    cin >> n >> k;

    ll a[n];
    for (int i=0; i<n; i++)
        cin >> a[i];

    // Code starts here
    ll num = 0;
    ll scale = 1;
    ll rem = k+1;
    
    auto tenPow = [&](int d) -> ll {
        ll ans = 1;
        for (int i=0; i<d; i++)
            ans *= 10;
        return ans;
    };

    for (int i=0; rem > 0 && i<n-1; i++) {
        ll temp = min(tenPow(a[i+1] - a[i]) - 1, rem);
        num += temp * tenPow(a[i]);
        rem -= temp;
    }

    num += rem * tenPow(a[n-1]);
    cout << num;
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
