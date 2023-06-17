#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
const int MOD = 1e9 + 7;

void solve() {
	int n, m, k; cin >> n >> m >> k;
	vector<int> a(m); for (auto &x: a) cin >> x;

	int extra = 0;	
	for (int &i: a) {
		if (i > n/k + 1) {
			cout << "NO";
			return;
		}
		if (i > n/k)
			extra++;
	}

	if (extra <= (n%k)) {
		cout << "YES";
	} else {
		cout << "NO";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int t = 1;
	cin >> t;

	for (int i=1; i<=t; i++) {
		// cout << "Case #" << i << ": ";
		solve(); cout << '\n';
	}
	return 0;
}

