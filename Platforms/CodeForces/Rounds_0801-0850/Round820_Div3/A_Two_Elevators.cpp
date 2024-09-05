#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MOD = 1e9 + 7;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;

    int ta = a, tb = abs(b - c) + c;

    if (ta == tb) {
        cout << 3;
    } else if (ta < tb) {
        cout << 1;
    } else {
        cout << 2;
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

