#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

/**
 * Suppose we have a l, a, b, r
 * The range [b, r] is useless.
 * 
 * If we are currently in [l, b] => Transport to b
 * We merge ranges interlapping and consider essential [s, e]
 * 
 * All the x in [s, e] must end up in e
 */
void solve() {
	int n; cin >> n;
	vector<array<int, 2>> se(2*n);
	for (int i = 0, l, r, a, b; i < n; i++) {
		cin >> l >> r >> a >> b;
		se[2*i] = {l, 1};
		se[2*i + 1] = {b, -1};
	}

	// Sort [start/end, 1/-1] ASC, DESC
	sort(se.begin(), se.end(), [](auto a, auto b) {
		if (a[0] == b[0]) return a[1] > b[1];
		return a[0] < b[0];
	});

	int nQ; cin >> nQ;
	vector<int> ans(nQ);  // To be printed in the end
	vector<array<int, 2>> q(nQ);
	for (int i = 0; i < nQ; i++) {
		cin >> ans[i];
		q[i][0] = ans[i];
		q[i][1] = i;
	}
	sort(q.begin(), q.end());

	// Solution
	int i = 0, s = -1, e = -1, cur = 0;

	auto update = [&]() {
		// Assumes start and end are updated
		for (; i < nQ and q[i][0] <= e; i++) {
			if (q[i][0] >= s) {
				ans[q[i][1]] = e;
			}
		}
	};

	// Processing the sorted starting / ending points
	for (auto [x, d]: se) {
		if (cur == 0) {
			assert(d == 1);  // It has to start
			s = x;
		}
		cur += d;
		if (cur == 0) {
			assert(d == -1);
			e = x;  // It ends here
			update();
		}
	}

	for (int x: ans) {
		cout << x << ' ';
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
