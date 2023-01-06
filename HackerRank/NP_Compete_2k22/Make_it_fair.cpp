#include <bits/stdc++.h>
using namespace std;

typedef unsigned long int ul;
typedef long long int ll;
typedef unsigned long long int ull;
typedef vector<int> vi;
typedef vector<long long int> vll;
typedef pair<int, int> pii;

#define pb push_back

void solve() {
    int n;
    cin >> n;
    int x, y;
    cin >> x >> y;

    int a[n];
    for (int i=0; i<n; i++)
        cin >> a[i];

    // Code starts here
    int g = __gcd(x, y);
    if (g == 1 || n == 1) {
        cout << "YES";
        return;
    }

    int val = a[0]%g;
    for (int i=1; i<n; i++) {
        if (a[i]%g != val) {
            cout << "NO";
            return;
        }
    }
    cout << "YES";
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
