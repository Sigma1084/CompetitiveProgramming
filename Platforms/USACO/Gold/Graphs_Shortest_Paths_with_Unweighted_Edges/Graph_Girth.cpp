#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;


int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	int n, m; cin >> n >> m;
	vector<vector<int>> graph(n);

	for (int i = 0, u, v; i < m; i++) {
		cin >> u >> v; u--; v--;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	int ans = 1e6;

	vector<int> d;
	queue<int> q;

	for (int i = 0; i < n; i++) {
		d.clear();
		d.resize(n, -1); d[i] = 0;
		q.push(i);
		while (not q.empty()) {
			int u = q.front(); q.pop();
			for (int v: graph[u]) {
				if (d[v] == -1) {
					d[v] = d[u] + 1;
					q.push(v);
				} else if (d[v] >= d[u]) {
					ans = min(ans, 1 + d[u] + d[v]);
				}
			}
		}
	}

	if (ans == 1e6)
		ans = -1;

	cout << ans;

	return 0;
}
