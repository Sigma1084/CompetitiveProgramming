#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;


void solve() {
	int n; cin >> n;
	vector<int> p(n);
	vector<vector<int>> ch(n);

	for (int i = 1, x; i < n; i++) {
		cin >> x;
		p[i] = x - 1;
		ch[p[i]].push_back(i);
	}

	string col; cin >> col;

	vector<int> w(n), b(n);
	function<void(int)> dfs = [&] (int u) {
		if (col[u] == 'W') w[u]++;
		else b[u]++;
		for (int v: ch[u]) {
			dfs(v);
			w[u] += w[v];
			b[u] += b[v];
		}
	};
	dfs(0);

	int ans = 0;
	for (int u = 0; u < n; u++) {
		if (w[u] == b[u]) ans++;
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
