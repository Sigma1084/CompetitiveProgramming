#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
#define all(x) (x).begin(), (x).end()

constexpr int A = 1 << 21;

void solve() {
	int n; cin >> n;
	vector<int> a(n); for (auto &x: a) cin >> x;

	function<bool(int)> check = [&n, &a] (int x) -> bool {
		int maxPos = 0;
		for (int i = 0; i <= maxPos and maxPos < n; i++) {
			if ((a[i] | x) == x)
				maxPos = max(maxPos, i + a[i]);
		}
		return maxPos >= n-1 and (a[n-1] | x) == x;
	};

	int ans = 1;
	int bit = 1;

	while (!check(ans) and ans < A) {
		bit <<= 1;
		ans |= bit;
	}

	if (ans >= A) {
		cout << -1;
		return;
	}

	bit >>= 1;
	while (bit) {
		if (check(ans ^ bit))
			ans ^= bit;
		bit >>= 1;
	}

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
