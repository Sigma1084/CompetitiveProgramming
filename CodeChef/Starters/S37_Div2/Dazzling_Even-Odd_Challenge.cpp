#include <bits/stdc++.h>
using namespace std;

typedef unsigned long int ul;
typedef long long int ll;
typedef unsigned long long int ull;

typedef vector<int> vi;
typedef vector<long long int> vll;
typedef vector<bool> vb;

typedef vector<vi> vvi;
typedef vector<vll> vvll;

typedef pair<int, int> pii;

#define MOD 1000000007
#define PI 3.1415926535

#define pb push_back
#define prec fixed << setprecision

#define pY { cout << "YES"; return; }
#define pN { cout << "NO"; return; }

void solve() {
    int n;
    cin >> n;

    int a[n];
    for (int i=0; i<n; i++)
        cin >> a[i];

    // auto f = [&] () -> void {};
    n /= 2;
    ll s = 0; for (int i: a) s += i;  // Sum of elements

    // Sum must be divisible by n and s/n must be odd
    if (s%n == 0 && s/n % 2 == 1) pY
    else pN  
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
