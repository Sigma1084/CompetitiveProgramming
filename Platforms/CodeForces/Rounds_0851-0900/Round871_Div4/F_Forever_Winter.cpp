#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;


void solve() {
	int n, m; cin >> n >> m;
	vector<vector<int>> adj(n);
	for (int i = 0, u, v; i < m; i++) {
		cin >> u >> v; u--; v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	map<std::size_t, std::size_t> mp;
	for (int u = 0; u < n; u++) {
		mp[adj[u].size()]++;
	}

	vector<pair<std::size_t, std::size_t>> vp(mp.begin(), mp.end());

	if (vp.size() == 3) {
		// 3 different degrees
		if (vp[1].second == 1) {
			cout << vp[1].first << ' ' << vp[2].first - 1;
		} else {
			cout << vp[2].first << ' ' << vp[1].first - 1;
		}
	} else {
		// x = 1 OR x = y + 1
		if (vp[1].second == 1) {
			cout << 1 << ' ' << n - 2;
		} else {
			cout << vp[1].first << ' ' << vp[1].first - 1;
		}
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
