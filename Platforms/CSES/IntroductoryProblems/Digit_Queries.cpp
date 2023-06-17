#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MOD = 1e9 + 7;

void solve() {
    ll n; cin >> n;

    // Number of single digits => 9
    // Number of double digits => 90
    // Number of triple digits => 900

    int digs = 1;
    while (n > 9 * digs * pow(10, digs-1)) {
        n -= 9 * digs * pow(10, digs-1);
        digs++;
    }

    // Number of digits per number = digs
    // Number of numbers to process = n
    // Current Number = ceil(n / digs)

    string req = to_string((ll) (pow(10, digs-1) + ceil(1.0*n/digs) - 1));
    req = string(digs-req.size(), '0') + req;
    int index = (n-1) % digs;

    // cout << n << ' ' << req << '\n';
    cout << req[index];
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

