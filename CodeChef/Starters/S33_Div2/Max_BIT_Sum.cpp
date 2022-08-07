#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

int numBinDig(int n) {
    int numDig = 0;
    while (n > 0) {
        numDig++;
        n /= 2;
    }
    return numDig;
}

void solve()
{
    int n;
    cin >> n;

    int a[n];
    for (int i=0; i<n; i++)
        cin >> a[i];

    int b[n];
    for (int i=0; i<n; i++)
        cin >> b[i];

    // Code starts here
    int nDA[n], nDB[n];
    for (int i=0; i<n; i++) {
        nDA[i] = numBinDig(a[i]);
        nDB[i] = numBinDig(b[i]);
    }

    ll sums = 0;

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (nDA[i] == nDB[j]) {
                sums += a[i] & b[i];
            }
            else {
                sums += a[i] ^ b[i];
            }
        }
    }

    cout << sums;
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
