#include <bits/stdc++.h>
using namespace std;

typedef unsigned long int ul;
typedef long long int ll;
typedef unsigned long long int ull;

typedef vector<int> vi;
typedef vector<long long int> vll;
typedef vector<bool> vb;

typedef vector<vi> vvi;
typedef vector<vll> vvll;

typedef pair<int, int> pii;

const int MOD = 1000000007;
const double PI = 3.1415926535;

#define pb push_back
#define prec fixed << setprecision

#define pY { cout << "YES"; return; }
#define pN { cout << "NO"; return; }

const int N = 2e5 + 2;
vvi e(N);
int p[N];
int w[N];
void dfs(int u) { for (int v: e[u]) if (v != p[u]) p[v] = u, dfs(v); }

void solve() {
    int n, k, st, ed;
    cin >> n >> k >> st >> ed;

    int col[k];
    for (int &v: col)
        cin >> v;

    fill_n(p+1, n, 0);
    fill_n(w+1, n, 0);
    for (int i=1; i<=n; i++) e[i].clear();

    for (int i=0; i<n-1; i++) {
        int t1, t2;
        cin >> t1 >> t2;
        e[t1].pb(t2);
        e[t2].pb(t1);
    }

    // Code starts here
    dfs(st);
    for (int c: col) while (c != st && w[c]==0) w[c] = 2, c = p[c];
    while (ed != st) w[ed] = 1, ed = p[ed];

    cout << accumulate(w+1, w+n+1, 0);
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
