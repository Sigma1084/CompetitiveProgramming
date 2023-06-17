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

#define MOD 1000000007
#define PI 3.1415926535

#define pb push_back
#define prec fixed << setprecision

#define pY { cout << "YES"; return; }
#define pN { cout << "NO"; return; }

void solve() {
    int n;
    cin >> n;

    int par[n+1];
    int root;
    vvi edges(n+1);

    for (int i=1; i<=n; i++) {
        cin >> par[i];
        if (par[i] == i) {
            par[i] = 0;
            root = i;
        }
        edges[par[i]].pb(i);
    }

    vi s(n);
    s[0] = root;

    int count = 1;
    for (int i=1; i<=n; i++) {
        if (edges[i].size() > 0)
            count += edges[i].size() - 1;
    }
    cout << count << "\n";

    auto f = [&] (auto&& f, int start, int curr) -> void {
        // If the current node is a leaf (Termination)
        if (edges[s[curr]].size() == 0) {
            cout << curr - start + 1 << "\n";
            for (int i=start; i<=curr; i++)
                cout << s[i] << " ";
            cout << "\n";
            return;
        }

        // If the current node is the one that has returned from prev
        for (int i=0; i < edges[s[curr]].size(); i++) {
            s[curr+1] = edges[s[curr]][i];
            if (i == 0)
                f(f, start, curr+1);
            else
                f(f, curr+1, curr+1);
        }
    };

    f(f, 0, 0);
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
