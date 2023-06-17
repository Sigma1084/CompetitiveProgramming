#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;


void solve() {
	int a, b; cin >> a >> b;
	if (a > b) swap(a, b);
	// a <= b ensured

	if (b >= 2 * a) {
		cout << a;
		return;
	}

	/**
	 * When we make them equal, we will always end up with 1, 1 or 2, 2 
	 * in which case we do 1, 1 or 1, 0 from which we can't proceed
	 */

	// Since those are the only cases, the answer is just max_possible
	cout << (a + b) / 3;
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
