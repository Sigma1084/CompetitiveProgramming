#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;


void solve() {
	int a, b, c;
	cin >> a >> b >> c;

	int p1 = (c + 1) / 2 + a;
	int p2 = c / 2 + b;

	if (p1 <= p2) {
		cout << "Second";
	} else {
		cout << "First";
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
