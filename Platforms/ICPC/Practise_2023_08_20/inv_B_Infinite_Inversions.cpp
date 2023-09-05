#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	int nQ; cin >> nQ;
	map<int, int> m;
	for (int i = 0, x, y; i < nQ; i++) {
		cin >> x >> y;
		if (m.find(x) == m.end()) m[x] = x;
		if (m.find(y) == m.end()) m[y] = y;
		swap(m[x], m[y]);
	}

	vector<int> a;
	for (auto [pos, val]: m) {
		a.push_back(val);
	}

	function<ll(int, int)> numInv = [&] (int l, int r) -> ll {
		if (l == r) return 0;
		int m = (l + r) / 2;
		ll ans = numInv(l, m) + numInv(m + 1, r);

		cerr << l << ' ' << r << ' ' << ans << "\n";

		// Count inversions in that now
		for (int i = l; i <= m; i++) {
			ans += lower_bound(m + 1 + a.begin(), a.begin() + r + 1, a[i])
					- a.begin() - (m + 1);
		}
		for (int j = m + 1; j <= r; j++) {
			ans += lower_bound(l + a.begin(), a.begin() + m + 1, a[j])
					- a.begin() - l;
		}

		// Merge [l, r]
		vector<int> b(a.begin() + l, a.begin() + m + 1);
		vector<int> c(a.begin() + m + 1, a.begin() + r + 1);
		for (int i = 0, j = 0, k = l; i < b.size() or j < c.size(); k++) {
			if (i == b.size()) a[k] = c[j++];
			else if (j == c.size()) a[k] = b[i++];
			else if (b[i] < c[j]) a[k] = b[i++];
			else a[k] = c[j++];
		}

		cerr << l << ' ' << r << ' ' << ans << "\n";
		return ans;
	};

	cout << numInv(0, a.size() - 1);

	return 0;
}
