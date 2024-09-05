#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;


void solve() {
	int n; cin >> n;
	vector<int> p(n); for (auto &x: p) cin >> x;

	if (n == 1) {
		cout << 1;
		return;
	}

	// Always end to the left of the greatest number
	int end = 2;
	for (int i = 1; i < n; i++) {
		if (p[i] > p[end])
			end = i;
	}

	// Perform for every right and check
	vector<int> ans(n);

	if (end + 1 == n) {
		for (int start = 0; start <= end; start++) {
			vector<int> b(n);
			int j = 0;
			for (int i = end + 1; i < n; i++, j++) b[j] = p[i];
			for (int i = end; i >= start; i--, j++) b[j] = p[i];
			for (int i = 0; i < start; i++, j++) b[j] = p[i];
			ans = max(ans, b);
		}
	}

	end--;
	for (int start = 0; start <= end; start++) {
		vector<int> b(n);
		int j = 0;
		for (int i = end + 1; i < n; i++, j++) b[j] = p[i];
		for (int i = end; i >= start; i--, j++) b[j] = p[i];
		for (int i = 0; i < start; i++, j++) b[j] = p[i];
		ans = max(ans, b);
	}

	for (int i: ans) cout << i << ' ';
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
