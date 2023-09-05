#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	int n; cin >> n;
	vector<int> a(n);
	for (int &v: a) cin >> v;

	vector<vector<int>> e(n);
	for (int i = 0, u, v; i + 1 < n; i++) {
		cin >> u >> v;
		u--; v--;
		e[u].push_back(v);
		e[v].push_back(u);
	}

	vector<int> divs, cnt, ans(n);
	for (int i = 1; i <= a[0]; i++) {
		if (a[0] % i) continue;
		divs.push_back(i);
	}
	cnt.resize(divs.size());

	function<void(int, int, int)> dfs = [&](int u, int p, int g) {
		ans[u] = g;
		for (int i = 0; i < int(divs.size()); i++) {
			int d = divs[i];
			if (a[u] % d != 0) {
				cnt[i]++;
			}
			if (cnt[i] <= 1) {
				ans[u] = max(ans[u], d);
			}
		}

		for (int v: e[u]) {
			if (v == p) continue;
			dfs(v, u, gcd(a[v], g));
		}

		// Undo the changes
		for (int i = 0; i < int(divs.size()); i++) {
			int d = divs[i];
			if (a[u] % d != 0) {
				cnt[i]--;
			}
		}
	};

	dfs(0, -1, 0);
	for (int i = 0; i < n; i++) {
		cout << ans[i] << ' ';
	}

	return 0;
}
