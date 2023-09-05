#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;


void solve() {
	string s; cin >> s;

	int l = s.find('1'), r = s.rfind('1');
	if (l == s.npos) {
		cout << 0;
	} else {
		cout << count(s.begin() + l, s.begin() + r, '0');
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
