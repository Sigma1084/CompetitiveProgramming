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
    int n, m;
    cin >> n >> m;
    int a[n], h[n];
    int b[m], c[m];

    for (int i=0; i<n; i++)
        cin >> a[i];

    for (int i=0; i<n; i++)
        cin >> h[i];

    for (int i=0; i<m; i++)
        cin >> b[i];

    for (int i=0; i<m; i++)
        cin >> c[i];

    // Code starts here

    auto effectBy = [&](int start, int intensity, int x) -> int {
        return max(0, intensity-abs(x-start));
    };

    auto effectAt = [&](int x) -> ll {
        ll ans = 0;
        for (int i=0; i<m; i++)
            ans += effectBy(b[i], c[i], x);
        return ans;
    };

    for (int i=1; i<20; i++)
        cout << effectAt(i) << " ";

    int ans = 0;
    for (int i=0; i<n; i++) {
        if (effectAt(a[i]) <= (ll)h[i])
            ans++;
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
