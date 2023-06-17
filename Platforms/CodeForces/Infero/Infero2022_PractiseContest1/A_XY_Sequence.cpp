#include <bits/stdc++.h>
using namespace std;

typedef unsigned long int ul;
typedef long long int ll;
typedef unsigned long long int ull;
typedef vector<int> vi;
typedef vector<long long int> vll;
typedef pair<int, int> pii;

#define MOD 1000000007
#define pb push_back

void solve() {
    int n, B, x, y;
    cin >> n >> B >> x >> y;

    // Code starts here
    ll s = 0;
    int curr = 0;
    for (int i=1; i <= n; i++) {
        if (curr + x <= B)
            curr = curr + x;
        else
            curr = curr - y;
        s += curr;
    }

    cout << s;
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
