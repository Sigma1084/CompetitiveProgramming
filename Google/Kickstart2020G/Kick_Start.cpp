#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
#define all(x) (x).begin(), (x).end()


void solve() {
	string s; cin >> s;
	int n = s.size();

	int kicks = 0;
	ll ans = 0;

	for (int i = 0; i + 4 < n; i++) {
		if (s.substr(i, 4) == "KICK") {
			kicks += 1;
		} else if (s.substr(i, 5) == "START") {
			ans += kicks;
		}
	}

	cout << ans;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	int t = 1;
	cin >> t;

	for (int i = 1; i <= t; i++) {
		cout << "Case #" << i << ":" << ' ';
		solve(); cout << '\n';
	}
	return 0;
}
