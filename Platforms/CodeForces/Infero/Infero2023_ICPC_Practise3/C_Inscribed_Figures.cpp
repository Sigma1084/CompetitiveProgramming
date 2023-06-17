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
		if ((a[i] != 0 and a[i-1] != 0) or a[i] == a[i-1]) {
			// A square and a triangle overlap
			cout << "Infinite";
			return;
		}
	}

	bool prevSq = (a[0] == 4);
	int ans = 0, sides;

	for (int i = 1; i < n; i++) {
		if (a[i] == 0) {
			ans += a[i-1];
			prevSq = (a[i-1] == 4);
		} else if (a[i] == 3) {
			ans += 3;
			if (prevSq) ans--;
			prevSq = false;
		} else if (a[i] == 4) {
			ans += 4;
			prevSq = true;
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
