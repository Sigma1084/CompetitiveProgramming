#include <bits/stdc++.h>
using namespace std;

typedef unsigned long int ul;
typedef long long int ll;
typedef unsigned long long int ull;
typedef vector<int> vi;
typedef vector<long long int> vll;
typedef pair<int, int> pii;

#define pb push_back

void solve()
{
    ll n;
    cin >> n;

    ll a[n];
    for (ll i=0; i<n; i++)
        cin >> a[i];

    // Code starts here
    int ans = 0;
    vll arr;

    int numOdds = 0;
    ll currSum = 0;
    for (ll i=0; i<n; i++) {
        if (a[i]%2 == 0) {
            if (numOdds == 0)
                arr.pb(a[i]);
            else {
                arr.pb(currSum);
                arr.pb(a[i]);
                currSum = 0;
                if (numOdds > 1)
                    ans++;
                numOdds = 0;
            }
        }
        else {
            currSum += a[i];
            numOdds++;
        }
    }
    if (numOdds > 0) {
        if (numOdds > 1)
            ans++;
        arr.pb(currSum);
    }

    vll arrr;
    int numEvens = 0;
    currSum = 0;
    for (ul i=0; i<arr.size(); i++) {
        if (arr[i]%2 == 1) {
            if (numEvens == 0)
                arrr.pb(arr[i]);
            else {
                arrr.pb(currSum);
                arrr.pb(arr[i]);
                currSum = 0;
                if (numEvens > 1)
                    ans++;
                numEvens = 0;
            }
        }
        else {
            currSum += arr[i];
            numEvens++;
        }
    }
    if (numEvens > 0) {
        if (numEvens > 1)
            ans++;
        arrr.pb(currSum);
    }

    cout << arrr.size() << " " << ans;
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
