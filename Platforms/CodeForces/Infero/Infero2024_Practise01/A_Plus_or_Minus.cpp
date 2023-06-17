#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;


void solve() {
	int a, b, c; cin >> a >> b >> c;
	if (a + b == c) {
		cout << '+';
	} else if (a - b == c) {
		cout << '-';
	} else {
		cout << "F";
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
