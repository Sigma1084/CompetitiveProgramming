#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MOD = 1e9 + 7;

void solve() {
	int n, b; cin >> n >> b;
	vector<int> a(n); for (auto &x: a) cin >> x;

	bool tenReq = false;
	int u = a[n-1], t;

	if (n == 1) {
		t = 0;
	} else {
		int i;
		for (i = n-2; i >= 0 and a[i] == b-1; i--);
		t = (i < 0) ? 0 : a[i];
	}

	int maxToGo = b + u - 1;

	// We need to check if u-1, u-2 and so on can occur
	for (int i = 0; i+1 < n; i++) {
		if (a[i] < u) a[i] += b;
	}

	sort(a.begin(), a.end()-1, greater<int>());

	for (int i = 0; i+1 < n; i++) {
		if (maxToGo % b == a[i] % b)
			maxToGo--;
	}

	if (maxToGo % b == (t+1) % b and u != 0) {
		tenReq = true;
		maxToGo--;
		for (int i = 0; i+1 < n; i++) {
			if (maxToGo % b == a[i] % b)
				maxToGo--;
		}
		maxToGo = max(maxToGo, b);
	}

	cout << max(0, maxToGo - u);
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

