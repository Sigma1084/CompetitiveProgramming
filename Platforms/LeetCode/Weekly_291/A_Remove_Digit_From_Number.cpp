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
#define GetVec(T, v) V<T> v; T t; for (int i=0; i<n; i++) cin >> t, v.pb(t);

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
#define Min(a, b, ...) min(a, Min(b, ...)
#define Max(a, b, ...) max(a, Max(b, ...)

// Debugging
#define print(a) Iter(a) cout << i << ' '; cout << '\n';

//Speed
#define FAST ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

/* ------------------------------------------------------------------------- */

string strSlice(string s, int start, int end) {
    int l = s.length();
    string ans = "";
    if (end == -1) end = s.length();
    if (start < 0 || start >= l) return ans;
    if (end <= start || end > l) return ans;
    for (int i=start; i<end; i++) ans += s[i];
    return ans;
}

class Solution {
public:
    string removeDigit(string a, char c) {
        int n = a.size();
        bool last = true;
        int ans = 0;
        ForRev(n) {
            if (a[i] != c) continue;
            if (last) {
                last = false;
                ans = i;
            } else if (a[i+1] > c) ans = i;
        }
        return strSlice(a, 0, ans) + strSlice(a, ans+1, -1);
    }
};

void solve() {
    Get(string, s)
    Get(char, c)

    // auto f = [&] () -> void {};
    Solution sol;
    cout << sol.removeDigit(s, c);
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