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


// Input Macros
#define GetInt(x) int x; cin >> x;
#define GetInts(x, y) int x, y; cin >> x >> y;

#define Get(T, x) T x; cin >> x;
#define GetArr(T, a, n) T a[n]; for (int i=0; i<n; i++) cin >> a[i];
#define GetVec(T, v) vector<T> v; T temp; for (int i=0; i<n; i++) cin >> temp, v.pb(temp);

// For loops
#define For for(auto i=0; i<n; i++)
#define FOR(i, start, end) for(auto i=start; i<end; i++)
#define Iter(arr) for(auto i: arr)

// Some Functions
template <class T> T Min(int n, T arr[]) {T mn = arr[0]; FOR(i, 1, n) mn = min(mn, arr[i]); return mn;}
template <class T> T Max(int n, T arr[]) {T mx = arr[0]; FOR(i, 1, n) mx = max(mx, arr[i]); return mx;}

void solve() {
    GetInts(n, x);
    GetArr(int, a, n);

    // auto f = [&] () -> void {};
    if (Min(n, a) <= x && Max(n, a) >= x) pY
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
