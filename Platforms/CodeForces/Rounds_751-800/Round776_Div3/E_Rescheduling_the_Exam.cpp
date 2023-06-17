#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;


void solve() {
    int n, d;
    cin >> n >> d;

    int a[n+1];
    for (int i=1; i<=n; i++)
        cin >> a[i];

    // Code starts here
    int mew = INT_MAX;
    for (int i=1; i<n; i++) {
        if (a[i+1] - a[i] < mew)
            mew = a[i+1] - a[i];
    }

    int excludingMax = -INT_MAX;
    vi included;

    if (a[2] - a[1] == mew)
        included.push_back(1);
    else if (a[2] - a[1] > excludingMax)
        excludingMax = a[2] - a[1];
    for (int i=2; i<n; i++) {
        if (a[i] - a[i-1] == mew || a[i+1] - a[i] == mew) {
            included.push_back(i);
            continue;
        }
        if (a[i] - a[i-1] > excludingMax)
            excludingMax = a[i] - a[i-1];
        if (a[i+1] - a[i] > excludingMax)
            excludingMax = a[i+1] - a[i];
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
