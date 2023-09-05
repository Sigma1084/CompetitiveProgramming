#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

void solve() {
	int s, k; cin >> s >> k;
	ll  ans = 0;

	while (k and s % 2) {
		ans = max(ans, 1LL * s * k);
		s += s % 10;
		k--;
	}

	if (k == 0 or s % 10 == 0) {
		ans = max(ans, 1LL * s * k);
		cout << ans;
		return;
	}

	/**
	 * s ends with 2, 4, 6, 8
	 * 2 -> 4 -> 8 -> 16 -> 22
	 * f(i) = (s + 20i)(k - 4i)  ;  0 <= 4i <= k
	 * f'(i) = -4(s + 20i) + 20(k - 4i)
	 * f'(i) = -4s - 80i + 20k - 80i = (-4s + 20k - 160i)
	 * 160i = 20k - 4s
	 * i = (20k - 4s) / 160
	 */

	auto f = [&] (int i) -> ll {
		if (0 <= 4 * i and 4 * i <= k)
			return 1LL * (s + 20 * i) * (k - 4 * i);
		else
			return 0;
	};

	for (int _ = 0, i; _ < 4 and k; _++, k--) {
		ans = max(ans, f(0));  // i = 0
		ans = max(ans, f(k / 4));  // max i
		i = (20 * k - 4 * s) / 160;  // floor
		ans = max(ans, f(i));
		i = (20 * k - 4 * s + 160 - 1) / 160;
		ans = max(ans, f(i));
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
