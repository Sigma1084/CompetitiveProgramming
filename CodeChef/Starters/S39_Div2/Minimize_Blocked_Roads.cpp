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

// Debugging
#define print(a) Iter(a) cout << i << ' '; cout << '\n';

//Speed
#define FAST ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

/* ------------------------------------------------------------------------- */

void solve() {
    GetInts(n, k)
    V<V<pii>> e(n+1);
    For(n-1) {
        GetInts(a, b) GetInt(c)
        e[a].pb({b, c});
        e[b].pb({a, c});
    }
    // e[i].S says whether it can be blocked

    if (k == n) {
        cout << 0;
        return;
    }

    // auto f = [&] () -> void {};

    vi p(n+1, -1);  // Parent in the dfs tree
    vi w(n+1, 1);  // Weight of the node in the dfs tree
    vb c(n+1, 0);  // Whether the node can be closed

    p[1] = 1, c[1] = 0;
    auto dfs = [&] (auto &&dfs, int u) -> void {
        Iter(e[u]) {
            // i is the pii with F as v and S as c[v]
            int v = i.F;
            if (p[u] == v) continue; // The back edge

            c[v] = i.S;
            p[v] = u;
            dfs(dfs, v);
            w[u] += w[v];
        }
    }; dfs(dfs, 1);

    V<pii> closables;
    // F is the weight and S is the index

    FOR(i, 2, n+1) if (c[i]) closables.pb({w[i], i});
    sort(closables.begin(), closables.end(), greater<pii>());

    map<int, bool> cl;

    int ans = 0;
    int cit = n;  // Number of cities affected
    Iter(closables) {
        int u = i.S;
        int v = u;

        bool check = false;
        while (!check && v != 1) {
            check = cl[v];
            v = p[v];
        }
        if (check) continue;

        ans += 1;
        cit -= i.F;
        cl[u] = true;

        if (cit <= k) {
            cout << ans;
            return;
        }
    }
    cout << -1;
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
