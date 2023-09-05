#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, k; cin >> n >> k;
	if (k % 3 == 0) {
		n %= (k + 1);
		if (n >= k) n--;
	}
	cout << ((n % 3) ? "Alice" : "Bob");
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
