#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n); for (auto &i: a) cin >> i;

    auto x = a.begin();
    while (next(x) != a.end() and *next(x) >= *x) x++;
    while (next(x) != a.end() and *next(x) <= *x) x++;

    if (next(x) == a.end()) {
        cout << "YES";
    } else {
        cout << "NO";
    }
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
