#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;


void solve() {
	array<string, 3> b;
	for (string &s: b) cin >> s;
	array<char, 3> chars = {'+', 'O', 'X'};

	for (char c: chars) {
		for (int i = 0; i < 3; i++) {
			bool ok = true;
			for (int j = 0; j < 3; j++) {
				if (b[i][j] != c)
					ok = false;
			}
			if (ok) {
				cout << c;
				return;
			}
		}
		for (int j = 0; j < 3; j++) {
			bool ok = true;
			for (int i = 0; i < 3; i++) {
				if (b[i][j] != c)
					ok = false;
			}
			if (ok) {
				cout << c;
				return;
			}
		}
		if (b[0][0] == c and b[1][1] == c and b[2][2] == c) {
			cout << c;
			return;
		} else if (b[0][2] == c and b[1][1] == c and b[2][0] == c) {
			cout << c;
			return;
		}
	}
	cout << "DRAW";
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
