#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, k; cin >> n >> m >> k;
    vector<int> a(n); for (auto &x: a) cin >> x;
    sort(a.begin(), a.end());
    vector<int> b(m); for (auto &x: b) cin >> x;
    sort(b.begin(), b.end());

    int ans = 0;
    auto apl = a.begin(), apt = b.begin();
    while (apl != a.end() and apt != b.end()) {
        if (*apl > *apt + k) apt++;
        else if(*apl < *apt - k) apl++;
        else { ans++, apl++, apt++; }
    }

    cout << ans;
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
