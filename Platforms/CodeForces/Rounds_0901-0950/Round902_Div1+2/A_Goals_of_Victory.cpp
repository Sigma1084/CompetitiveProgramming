#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;

    vector<int> a(n - 1);
    for (int &x: a) {
        cin >> x;
    }

    cout << -accumulate(a.begin(), a.end(), 0LL);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    for (int i = 1; i <= t; ++i) {
        solve();
        cout << '\n';
    }

    return 0;
}

