#include <bits/stdc++.h>
using namespace std;
constexpr int INF = 1e8 + 7;

void solve() {
	int n; cin >> n;

	int fMin = INF, sMin = INF, bMin = INF;
	for (int i = 0; i < n; i++) {
		int t; cin >> t;
		string s; cin >> s;
		if (s[0] == '1') fMin = min(fMin, t);
		if (s[1] == '1') sMin = min(sMin, t);
		if (s == "11") bMin = min(bMin, t);
	}

	int ans = min(fMin + sMin, bMin);
	if (ans >= INF) ans = -1;
	cout << ans;
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
