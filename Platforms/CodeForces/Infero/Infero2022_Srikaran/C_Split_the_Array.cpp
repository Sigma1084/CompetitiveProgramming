#include <bits/stdc++.h>
using namespace std;

// Data Types
typedef long long int ll;
typedef long double ld;

// Constants
const int MOD = 1000000007;
const double PI = 3.1415926535;
const int INF = INT_MAX;
const ll LINF = LONG_MAX;
const char NL = '\n';

// Some misc Macros
#define pb push_back
#define prec fixed << setprecision
#define tempT template <typename T>
#define all(v) (v).begin(), (v).end()
#define F first
#define S second
#define Sort(v) sort(all(v))

// For loops
#define For(n) for(int i=0; i<n; i++)
#define ForRev(n) for (int i=n-1; i>=0; i--)
#define Trav(_iterable) for(auto &i: _iterable)
#define FOR(i, start, end) for(auto i=start; i<end; i++)
#define FORRev(i, start, end) for(auto i=end-1; i>=start; i--)
#define TRAV(i, _iterable) for(auto &i: _iterable)

// Data Structures
tempT struct V: vector<T> {
    using vector<T>::vector;
    void sort() { std::sort(all(*this)); }
    friend ostream& operator << (ostream &outFunc, const V<T> &v)
    { Trav(v) outFunc << i << ' '; outFunc << ' '; return outFunc; }
    friend istream& operator >> (istream &inFunc, V<T> &v)
    { Trav(v) inFunc >> i; return inFunc; }
};
template<class T1, class T2> struct P: pair<T1, T2> {
    using pair<T1, T2>::pair;
    friend ostream& operator << (ostream &outFunc, const P<T1, T2> &p)
    { outFunc << p.F << ' ' << p.S << ' '; return outFunc; }
    friend istream& operator >> (istream &inFunc, P<T1, T2> &p)
    { inFunc >> p.F >> p.S; return inFunc; }
};
#define M map
typedef V<int> vi;
typedef V<bool> vb;
typedef V<vi> vvi;
typedef P<int, int> pii;
typedef M<int, int> mii;
typedef V<long long int> vl;
typedef V<vl> vvl;


// Yes or No and return Macros
#define pY { cout << "YES"; return; }
#define pN { cout << "NO"; return; }

tempT istream &operator >> (istream &in,vector<T> &v) { for (auto &i : v) in >> i ; return in; }
tempT ostream &operator << (ostream &ost, vector<T> v) {
    if (&ost == &cerr) {
        int cnt = v.size(); cerr <<"{";
        for(auto x: v) { cerr << x; cnt--; if(cnt) cerr << ", "; }
        cerr << "}";
    } else for (auto &i: v) ost << i << " "; return ost;
}


/* ------------------------------------------------------------------------- */
// Some Functions

void fast() { ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr); }

tempT T Min(int n, T a[]) {T mn = a[0];For(n) mn = min(mn, a[i]); return mn;}
tempT T Max(int n, T a[]) {T mx = a[0];For(n) mx = max(mx, a[i]); return mx;}
tempT T Min(V<T> a) { T mn = a[0]; Trav(a) mn = min(mn, i); return mn; }
tempT T Max(V<T> a) { T mx = a[0]; Trav(a) mx = max(mx, i); return mx; }

tempT ll Sum(int n, T a[]) { ll s = 0; For(n) s += a[i]; return s; }
tempT ll Sum(V<T> a) { ll s = 0; Trav(a) s += i; return s; }

tempT M<T, int> freq(V<T> a) { M<T, int> m; Trav(a) m[i]++; return m; }

bool isInt(float x) { return ((x - (int)x) < 1e-9); }

/* ------------------------------------------------------------------------- */

// Global Variables


// const int N = 1e5 + 3;

void solve() {
    int n, T; cin >> n >> T;
    vi a(n); cin >> a;

    int count = 0;

    Trav(a) {
        if (i > T) {
            cout << 0 << ' ';
        } else if (i + i == T) {
            cout << (count%2) << ' ';
            count++;
        } else if (i + i < T) {
            cout << 0 << ' ';
        } else {
            cout << 1 << ' ';
        }
    }
}


int main() {
    fast();

    int t = 1;
    cin >> t;

    for (int i=1; i<=t; i++) {
        // cout << "Case #" << i << ": ";
        solve();
        cout << NL;
    }

    return 0;
}
