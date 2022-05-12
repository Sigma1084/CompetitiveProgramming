#include <bits/stdc++.h>
using namespace std;

typedef unsigned long int ul;
typedef long long int ll;
typedef unsigned long long int ull;
typedef vector<int> vi;
typedef vector<long long int> vll;
typedef pair<int, int> pii;

#define MOD 1000000007
#define PI 3.1415926535

#define pb push_back
#define prec fixed << setprecision

#define pY { cout << "YES"; return; }
#define pN { cout << "NO"; return; }


void solve() {
    int r, a, b;
    cin >> r >> a >> b;

    // Given, 2A <= B <= 1000

    // auto f = [&] () -> void {};
    
    double ans = 0.0;
    while (r > 0) {
        ans += (double) r * r;
        ans += (double) r * a * r * a;
        r = r * a / b;
    }
    cout << prec(6) << PI * ans;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;

    for (int i=0; i<t; i++) {
        cout << "Case #" << i+1 << ": ";
        solve();
        cout << "\n";
    }

    return 0;
}
