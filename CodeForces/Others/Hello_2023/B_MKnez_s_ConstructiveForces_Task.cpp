#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
#define all(x) (x).begin(), (x).end()


void solve() {
	int n; cin >> n;

	if (n == 3) {
		cout << "NO";
		return;
	}

	cout << "YES\n";
	if (n % 2 == 0) {
		for (int i = 0, j = 0; i < n; i++, j = 1 - j)
			cout << (j ? 1 : -1) << ' ';
	} else {
		/**
		 * n = 5
		 * a + b + c + d + e
		 * c + d + e = 0
		 * a + d + e = 0
		 * a = c = e
		 * a + b + e = 0
		 * a + d + e = 0
		 * d = e
		 * 
		 * a + b = 2*a + b => a = 0
		 * 
		 * a b a b a
		 * a + b = 3*a + 2*b
		 * 2*a + b = 0
		 * b = -2*a
		 * 
		 * 1 -2 1 -2 1 GG
		 * 
		 * 2k + 1
		 * (k+1)a + kb = a + b
		 * ka + (k-1) b = 0
		 * a = k-1 b = -k
		 */
		int k = n / 2;
		for (int i = 1; i <= n; i++) {
			if (i % 2 == 1) cout << k-1;
			else cout << -k;
			cout << ' ';
		}
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
