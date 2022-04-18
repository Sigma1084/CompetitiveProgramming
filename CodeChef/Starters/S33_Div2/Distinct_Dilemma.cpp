#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;


void solve()
{
    int n;
    cin >> n;

    int a[n];
    for (int i=0; i<n; i++)
        cin >> a[i];

    // Code starts here
    ll s = 0;
    for (int i=0; i<n; i++)
        s += a[i];

    ll k = floor(sqrt(2 * s));
    while (k*(k+1) > 2*s)
        k--;

    cout << k;
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
