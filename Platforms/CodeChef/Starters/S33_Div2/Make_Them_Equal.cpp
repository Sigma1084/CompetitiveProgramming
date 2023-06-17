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
    int numOdd = 0;
    int numEven = 0;
    for (int i=0; i<n; i++) {
        if (a[i] % 2 == 0)
            numEven++;
        else
            numOdd++;
    }

    // Number of odds is odd
    if (numOdd % 2 == 1) {
        cout << numEven;
    }

    // Number of odds is even
    else {
        cout << min(numEven, numOdd/2);
    }
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
