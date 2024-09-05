#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define all(x) (x).begin(), (x).end()


void solve() {
	int a, b; cin >> a >> b;
	if (a == 1 or b == 1) {
		cout << 1 << '\n' << a << ' ' << b;
	} else {
		cout << 2 << '\n';
		cout << a - 1 << ' ' << 1 << '\n';
		cout << a << ' ' << b;
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
