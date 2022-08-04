#include <bits/stdc++.h>
using namespace std;

// Data Types
typedef long long int ll;
typedef long double ld;

// Constants
const int MOD = 1000000007;
const float PI = 3.1415926535;
const float eps = 1e-6;
const int INF = INT_MAX;
const ll LINF = LONG_MAX;
const char NL = '\n';

// Some misc Macros
#define pb push_back
#define prec fixed << setprecision
#define tempT template<typename T>
#define all(v) (v).begin(), (v).end()
#define F first
#define S second

// For loops
#define For(n) for(int i=0; i<n; i++)
#define ForRev(n) for (int i=n-1; i>=0; i--)
#define Trav(_iterable) for(auto &i: _iterable)
#define rep(i, start, end) for(auto i=start; i<end; i++)
#define repRev(i, start, end) for(auto i=end-1; i>=start; i--)
#define TRAV(i, _iterable) for(auto &i: _iterable)

// Data Structures
#define V vector
#define M map
typedef V<int> vi;
typedef V<bool> vb;
typedef V<vi> vvi;
typedef V<long long int> vl;


// Yes or No and return Macros
#define pY { cout << "YES"; return; }
#define pN { cout << "NO"; return; }

/* ------------------------------------------------------------------------- */
// Input and Output Extends

template<typename T> istream &operator >> (istream &in, vector<T> &v) {
    for (auto &i: v) in >> i; return in; }
template<typename T> ostream &operator << (ostream &ost, const vector<T> &v) {
    if (&ost == &cerr) { cerr << "{"; for(auto &x: v) cerr << ' ' << x; cerr << " }"; }
    else for (auto &x: v) ost << x << ' '; return ost; }
template<typename T1, typename T2> istream &operator >> (istream &in, pair<T1, T2> &p) {
    in >> p.first >> p.second; return in; }
template<typename T1, typename T2> ostream &operator << (ostream &ost, const pair<T1, T2> &p) {
    if (&ost == &cerr) { cerr << "( " << p.first << ", " << p.second << " )"; }
    else ost << p.first << ' ' << p.second; return ost; }
template<typename T> ostream &operator << (ostream &ost, const set<T> &s) {
    if (&ost == &cerr) { cerr <<"{"; for(auto &x: s) cerr << ' ' << x; cerr << " }"; }
    else for (auto &x: s) ost << x << ' '; return ost; }
template<typename T> ostream &operator << (ostream &ost, const multiset<T> &s) {
    if (&ost == &cerr) { cerr <<"{"; for(auto &x: s) cerr << ' ' << x; cerr << " }"; }
    else for (auto &x: s) ost << x << ' '; return ost; }

/* ------------------------------------------------------------------------- */
// Some Functions

void fast() { ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr); }

tempT T Min(V<T> a) { T mn = a[0]; Trav(a) mn = min(mn, i); return mn; }
tempT T Max(V<T> a) { T mx = a[0]; Trav(a) mx = max(mx, i); return mx; }
tempT ll Sum(V<T> a) { ll s = 0; Trav(a) s += i; return s; }
tempT M<T, int> freq(V<T> a) { map<T, int> m; Trav(a) m[i]++; return m; }

bool isInt(float x) { return ((x - (int)x) < eps); }

/* ------------------------------------------------------------------------- */

// Global Variables


// const int N = 1e5 + 3;

ll solve(ll k) {
    // total = n C 2
    // Divide the grids into bars of 2*3 or 3*2
    // In both the above cases 2 positions get wiped out
    ll ans = (k*k) * (k*k - 1) / 2;
    ans -= 4 * (k-1) * (k-2);
    return ans;
}

int main() {
    fast();

    int t = 1;
    cin >> t;

    for (int i=1; i<=t; i++) {
        // cout << "Case #" << i << ": ";
        cout << solve(i);
        cout << NL;
    }

    return 0;
}
