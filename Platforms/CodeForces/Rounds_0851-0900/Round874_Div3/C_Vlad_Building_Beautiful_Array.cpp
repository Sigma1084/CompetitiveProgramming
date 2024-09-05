#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;


void solve() {
	int n; cin >> n;
	vector<int> a(n); for (auto &x: a) cin >> x;
	sort(a.begin(), a.end());

	// If the first thing is odd, then done
	if (a.front() & 1) {
		cout << "YES";
		return;
	}

	// If there is an odd, it has to be in the beginning
	bool ok = true;
	for (int i: a) if (i & 1) ok = false;

	if (ok) {
		cout << "YES";
	} else {
		cout << "NO";
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
