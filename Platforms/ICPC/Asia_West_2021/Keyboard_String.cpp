#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;


void solve() {
	int n, m; cin >> n;
	string s; cin >> s;
	cin >> m;

	map<char, char> mp;
	for (int i = 0; i < m; i++) {
		char b, c; cin >> b >> c;
		mp[b] = c;
	}
	s += '0';

	for (int i = 0; i < n; i++) {
		if (mp.find(s[i]) != mp.end() and mp.at(s[i]) != s[i+1]) {
			cout << "NO";
			return;
		}
	}

	cout << "YES";
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
