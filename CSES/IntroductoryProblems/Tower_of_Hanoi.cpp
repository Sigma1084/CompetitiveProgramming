#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MOD = 1e9 + 7;

int ops(int n) {
    if (n == 1) return 1;
    return 2*ops(n-1) + 1;
}

void recurse(int n, int a, int c, int b) {
    if (n == 1) { cout << a << ' ' << c << '\n'; return; }
    recurse(n-1, a, b, c);
    cout << a << ' ' << c << '\n';
    recurse(n-1, b, c, a);
}

void solve() {
    int n; cin >> n;
    cout << ops(n) << '\n';
    recurse(n, 1, 3, 2);
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

