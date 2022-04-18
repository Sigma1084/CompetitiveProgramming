#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;


void solve()
{
    ll num = 0;

    ll temp = 2;
    ll gcd;
    for (ll i=1; i<30; i++, temp*=2) {
        cout << "? " << temp - num << " " << 2*temp - num << endl;
        cout.flush();
        cin >> gcd;
        if (temp/gcd == 2)
            num += gcd;
    }

    temp /= 2;  // temp = 2^29
    // Now our a, b are 2^29+2^28 and 2^30-1
    // If x = 0, we have GCD = 3
    // If x = 2^29, we have GCD != 3 since 2^28(5) is not div by 3
    cout << "? " << temp + temp / 2 - num << " " << 2 * temp - 1 - num << endl;
    cout.flush();
    cin >> gcd;
    if (gcd != 3) {
        num += temp;
    }

    cout << "! " << num << endl;
    cout.flush();
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
