#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define all(x) (x).begin(), (x).end()


void solve() {
	int n, m; cin >> n >> m;
	vector<vector<int>> adj(n);

	int u, v, profit, odds = 0;
	for (int i = 0; i < m; i++) {
		cin >> u >> v; u--; v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	vector<int> d(n, -1);
	queue<int> q; q.push(0);
	
	while (not q.empty()) {
		int u = q.front(); q.pop();
		for (int v: adj[u]) {
			if (d[v] != -1) continue;
			d[v] = d[u] + 1;
			if (d[v] % 2 == 1) odds++;
			q.push(v);
		}
	}

	if (odds > n / 2) {
		cout << n - odds << '\n';
		for (int i = 0; i < n; i++) {
			if (d[i] % 2 == 0) cout << i + 1 << ' ';
		}
	} else {
		cout << odds << '\n';
		for (int i = 0; i < n; i++) {
			if (d[i] % 2 == 1) cout << i + 1 << ' ';
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
