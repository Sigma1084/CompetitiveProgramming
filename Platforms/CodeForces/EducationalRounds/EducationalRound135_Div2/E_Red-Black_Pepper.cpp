#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MOD = 1e9 + 7;

void solve() {
    int n; cin >> n;
    
    vector<pair<int, int>> a;
    vector<int> f(n + 1);

    for (auto &[r, b]: a) {
        cin >> r >> b; f[0] += b;
    }

    sort(a.begin(), a.end(), [](auto &x, auto &y) {
        return x.first - x.second < y.first - y.second;
    });

    for (int i = 1; i <= n; i++) {
        f[i] = f[i-1] - a[i-1].second + a[i-1].first;
    }

    int m; cin >> m;
    int x, y; cin >> x >> y;


}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int t = 1;
    // cin >> t;

    for (int i=1; i<=t; i++) {
        // cout << "Case #" << i << ": ";
        solve(); cout << '\n';
    }
    return 0;
}

