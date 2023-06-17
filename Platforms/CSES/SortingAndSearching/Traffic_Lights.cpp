#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MOD = 1e9 + 7;

void solve() {
    int x, n, in; cin >> x >> n;

    set<int> lights = {0, x};
    multiset<int> d = {x};

    int l, u;

    for (int _ = 0; _ < n; _++) {
        cin >> in;
        auto lb = lights.lower_bound(in);
        if (*lb != in) {
            u = *lb, l = *prev(lb);
            d.erase(d.find(u-l));
            d.insert(u - in); d.insert(in - l);
            lights.insert(in);
        }
        cout << *d.rbegin() << ' ';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int t = 1;
    // cin >> t;

    for (int i=1; i<=t; i++) {
        solve();
        cout << '\n';
    }	
}
