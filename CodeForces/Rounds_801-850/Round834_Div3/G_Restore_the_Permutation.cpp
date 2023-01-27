#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
#define all(x) (x).begin(), (x).end()
const int P = 1e9 + 7;

void solve() {
	int n, x; cin >> n;
	vector<int> a(n + 1);
	vector<bool> isGiven(n + 1, false);
	set<int> toFill;
	bool ok = true;

	for (int i = 2; i <= n; i += 2) {
		cin >> x;
		if (isGiven[x]) ok = false;
		isGiven[x] = true;
		a[i] = x;
	}

	if (not ok) {
		cout << -1;
		return;
	}

	for (int i = 1; i <= n; i++)
		if (not isGiven[i])
			toFill.insert(i);

	/**
	 * Now we have n elements in the array and want to fill n more elements
	 * Greedy approach from behind
	 * Insert the greatest element that can be inserted from the end
	 */

	for (int i = n; i > 0; i -= 2) {
		auto x = toFill.upper_bound(a[i]);
		if (x == toFill.begin()) {
			// No element smaller than the current exists
			cout << -1; return;
		}
		x--;
		a[i-1] = *x;
		toFill.erase(x);
	}

	for (int i = 1; i <= n; i++)
		cout << a[i] << ' ';
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

