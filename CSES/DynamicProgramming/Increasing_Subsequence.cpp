#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n); for (auto &i: a) cin >> i;

    vector<int> dec; dec.push_back(a[0]);
    for (auto &i: a) {
        if (i > dec.back()) dec.push_back(i);
        else *lower_bound(dec.begin(), dec.end(), i) = i;
    }

    cout << dec.size();
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
