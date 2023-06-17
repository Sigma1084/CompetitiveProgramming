#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

#define MOD 1000000007

// Gives the number of occurrences of 1 in d-th's place in n
int numPlaces(int n, int d) {
    if (n < (1<<d))
        return 0;

    int ans = (n >> (d+1)) * (1 << d);
    ans += (n>>d & 1) * (1 + (n % ((n>>d)<<d)));

    return ans;
}

void solve()
{
    int n;
    cin >> n;

    int a[n];
    for (int i=0; i<n; i++)
        cin >> a[i];

    // Code starts here
    int currPlace = 1;
    ll prod, ans = 0;
    for (int j=0; j<30; j++, currPlace *= 2) {
        prod = 1;
        for (int i=0; i<n; i++) {
            prod *= numPlaces(a[i], j);
            prod %= MOD;
        }
        ans += (ll)prod * currPlace;
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
