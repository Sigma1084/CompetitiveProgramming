#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define all(x) (x).begin(), (x).end()


int query(int x, int y) {
	cout << "? " << x << " " << y << endl;
	cin >> x; return x;
}


void solve() {
	int n, m; cin >> n >> m;
	int r, c;

	int a, b;
	a = query(1, 1);
	// The row and column compete to be a + 1

	if (a + 1 > m) {
		// Columns cant compete anymore => Row must be a + 1
		r = a + 1;
		c = query(a + 1, 1) + 1;
	} else if (a + 1 > n) {
		// Rows cant compete anymore => Column must be a + 1
		c = a + 1;
		r = query(1, a + 1) + 1;
	} else {
		// Can be anyone's game
		if ((b = query(1, a + 1)) < a) {
			// Distance after finishing columns is lesser => Column must be a + 1
			c = a + 1;
			r = b + 1;
		} else if ((b = query(a + 1, 1)) < a) {
			// Distance after finishing rows is lesser => Row must be a + 1
			r = a + 1;
			c = b + 1;
		} else {
			r = a + 1;
			c = a + 1;
		}
	}

	cout << "! " << r << ' ' << c << endl;
}


int main() {
	int t = 1;
	cin >> t;

	for (int i = 1; i <= t; i++) {
		solve();
	}

	return 0;
}
