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
#define tempT template <class _T>
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
tempT struct V: vector<_T> {
    using vector<_T>::vector;
    void sort() { std::sort(all(*this)); }
    friend ostream& operator << (ostream &outFunc, const V<_T> &v)
    { Trav(v) outFunc << i << ' '; outFunc << ' '; return outFunc; }
    friend istream& operator >> (istream &inFunc, V<_T> &v)
    { Trav(v) inFunc >> i; return inFunc; }
    template<class T2> friend V<_T> operator + (const V<_T> &v, const T2 &ele)
    { V<_T> ans; Trav(v) ans.pb(i + ele); return ans; }
    template<class T2> friend V<_T> operator / (const V<_T> &v, const T2 &ele)
    { V<_T> ans; Trav(v) ans.pb(i / ele); return ans; }
    template<class T2> friend V<_T> operator * (const V<_T> &v, const T2 &ele)
    { V<_T> ans; Trav(v) ans.pb(i * ele); return ans; }
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


/* ------------------------------------------------------------------------- */
// Some Functions

void fast() { ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr); }

tempT _T Min(int n, _T a[]) {_T mn = a[0];For(n) mn = min(mn, a[i]); return mn;}
tempT _T Max(int n, _T a[]) {_T mx = a[0];For(n) mx = max(mx, a[i]); return mx;}
tempT _T Min(V<_T> a) { _T mn = a[0]; Trav(a) mn = min(mn, i); return mn; }
tempT _T Max(V<_T> a) { _T mx = a[0]; Trav(a) mx = max(mx, i); return mx; }

tempT ll Sum(int n, _T a[]) { ll s = 0; For(n) s += a[i]; return s; }
tempT ll Sum(V<_T> a) { ll s = 0; Trav(a) s += i; return s; }

tempT M<_T, int> freq(V<_T> a) { M<_T, int> m; Trav(a) m[i]++; return m; }

bool isInt(float x) { return ((x - (int)x) < 1e-9); }

/* ------------------------------------------------------------------------- */

// Global Variables


const int N = 1e5 + 2;
V<V<bool>> vertexOpen(51, V<bool>(N, false));

// e[t][a] will give edges of a at t
V<V<V<int>>> e(51, V<V<int>>(N, V<int>()));  

V<int> p(N, -1);  // Parent
bool stop = false;

void dfs(int u, int t, int end) {
    for (auto v: e[t][u]) {
        if (stop) return;
        if (p[v] == -1) {
            p[v] = u;
            if (v == end) {
                stop = true;
                return;
            }
            dfs(v, t, end);
        }
    }
}

void solve() {
    vertexOpen = V<V<bool>>(51, V<bool>(N, false));
    e = V<V<V<int>>>(51, V<V<int>>(N, V<int>()));

    int n; cin >> n;
    for(int i=1; i<=n; i++) {
        int t; cin >> t;
        for(int j=0; j<t; j++) {
            int a, b; cin >> a >> b;
            for (int k=a; k<=b; k++) 
                vertexOpen[k][i] = true;
        }
    }

    int m; cin >> m;
    for (int i=1; i<=m; i++) {
        int u, v; cin >> u >> v;
        int t; cin >> t;
        for(int j=0; j<t; j++) {
            int a, b; cin >> a >> b;
            for (int k=a; k<=b; k++) {
                if (vertexOpen[k][u] and vertexOpen[k][v]) {
                    e[k][u].pb(v);
                    e[k][v].pb(u);
                }
            }
        }
    }

    int start, finish;
    cin >> start >> finish;

    ll ans = 0;

    for (int t=0; t<=50; t++) {
        if (!vertexOpen[t][start] or !vertexOpen[t][finish]) {
            continue;
        }
        if (e[t][start].empty() or e[t][finish].empty()) {
            continue;
        }
        p = V<int>(N, -1);
        stop = false;
        dfs(start, t, finish);
        if (p[finish] == -1) {
            continue;
        }
        ans++;
    }

    cout << ans;
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
