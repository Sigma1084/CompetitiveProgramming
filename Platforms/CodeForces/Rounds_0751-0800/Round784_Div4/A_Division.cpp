#include <bits/stdc++.h>
using namespace std;

// Data Types
typedef long long int ll;
typedef long double ld;

// Some misc Macros
#define pb push_back
#define prec fixed << setprecision
#define tempT template <class _T>
#define F first
#define S second

// DataTypes
#define V vector
#define M map
template<class _T1, class _T2> struct P: pair<_T1, _T2> {
    friend std::ostream& operator << (ostream &outFunc, const P<_T1, _T2> &p) {
        outFunc << p.F << ' ' << p.S << ' '; return outFunc; }
};

typedef V<int> vi;
typedef V<bool> vb;
typedef V<vi> vvi;
typedef P<int, int> pii;
typedef M<int, int> mii;
typedef V<long long int> vll;
typedef V<vll> vvll;

// Constants
const int MOD = 1000000007;
const double PI = 3.1415926535;
const int INF = INT_MAX;
const ll LINF = LONG_MAX;
const char NEWL = '\n';

// Yes or No and return Macros
#define pY { cout << "YES"; return; }
#define pN { cout << "NO"; return; }

// Input Macros
#define GetInt(x) int x; cin >> x;
#define GetInts(x, y) int x, y; cin >> x >> y;

#define Get(T, x) T x; cin >> x;
#define GetArr(T, a, n) T a[n]; for (int i=0; i<n; i++) cin >> a[i];
#define GetVec(T, v, n) V<T> v(n); for (T &t: v) cin >> t;

// For loops
#define For(n) for(int i=0; i<n; i++)
#define ForRev(n) for (int i=n-1; i>=0; i--)
#define Iter(arr) for(auto i: arr)
#define FOR(i, start, end) for(auto i=start; i<end; i++)
#define FORRev(i, start, end) for(auto i=end-1; i>=start; i--)

// Debugging
bool debug = false;
#define printIter(a) Iter(a) cout << i << ' '; cout << '\n';
#define printPair(p) cout << p.F << ' ' << p.S << ' ';

//Speed
#define FAST ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

/* ------------------------------------------------------------------------- */
// Some Functions

tempT _T Min(int n, _T a[]) {_T mn = a[0];For(n) mn = min(mn, a[i]); return mn;}
tempT _T Max(int n, _T a[]) {_T mx = a[0];For(n) mx = max(mx, a[i]); return mx;}
tempT _T Min(V<_T> a) { _T mn = a[0]; Iter(a) mn = min(mn, i); return mn; }
tempT _T Max(V<_T> a) { _T mx = a[0]; Iter(a) mx = max(mx, i); return mx; }

tempT ll Sum(int n, _T a[]) { ll s = 0; For(n) s += a[i]; return s; }
tempT ll Sum(V<_T> a) { ll s = 0; Iter(a) s += i; return s; }

tempT M<_T, int> freq(V<_T> a) {M<_T, int> m; Iter(a) m[i]++; return m; }

/* ------------------------------------------------------------------------- */

// const int N = 1e5 + 3;

/* ------------------------------------------------------------------------- */


void solve() {
    GetInt(n)

    // auto f = [&] () -> void {};
    cout << "Division ";
    if (n <= 1399) cout << 4;
    else if (n <= 1599) cout << 3;
    else if (n <= 1899) cout << 2;
    else cout << 1;
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
