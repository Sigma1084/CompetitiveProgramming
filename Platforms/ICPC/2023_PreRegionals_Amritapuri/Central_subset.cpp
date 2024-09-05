#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define all(x) (x).begin(), (x).end()

template<typename T> ostream &operator << (ostream &ost, const vector<T> &v) {
    if (&ost == &cerr) { cerr << "["; for(const auto &x: v) cerr << ' ' << x; cerr << " ]"; }
    else for (const auto &x: v) ost << x << ' '; return ost;
}

void solve() {
	int n, m; cin >> n >> m;
	vector<vector<int>> adj(n);

	for (int _ = 0, u, v; _ < m; _++) {
		cin >> u >> v; u--; v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	vector<int> d(n, -1);
	queue<int> q; q.push(0); d[0] = 0;
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (int v: adj[u]) {
			if (d[v] == -1) {
				d[v] = d[u] + 1;
				q.push(v);
			}
		}
	}

	int k = ceil(sqrt(double(n)));
	vector<vector<int>> classes(k + 1);
	for (int i = 0; i < n; i++)
		classes[d[i] % (k + 1)].push_back(i);

	for (int i = 0; i < k + 1; i++) {
		if (classes[i].empty() or classes[i].size() > k) continue;
		cout << classes[i].size() << '\n';
		for (int x: classes[i]) cout << x+1 << ' ';
		return;
	}

	cout << -1;
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
