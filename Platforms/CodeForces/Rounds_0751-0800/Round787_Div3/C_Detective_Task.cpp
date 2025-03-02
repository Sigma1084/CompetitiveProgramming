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
    string a;
    cin >> a;

    int n = a.size();

    // auto f = [&] () -> void {};

    int last1 = 0;
    for (int i=0; i<n; i++) {
        if (a[i] == '1')
            last1 = i;
    }

    int first0 = n-1;
    for (int i=n-1; i>=0; i--) {
        if (a[i] == '0')
            first0 = i;
    }

    cout << first0 - last1 + 1;
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
