#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
#define all(x) (x).begin(), (x).end()


void solve() {
	int x, y; cin >> x >> y;
	if (x > y) swap(x, y);  // ensure x <= y

	ll n;

	if (x == 1) {
		if (y == 1) n = 5;
		else n = y - 1;
	} else {
		if (x == 2 and y == 2) n = 2;
		else n = (ll) x*y - x - y;
	}

	cout << n << ' ';
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	int t = 1;
	cin >> t;

	for (int i = 1; i <= t; i++) {
		solve(); cout << '\n';
	}
	return 0;
}
