#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MOD = 1e9 + 7;

void solve() {
    int n, nQ; cin >> n >> nQ;
    vector<int> a(n); for (auto &x: a) cin >> x;

    // vector<int> b;
    // int cur = a[0]; int f = 1;
    // for (int i = 1; i < n; i++) {
    //     if (a[i] == cur) f++;
    //     else {
    //         cur = a[i];
    //         b.push_back(f);
    //         f = 0;
    //     }
    // }
    // b.push_back(f);

    vector<int> vals(n + 1);

    /**
     * @brief edges[]
     */
    vector<vector<pair<int, int>>> e;

    ll ans = 0;
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

