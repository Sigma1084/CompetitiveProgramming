#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;


void solve() {
	string s; cin >> s;
	int n = s.size();
	int bef = s[n - 1];
	for (int i = n - 2; i >= 0; i--) {
		if (s[i] > bef) {
			if (s[i] != '9') s[i] += 1;
		} else {
			bef = s[i];
		}
	}
	sort(s.begin(), s.end());
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
