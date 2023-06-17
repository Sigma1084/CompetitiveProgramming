#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MOD = 1e9 + 7;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    vector<int> a(n); for (auto &x: a) cin >> x;

    vector<vector<int>> X;
    X.push_back({0});

    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            X.back().push_back(a[i]);
        } else {
            X.push_back({a[i]});
        }
    }

    ll ans = 0;
    for (auto &x: X) {
        ans += accumulate(x.begin(), x.end(), 0LL);
        ans -= *min_element(x.begin(), x.end());
    }

    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int t = 1;
    cin >> t;

    for (int i=1; i<=t; i++) {
        // cout << "Case #" << i << ": ";
        solve(); cout << '\n';
    }
    return 0;
}

