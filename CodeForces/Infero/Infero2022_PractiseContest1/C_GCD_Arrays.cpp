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
    int l, r, k;
    cin >> l >> r >> k;

    // Code starts here
    if (l == r) {
        if (l == 1)
            cout << "NO";
        else
            cout << "YES";
        return;
    }

    // l < r
    int req = 1;
    auto numOdds = [&](int n) -> int { return (n+1) / 2; };
    if (k >= numOdds(r) - numOdds(l-1))
        cout << "YES";
    else 
        cout << "NO";
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
