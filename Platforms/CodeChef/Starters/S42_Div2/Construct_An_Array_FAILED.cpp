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

// Input Macros
#define Get(_T, x) _T x; cin >> x
#define GetV(_T, x, n) V<_T> x(n); cin >> x

// Debugging
bool debug = false;

/* ------------------------------------------------------------------------- */
// Some Functions

void fast() { ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr); }

tempT _T Min(int n, _T a[]) {_T mn = a[0];For(n) mn = min(mn, a[i]); return mn;}
tempT _T Max(int n, _T a[]) {_T mx = a[0];For(n) mx = max(mx, a[i]); return mx;}
tempT _T Min(V<_T> a) { _T mn = a[0]; Trav(a) mn = min(mn, i); return mn; }
tempT _T Max(V<_T> a) { _T mx = a[0]; Trav(a) mx = max(mx, i); return mx; }

tempT ll Sum(int n, _T a[]) { ll s = 0; For(n) s += a[i]; return s; }
tempT ll Sum(V<_T> a) { ll s = 0; Trav(a) s += i; return s; }

tempT M<_T, int> freq(V<_T> a) {M<_T, int> m; Trav(a) m[i]++; return m; }
ll lcm(ll a, ll b) { return a * b / __gcd(a, b); }

/* ------------------------------------------------------------------------- */

// Global Variables


const int N = 1e3;

vb isPrime(N+3, true);
vi primes;
vi smallPrimes;
ll large = 1;
ll large2 = 2; 

void prepare() {
    isPrime[0] = isPrime[1] = false;

    for(int i=2; i*i<=N; i++) {
        if (isPrime[i]) {
            for (int j=i*i; j<=N; j += i) {
                isPrime[j] = false;
            }
        }
    }

    For(N+1) { 
        if (i <= 32 and isPrime[i]) smallPrimes.pb(i);
        else if (isPrime[i]) primes.pb(i);
    }
}

void solve() {
    Get(int, n);
    
    // auto f = [&] () -> void {};

    auto getNum = [&](int i) -> ll {
        if (i == n-2) return large;
        if (i == n-1) return large2;

        ll num = i+3;
        if (i < primes.size()) num *= primes[i];
        return num;
    };

    For(n) {
        cout << getNum(i) << ' ';
    } cout << NL;

    For(n) {
        if (i == 0) { cout << __gcd(getNum(0), large2) << ' '; }
        else if (i == 1) { cout << __gcd(large2, large) << ' '; }
        else { cout << __gcd(getNum(i-2), large) << ' '; }
    }
}


int main() {
    fast();

    int t = 1;
    cin >> t;

    prepare();
    for (int p: vi({2, 3, 5, 7, 11, 13})) {
        // Max power of p dividing 1000
        int k = N;
        while (k / p > 0) large *= p, k /= p;
    }

    for (int p: vi({17, 19, 23, 29, 31})) {
        int k = N;
        while (k / p > 0) large2 *= p, k /= p;
    }

    for (int i=1; i<=t; i++) {
        // cout << "Case #" << i << ": ";
        solve();
        cout << NL;
    }

    return 0;
}
