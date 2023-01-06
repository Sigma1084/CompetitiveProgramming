#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MOD = 1e9 + 7;

void solve() {
    ll l, r, x, a, b;
    cin >> l >> r >> x >> a >> b;

    if (a > b) swap(a, b);

    if (a == b) {
        cout << 0;
    } else if (b-a >= x) {
        // One Step Win
        cout << 1;
    } else if (a-l >= x or r-b >= x) {
        // There is space to the left of a OR right of b
        cout << 2;
    } else if (r-a < x or b-l < x) {
        // a can't go right OR b can't be reached from left
        cout << -1;
    } else {
        cout << 3;
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

