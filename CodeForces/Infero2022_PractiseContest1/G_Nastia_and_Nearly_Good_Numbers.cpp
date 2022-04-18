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
    ll A, B;
    cin >> A >> B;

    // Code starts here

    if (B == 1) {
        cout << "NO";
        return;
    }

    cout << "YES\n";
    if (B == 2) 
        cout << A << " " << A*3 << " " << A*4;
    else
        cout << A << " " << A*(B-1) << " " << A*B;
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
