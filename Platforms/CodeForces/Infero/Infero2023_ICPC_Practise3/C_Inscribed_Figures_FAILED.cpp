#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define all(x) (x).begin(), (x).end()


void solve() {
	int n; cin >> n;
	vector<int> a(n); for (auto &x: a) cin >> x;

	for (int i = 0; i < n; i++) {
		if (a[i] == 1) {
			a[i] = 0;
		} else if (a[i] == 2) {
			a[i] = 3;
		} else if (a[i] == 3) {
			a[i] = 4;
		}
	}

	for (int i = 1; i < n; i++) {
		if (a[i] != 0 and a[i-1] != 0) {
			// A square and a triangle overlap
			cout << "Infinite";
			return;
		}
	}

	bool prevTri = false;
	int ans = 0, sides;


	for (int i = 1; i < n; i++) {
		if (a[i] == 0) {
			ans += a[i-1];
			prevTri = (a[i-1] == 3);
		} else if (a[i] == 3) {
			ans += 3;
			prevTri = true;
		} else if (a[i] == 4) {
			ans += 4;
			if (prevTri) ans += 1;
			prevTri = false;
		} else {
			assert(false);
		}
	}

	cout << "Finite\n" << ans;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	int t = 1;
	// cin >> t;

	for (int i = 1; i <= t; i++) {
		solve(); cout << '\n';
	}
	return 0;
}
