#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define all(x) (x).begin(), (x).end()

void solve() {
	int n, m, k; cin >> n >> m >> k;
	vector<bool> isSpecial(n, false);
	for (int i = 0, x; i < k; i++) {
		cin >> x; isSpecial[x - 1] = true;
	}
	vector<vector<int>> adj(n);

	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v; u--; v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	auto bfs = [&] (int start) {
		queue<int> q;
		q.push(start);
		vector<int> d(n, -1);

		d[start] = 0;
		while (not q.empty()) {
			int u = q.front(); q.pop();
			for (int v: adj[u]) {
				if (d[v] == -1) {
					d[v] = d[u] + 1;
					q.push(v);
				}
			}
		}

		return d;
	};

	vector<int> d1 = bfs(0), d2 = bfs(n-1);

	// for (int i = 0; i < n; i++) {
	// 	cerr << d1[i] << ' ';
	// }
	// cerr << '\n';

	// for (int i = 0; i < n; i++) {
	// 	cerr << d2[i] << ' ';
	// }
	// cerr << '\n';

	/**
	 * We need to find
	 * max_{a, b are special} min(d1[a] + d2[b], d1[b] + d2[a])
	 * Now, we can sort the special nodes by d1 - d2
	 * 
	 * Without loss of generality, assume d1[a] - d2[a] <= d1[b] - d2[b]
	 * implies d1[a] + d2[b] <= d1[b] + d2[a] when a < b
	 * 
	 * max_{a < b} d1[a] + d2[b]
	 * 
	 * We store and update maxD1[a] and iterate over b
	 */

	vector<pair<int, int>> d1MinusD2(k);
	for (int i = 0, j = 0; i < n; i++) {
		if (isSpecial[i]) {
			d1MinusD2[j++] = { d1[i] - d2[i], i };
		}
	}
	sort(all(d1MinusD2));

	int maxD1 = -INT_MAX, ans = 0;
	for (auto [_, b]: d1MinusD2) {
		ans = max(ans, maxD1 + d2[b] + 1);
		maxD1 = max(maxD1, d1[b]);
	}

	cout << min(ans, d2[0]);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	int t = 1;
	// cin >> t;

	for (int i = 1; i <= t; i++) {
		solve(); cout << '\n';
	}
	return 0;
}
