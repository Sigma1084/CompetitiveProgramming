#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
const int MOD = 1e9 + 7;

void solve() {
	int n; cin >> n;
	string s; cin >> s;

	int o = 0; for (char &c: s) o += c - '0';
	int z = n - o;

	// 2^numOnes - 1 can't win
	for (int i = (1 << o); i <= (1 << n) - (1 << z) + 1; i++) {
		cout << i << ' ';
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int t = 1;
	// cin >> t;

	for (int i=1; i<=t; i++) {
		// cout << "Case #" << i << ": ";
		solve(); cout << '\n';
	}
	return 0;
}

