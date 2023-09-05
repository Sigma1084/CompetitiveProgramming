#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;


void solve() {
	ll n, m, d; cin >> n >> m >> d;
	vector<ll> s(m + 2);  // Seller

	for (int i = 1; i <= m; i++) {
		cin >> s[i];
	}

	s.front() = - d + 1;  // 1 is always present
	s.back() = n + 1;

	auto contr = [&] (int i, int j = -1) {
		if (j == -1) j = i - 1;
		return 1 + (s[i] - s[j] - 1) / d;
	};

	ll cur = -1;  // Accounting for the last contr
	for (int i = 1; i <= m + 1; i++) {
		cur += contr(i);
	}

	ll ans = cur, ind = 0;

	// What happens if s[i] is removed
	for (int i = 1; i <= m; i++) {
		ll diff = contr(i + 1, i - 1) - contr(i + 1) - contr(i);
		if (diff < 0) {
			ans = cur + diff;
			ind++;
		}
	}

	if (cur == ans) {
		cout << cur << ' ' << m;
	} else {
		cout << ans << ' ' << ind;
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
