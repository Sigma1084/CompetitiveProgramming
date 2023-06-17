#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;


void solve() {
	int n; cin >> n;
	vector<int> a(n); for (auto &x: a) cin >> x;

	auto mod = [&n](int k) {
		return ((k % n) + n) % n;
	};

	vector<bool> occ(n, 0);
	for (int k = 0; k < n; k++) {
		occ[mod(k + a[k])] = true;
	}

	bool ok = accumulate(occ.begin(), occ.end(), 0) == n;
	cout << (ok ? "YES" : "NO");
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
