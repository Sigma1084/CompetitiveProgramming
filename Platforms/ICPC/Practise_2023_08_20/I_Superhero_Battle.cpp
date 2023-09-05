#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	ll H; cin >> H;
	int n; cin >> n;
	vector<int> a(n);
	for (int &x: a) cin >> x;

	vector<ll> p(n);
	p[0] = a[0];
	for (int i = 1; i < n; i++) {
		p[i] = p[i-1] + a[i];
	}

	ll mn = *min_element(p.begin(), p.end());
	ll tot = p.back();

	if (tot >= 0 and H + mn > 0) {
		cout << -1 << endl;
		return 0;
	}

	/**
	 * After 1 run, we will have H - tot
	 * H - t * tot + mn <= 0
	 * 
	 * Least t such that H + mn <= 0
	 * H + mn <= t * tot
	 * t >= (H + mn) / tot
	 * t >= a / b
	 * 2 >= 5 / 3
	 */

	ll t = 0, ans = 0;
	if (tot < 0 and H + mn > 0) {
		tot = -tot;
		t = (H + mn + tot - 1) / tot;
		ans = t * n;
		H -= t * tot;
	}

	assert(H + mn <= 0);
	for (int i = 0; i < n; i++) {
		if (H + p[i] <= 0) {
			ans += i + 1;
			break;
		}
	}

	cout << ans << endl;

	return 0;
}
