#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define all(x) (x).begin(), (x).end()


void solve() {
	string s; cin >> s;
	stack<char> t;
	for (const char &c: s) {
		if (c == 'A' or t.empty()) {
			t.push(c);
		}  else {
			t.pop();
		}
	}
	cout << t.size();
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
