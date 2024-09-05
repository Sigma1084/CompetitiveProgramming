#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    array<int, 3> a;
    for (auto &x: a) cin >> x;

    sort(a.begin(), a.end());

    if (a[2] % a[0] == 0 and a[1] % a[0] == 0 and
            accumulate(a.begin(), a.end(), 0LL) / a[0] <= 6) {
        cout << "YES";
    } else {
        cout << "NO";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    while (t--) {
        solve();
        cout << '\n';
    }

    return 0;
}
