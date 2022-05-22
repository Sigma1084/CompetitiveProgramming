#include <bits/stdc++.h>
using namespace std;

// Data Type Macros

typedef unsigned long int ul;
typedef long long int ll;
typedef unsigned long long int ull;

#define V vector
typedef V<int> vi;
typedef V<long long int> vll;
typedef V<bool> vb;

typedef V<vi> vvi;
typedef V<vll> vvll;

typedef pair<int, int> pii;

// Constants
const int MOD = 1000000007;
const double PI = 3.1415926535;
const int INF = INT_MAX;
const ll LINF = LONG_MAX;

// Some other Macros
#define pb push_back
#define prec fixed << setprecision
#define tempT template <class T>
#define F first
#define S second

// Yes or No and return Macros
#define pY { cout << "YES"; return; }
#define pN { cout << "NO"; return; }

// Input Macros
#define GetInt(x) int x; cin >> x;
#define GetInts(x, y) int x, y; cin >> x >> y;

#define Get(T, x) T x; cin >> x;
#define GetArr(T, a, n) T a[n]; for (int i=0; i<n; i++) cin >> a[i];
#define GetVec(T, v, n) V<T> v; T t; for (int i=0; i<n; i++) cin >> t, v.pb(t);

// For loops
#define For(n) for(int i=0; i<n; i++)
#define ForRev(n) for (int i=n-1; i>=0; i--)
#define FOR(i, start, end) for(auto i=start; i<end; i++)
#define FORRev(i, start, end) for(auto i=end-1; i>=start; i--)
#define Iter(arr) for(auto i: arr)

// Some Functions
tempT T Min(int n, T a[]) { T mn = a[0]; For(n) mn = min(mn, a[i]); return mn; }
tempT T Max(int n, T a[]) { T mx = a[0]; For(n) mx = max(mx, a[i]); return mx; }
tempT T Min(V<T> a) { T mn = a[0]; Iter(a) mn = min(mn, i); return mn; }
tempT T Max(V<T> a) { T mx = a[0]; Iter(a) mx = max(mx, i); return mx; }

// Debugging
#define print(a) Iter(a) cout << i << ' '; cout << '\n';

//Speed
#define FAST ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

/* ------------------------------------------------------------------------- */


class Solution {
public:
    int minimumCardPickup(vi &a) {
        int ans = MOD;
        map<int, int> prev;
        int n = a.size();
        For(n) {
            if (prev[a[i]]) ans = min(ans, i+2 - prev[a[i]]);
            prev[a[i]] = i+1;
        }
        if (ans == MOD) ans = -1;
        return ans;
    }
};

void solve() {
    GetInt(n)
    GetVec(int, a, n)

    // auto f = [&] () -> void {};
    Solution sol;
    cout << sol.minimumCardPickup(a);
}


int main() {
    FAST

    int t;
    cin >> t;

    for (int i=0; i<t; i++) {
        // cout << "Case #" << i+1 << ": ";
        solve();
        cout << "\n";
    }

    return 0;
}
