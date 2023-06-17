#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
#define all(x) (x).begin(), (x).end()


void solve() {
	int n; cin >> n;
	string s; cin >> s;

	int nOp;
	string t;
	pair<string, int> ans({s, 1});

	for (int k = 2; k <= n; k++) {
		nOp = (n - k + 1);
		t = s.substr(k - 1) + s.substr(0, k - 1);
		if (nOp & 1) {
			reverse(t.end() - k + 1, t.end());
		}
		ans = min(ans, {t, k});
	}

	cout << ans.first << '\n' << ans.second;
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
