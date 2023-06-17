#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define all(x) (x).begin(), (x).end()


void solve() {
	int n, m; cin >> n >> m;
	set<int> s;
	for (int i = 0, x; i < n; i++) {
		cin >> x; s.insert(x);
	}
	s.insert(-1e9);
	s.insert(1e9);


	/**
	 * k shud be strictly in (b - root(4ac), b + root(4ac))
	 */
	for (int i = 0, a, b, c, k; i < m; i++) {
		cin >> a >> b >> c;
		if (c <= 0) {
			// Impossible
			cout << "NO\n";
		} else if ((k = *s.lower_bound(b)) < b + (int)ceil(sqrt(4LL * a * c))) {
			// First value geq b be less than the lim should be fine
			cout << "YES\n" << k << '\n';
		} else if ((k = *prev(s.lower_bound(b))) > b - sqrt(4LL * a * c)) {
			// First value lt b be greater than the lim should be fine
			cout << "YES\n" << k << '\n';
		} else {
			cout << "NO\n";
		}
	}
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
