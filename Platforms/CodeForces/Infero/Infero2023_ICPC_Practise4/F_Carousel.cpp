#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define all(x) (x).begin(), (x).end()


void solve() {
	int n; cin >> n;
	vector<int> a(n); for (auto &x: a) cin >> x;

	bool allEq = true;
	for (int i = 1; i < n; i++) {
		if (a[i] != a[i-1]) {
			allEq = false;
			break;
		}
	}

	if (allEq) {
		cout << 1 << '\n';
		for (int i = 0; i < n; i++)
			cout << 1 << ' ';
		return;
	}

	if (n % 2 == 0 or a[0] == a[n-1]) {
		cout << 2 << '\n';
		for (int i = 0; i < n; i++)
			cout << (i % 2) + 1 << ' ';
		return;
	}

	// Now n is odd
	int bothEq = 0;
	for (int i = 1; i < n; i++) {
		if (a[i] == a[i-1]) {
			bothEq = i;
			break;
		}
	}

	if (bothEq) {
		cout << 2 << '\n';
		for (int i = 0, j = 0; i < n; i++) {
			if (i != bothEq)
				j ^= 1;
			cout << j + 1 << ' ';
		}
		return;
	}

	cout << 3 << '\n';
	for (int i = 0; i < n-1; i++)
		cout << (i % 2) + 1 << ' ';
	cout << 3;
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
