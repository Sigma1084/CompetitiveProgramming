#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;


void solve() {
	int h, m; cin >> h >> m;
	if (h == 0 and m == 0) cout << 0;
	else cout << (23 - h) * 60 + (60 - m);
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
