#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
const int MOD = 1e9 + 7;

void solve() {
	int n; cin >> n;
	string s; cin >> s;

	int ones = (s[0] == '1');
	stringstream ss;
	for (int i = 1; i < n; i++) {
		if (s[i] == '0') ss << '+';
		else {
			if (ones%2 == 0) {
				ss << '+';
			} else {
				ss << '-';
			}
			ones++;
		}
	}

	ss >> s;
	cout << s;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int t = 1;
	cin >> t;

	for (int i=1; i<=t; i++) {
		// cout << "Case #" << i << ": ";
		solve(); cout << '\n';
	}
	return 0;
}

