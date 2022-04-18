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
    ll n, h;
    cin >> n >> h;

    ll a[n];
    for (ll i=0; i<n; i++)
        cin >> a[i];

    // Code starts here

    // The number of damage dealt will be
    // damage(k) is O(n)
    auto damage = [&](ll k) -> ll {
        ll ans = k;
        for (ll i=0; i<n-1; i++)
            ans += min(a[i+1] - a[i], k);
        return ans;
    };

    // Bisection
    if (n >= h) {
        cout << 1;
        return;
    }

    ll low, mid, high = 2;

    // Determining Upper Bound, must take O(nlogh)
    while (damage(high) < h)
        high *= 2;
    low = high/2 + 1;

    // Must be over in O(nlogh)
    // Iterate till low becomes high-1
    while (low <= high) {
        mid = (low+high)/2;
        if (damage(mid) < h)
            low = mid + 1;
        else
            high = mid - 1;
    }

    cout << low;
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
