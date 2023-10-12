#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;

    if (n <= 6 or n == 9) {
        cout << "NO";
    } else if (n % 3 == 0) {
        cout << "YES\n1 4 " << n - 5;
    } else {
        cout << "YES\n1 2 " << n - 3;
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
