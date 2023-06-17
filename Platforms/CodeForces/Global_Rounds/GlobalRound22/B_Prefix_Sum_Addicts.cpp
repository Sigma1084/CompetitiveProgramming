#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MOD = 1e9 + 7;

void solve() {
    int n, k; cin >> n >> k;
    vector<ll> s(k); for (auto &x: s) cin >> x;

    // Calculate the minimum and maximum of Sk
    // a[i] = S[i] - S[i-1]

    for (int i=1; i+1 < k; i++) {
        // a[i+1] < a[i] should not happen
        if (s[i+1] - s[i] < s[i] - s[i-1]) {
            cout << "No";
            return;
        }
    }

    ll last = k > 1 ? s[1] - s[0] : INT_MAX;
    ll minLast = (s[0] / (n-k+1)) + ((s[0]%(n-k+1)) != 0);

    if (minLast <= last) {
        cout << "Yes";
    } else {
        cout << "No";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int t = 1;
    cin >> t;

    for (int i=1; i<=t; i++) {
        // cout << "Case #" << i << ": ";
        solve(); cout << '\n';
    }
    return 0;
}

