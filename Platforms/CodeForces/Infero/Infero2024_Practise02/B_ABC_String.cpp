#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

bool isValid(string s) {
	int x = 0;
	for (char c: s) {
		if (c == '(') x++;
		else if (c == ')') x--;
		else assert(false);
		if (x < 0) return false;
	}
	return x == 0;
}

void solve() {
	string s; cin >> s;
	int n = s.size();
	
	for (int i = 0; i < 8; i++) {
		string t = s;
		for (int j = 0; j < 3; j++) {
			char rep = i & (1 << j) ? '(' : ')';
			for (char &c: t) if (c == 'A' + j) c = rep;
		}
		if (isValid(t)) {
			cout << "YES";
			return;
		}
	}
	cout << "NO";
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

