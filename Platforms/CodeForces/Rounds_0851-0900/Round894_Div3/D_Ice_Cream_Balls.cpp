#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;


void solve() {
	ll c; cin >> c;

	ll n = sqrt(2 * c) + 1;
	while ((n - 1) * n / 2 > c) {
		n--;
	}
	// n * (n - 1) / 2 <= c
	n += c - n * (n - 1) / 2;

	cout << n;
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
