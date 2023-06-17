#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
#define all(x) (x).begin(), (x).end()


void solve() {
	int n, m; cin >> n >> m;
	vector<vector<array<int, 2>>> edges(n);
	vector<vector<array<int, 2>>> revEdges(n);
	// edges[u] = {{w, v}, ...} where w is the weight
	
	for (int i = 0; i < m; i++) {
		int u, v, w; cin >> u >> v >> w;
		u--; v--;
		edges[u].push_back({w, v});
		revEdges[v].push_back({w, u});
	}

	function<bool(int)> check = [&] (int x) {
		vector<bool> vis(n, false);
		function<void(int)> dfs = [&] (int u) {
			vis[u] = true;
			for (const auto &[w, v]: edges[u]) {
				if (!vis[v]) dfs(v);
			}
			for (const auto &[w, v]: revEdges[u]) {
				if (!vis[v] and w <= x) dfs(v);
			}
		};
		dfs(0);
		return (accumulate(all(vis), 0) == n);
	};

	int l = 0, r = 1e9 + 1;
	while (l < r) {
		int mid = (l + r) / 2;
		if (check(mid)) r = mid;
		else l = mid + 1;
	}
	cout << int(check(1)) << ' ';

	if (l == 1e9 + 1) {
		cout << -1;
	} else {
		cout << l;
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
