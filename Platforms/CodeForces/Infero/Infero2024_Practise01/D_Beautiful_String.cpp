#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;


void solve() {
	string s; cin >> s;
	int n = s.size();

	for (int i = 0; i < n; i++) {
		set<char> surr;
		if (i - 1 >= 0) {
			surr.insert(s[i - 1]);
		}
		if (i + 1 < n) {
			surr.insert(s[i + 1]);
		}
		if (s[i] != '?' and surr.count(s[i])) {
			cout << -1;
			return;
		}
		if (s[i] != '?') continue;

		if (not surr.count('a')) {
			s[i] = 'a';
		} else if (not surr.count('b')) {
			s[i] = 'b';
		} else if (not surr.count('c')) {
			s[i] = 'c';
		} else {
			cout << -1;
			return;
		}
	}

	cout << s;
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
