#include <bits/stdc++.h>
using namespace std;

void solve() {
    int nT, nC, temp; cin >> nT >> nC;
    multiset<int> t; for (int i=0; i<nT; i++) cin >> temp, t.insert(temp);

    for (int i=0; i<nC; i++) {
        cin >> temp;
        auto it = t.upper_bound(temp);
        if (it == t.begin()) cout << -1;
        else --it, cout << *it, t.erase(it);
        cout << '\n';
    }
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
