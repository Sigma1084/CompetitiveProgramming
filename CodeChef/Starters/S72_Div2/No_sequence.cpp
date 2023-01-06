#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
#define all(x) (x).begin(), (x).end()


void solve() {
	int n, k; ll s; cin >> n >> k >> s;

	vector<int> ans(n);
	for (int i = 0; i < n and s; i++, s /= k) {
		if (s % k == 0) {
			continue;
		} else if (s % k == 1) {
			s -= 1;
			ans[i] = 1;
		} else if ((s+1) % k == 0) {
			s += 1;
			ans[i] = -1;
		} else {
			break;
		}
	}

	if (not s) {
		for (int &i: ans)
			cout << i << ' ';
	} else {
		cout << -2;
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
