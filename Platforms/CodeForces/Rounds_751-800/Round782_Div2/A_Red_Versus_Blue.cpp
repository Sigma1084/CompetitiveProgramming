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

#define pY { cout << "YES"; return; }
#define pN { cout << "NO"; return; }

void solve() {
    int n, r, b;
    cin >> n >> r >> b;

    // auto f = [&] () -> void {};
    // Divide Rs into b+1 groups

    if (r == b) {
        for (int i=0; i<r; i++) cout << "RB";
        return;
    }

    int rem = r % (b+1);
    int num = r / (b+1);
    // cout << rem << num << endl;

    // Number of groups is b+1
    for (int i=0; i<b; i++) {
        for (int j=0; j<num; j++) cout << "R";
        if (i < rem) cout << "R";
        cout << "B";
    }
    for (int j=0; j<num; j++) cout << "R";
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
