#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
#define all(x) (x).begin(), (x).end()
const int P = 1e9 + 7;

void solve() {
	int n; cin >> n;
	vector<int> a(n); for (auto &x: a) cin >> x;

	sort(a.begin(), a.end());
	vector<int> b(n);

	int i, j;  // i is the traverser for a
	bool ok;

	for (int s = 0; s < 2; s++) {
		for (i = 0, j = s; j < n; i++, j += 2) b[j] = a[i];
		for (j = 1^s; j < n; j += 2, i++) b[j] = a[i];

		ok = true;
		for (j = 1; j < n; j++) {
			if (b[j] == b[j-1]) ok = false;
		}

		if (ok or n == 2) {
			for (int &x: b) cout << x << ' ';
			return;
		}
	}

	cout << -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int t = 1;
	cin >> t;

	for (int i=1; i<=t; i++) {
		solve(); cout << '\n';
	}
	return 0;
}

