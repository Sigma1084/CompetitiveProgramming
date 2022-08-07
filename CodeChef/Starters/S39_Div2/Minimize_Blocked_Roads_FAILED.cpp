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
#define T third

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

// Debugging
#define print(a) Iter(a) cout << i << ' '; cout << '\n';

//Speed
#define FAST ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

// Quad
struct quad {
    int first, second, third, FO;
    quad(int a=1, int b=-1, int c=0, int d=0): first(a), second(b), third(c), FO(d) {};
    quad(quad const &t): first(t.first), second(t.second), third(t.third), FO(t.FO) {};
    bool operator < (quad const &other) {if (this->first < other.first) return true; return false; }
    bool operator > (quad const &other) {if (this->first > other.first) return true; return false; }
    friend std::ostream& operator << (ostream &outFunc, const quad& t) {
        outFunc << t.first << " " << t.second << " " << t.third << " " << t.FO; return outFunc; }
};

bool com(const quad &q1, const quad &q2) {
    if (q1.F > q2.F) return true;
    return false;
}

/* ------------------------------------------------------------------------- */

void solve() {
    GetInts(n, k)
    V<V<pii>> e(n+1);
    For(n-1) {
        GetInts(a, b) GetInt(c)
        e[a].pb({b, c});
        e[b].pb({a, c});
    }
    // a[i].F says whether it can be blocked

    V<quad> info(n+1);
    // F is the number of cities under it
    // S is the parent 
    // T says whether the node can be closed
    // FO is the index of the node

    info[1] = {1, 1, 0, 1};
    auto dfs = [&] (auto &&dfs, int cur) -> void {
        info[cur].F = 1;  // Initially setting the cities under it to be 1
        Iter(e[cur]) {
            // If i is the parent edge ontinue
            if (i.F == info[cur].S) continue;
            if (info[i.F].S != -1) continue;
            info[i.F] = {1, cur, i.S, i.F};
            dfs(dfs, i.F);
            info[cur].F += info[i.F].F;
        }
    }; dfs(dfs, 1);
    auto inf = info;
    sort(inf.begin(), inf.end(), com);

    // inf is sorted in such a way that the number of cities is max
    map<int, bool> m;
    int cities = n;
    int ans = 0;
    Iter(inf) {
        if (i.T == 0) continue;
        
        // Here i.T = 1 which means it can be closed
        // Now to check if it has a closed parent
        int c = i.T;
        bool check = false;
        while (!check && c != 1) 
            check = m[c], c = info[c].S;
        if (check) continue;
        m[c] = true; cities -= i.F; ans++;
        if (cities <= k) {
            cout << ans;
            return;
        }
    }
    cout << -1;
    return;
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
