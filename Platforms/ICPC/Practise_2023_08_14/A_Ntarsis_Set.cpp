#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;


void solve() {
	string s; cin >> s;
	bitset<4000> bs(s);
	cout << bs.to_string() << '\n';
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
