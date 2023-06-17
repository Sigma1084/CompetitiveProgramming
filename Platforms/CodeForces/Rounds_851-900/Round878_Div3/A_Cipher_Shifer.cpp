#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;


void solve() {
	int n; cin >> n;
	string s; cin >> s;
	string a;
	char c = 0;
	for (int i = 0; i < n; i++) {
		if (c == 0) {
			c = s[i];
			a.push_back(c);
		} else if (s[i] == c) {
			c = 0;
		}
	}
	cout << a;
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
