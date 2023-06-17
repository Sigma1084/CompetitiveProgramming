#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;


void solve() {
	int n, m; cin >> n >> m;
	
	// m shud be n * 2^k / 3^l where k <= l
	int f2n = 0, f2m = 0, f3n = 0, f3m = 0;
	while (n % 2 == 0) f2n++, n /= 2;
	while (m % 2 == 0) f2m++, m /= 2;
	while (n % 3 == 0) f3n++, n /= 3;
	while (m % 3 == 0) f3m++, m /= 3;

	if (n != m or f2m - f2n > f3n - f3m) {
		cout << "NO";
	} else if (f2m - f2n < 0 or f3n - f3m < 0) {
		cout << "NO";
	} else {
		cout << "YES";
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

