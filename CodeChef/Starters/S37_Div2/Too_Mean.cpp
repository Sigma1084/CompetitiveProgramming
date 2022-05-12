#include <bits/stdc++.h>
using namespace std;

typedef unsigned long int ul;
typedef long long int ll;
typedef unsigned long long int ull;

typedef vector<int> vi;
typedef vector<long long int> vll;
typedef vector<bool> vb;

typedef vector<vi> vvi;
typedef vector<vll> vvll;

typedef pair<int, int> pii;

#define MOD 1000000007
#define PI 3.1415926535

#define pb push_back
#define prec fixed << setprecision

#define pY { cout << "YES"; return; }
#define pN { cout << "NO"; return; }

void solve() {
    int n; cin >> n;
    int a[n]; for (int i=0; i<n; i++) cin >> a[i];

    // auto f = [&] () -> void {};

    sort (a, a+n);
    ll s = 0; for (int i: a) s += i;
    ll s2 = 0;

    double ans = 1.0*s/n;
    for (int i=0; i<n-1; i++) {
        s2 += a[i];
        ans = max(ans, ((1.0*s2/(i+1)) + s-s2)/(n-i));
    }

    cout << prec(6) << ans;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;

    for (int i=0; i<t; i++) {
        // cout << "Case #" << i+1 << ": ";
        solve();
        cout << "\n";
    }

    return 0;
}
