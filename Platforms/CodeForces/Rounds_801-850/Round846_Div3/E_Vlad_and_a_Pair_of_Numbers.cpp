#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
#define all(x) (x).begin(), (x).end()


void solve() {
	int x; cin >> x;
	if (x % 2) {
		cout << -1;
		return;
	}
	int Plus = 2 * x;
	int And = x / 2;

	int b = And;
	int a = 3 * And;

	if ((a ^ b) == x) {
		cout << a << ' ' << b;
	} else {
		cout << -1;
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
