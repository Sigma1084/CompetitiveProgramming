#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
#define all(x) (x).begin(), (x).end()


void solve() {
	int n; cin >> n;
	string s; cin >> s;

	int r = n, l = -1;
	for (int i = n-1; i >= 0; i--) {
		if (s[i] == 'R')
			r = i;
	}
	for (int i = 0; i < n; i++) {
		if (s[i] == 'L')
			l = i;
	}

	if (r == n or l == -1) {
		cout << -1;
	} else if (l < r) {
		cout << r;
	} else {
		cout << 0;
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
