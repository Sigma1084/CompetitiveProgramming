#include <bits/stdc++.h>
using namespace std;

// Data Type Macros

typedef unsigned long int ul;
typedef long long int ll;
typedef unsigned long long int ull;

typedef vector<int> vi;
typedef vector<long long int> vll;
typedef vector<bool> vb;

typedef vector<vi> vvi;
typedef vector<vll> vvll;

typedef pair<int, int> pii;

// Constant Macros
#define MOD 1000000007
#define PI 3.1415926535
#define inf INT_MAX
#define linf LONG_MAX

// Some other Macros
#define pb push_back
#define prec fixed << setprecision
#define tempT template <class T>

// Yes or No and return Macros
#define pY { cout << "YES"; return; }
#define pN { cout << "NO"; return; }

// Input Macros
#define GetInt(x) int x; cin >> x;
#define GetInts(x, y) int x, y; cin >> x >> y;

#define Get(T, x) T x; cin >> x;
#define GetArr(T, a, n) T a[n]; for (int i=0; i<n; i++) cin >> a[i];
#define GetVec(T, v) vector<T> v; T temp; for (int i=0; i<n; i++) cin >> temp, v.pb(temp);

// For loops
#define For for(int i=0; i<n; i++)
#define ForRev for (int i=n-1; i>=0; i--)
#define FOR(i, start, end) for(auto i=start; i<end; i++)
#define FORRev(i, start, end) for(auto i=end-1; i>=start; i--)
#define Iter(arr) for(auto i: arr)

// Some Functions
tempT T Min(int n, T arr[]) {T mn = arr[0]; FOR(i, 1, n) mn = min(mn, arr[i]); return mn;}
tempT T Max(int n, T arr[]) {T mx = arr[0]; FOR(i, 1, n) mx = max(mx, arr[i]); return mx;}

// Debugging
#define print(a) Iter(a) cout << i; cout << '\n';


void solve() {
    GetInt(n)
    GetArr(int, a, n)

    // auto f = [&] () -> void {};
    int mn = Min(n, a);
    ll s = 0; Iter(a) s += i-mn; 
    cout << s;
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
