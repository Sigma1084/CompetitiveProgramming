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
#define pMinus1 { cout << -1; return; }

void solve() {
    int n;
    cin >> n;

    int a[n];
    for (int i=0; i<n; i++)
        cin >> a[i];

    // auto f = [&] () -> void {};

    int count = 0;
    for (int i=n-2; i>=0; i--) {
        while (a[i] > 0 && a[i] >= a[i+1]) {
            a[i] /= 2;
            count++;
        }
        // Here, a[i] < a[i+1]
        if (a[i+1] == 0) pMinus1;
    }

    cout << count;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;

    for (int i=0; i<t; i++) {
        // cout << "Case #" << i+1 << ": ";
        solve();
        cout << "\n";
    }

    return 0;
}
